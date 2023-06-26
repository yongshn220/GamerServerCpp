#include "pch.h"
#include <iostream>
#include "Service.h"
#include "Session.h"
#include "ThreadManager.h"

#include "BufferReader.h"

char sendData[] = "Hello World";


class ServerSession : public PacketSession
{
public:
	~ServerSession()
	{
		cout << "~ServerSession" << endl;
	}

	virtual void OnConnected() override
 	{
		/*SendBufferRef sendBuffer = GSendBufferManager->Open(4096);
		::memcpy(sendBuffer->Buffer(), sendData, sizeof(sendData));
		sendBuffer->Close(sizeof(sendData));

		Send(sendBuffer);*/
	}

	virtual void OnDisconnected() override
	{
		//cout << "Disconnected" << endl;
	}
	
	virtual int32 OnRecvPacket(BYTE* buffer, int32 len) override
	{
		BufferReader br(buffer, len);

		PacketHeader header;
		br >> header;

		uint64 id;
		uint32 hp;
		uint16 attack;
		br >> id >> hp >> attack;

		cout << id << hp << attack << endl;
		return len;
	}

	virtual void OnSend(int32 len) override
	{
		//cout << "OnSend Len = " << len << endl;
	}
};
int main()
{
	this_thread::sleep_for(1s);

	ClientServiceRef service = MakeShared<ClientService>(
		NetAddress(L"127.0.0.1", 7777),
		MakeShared<IocpCore>(),
		MakeShared<ServerSession>,
		1000);

	ASSERT_CRASH(service->Start());

	for (int32 i = 0; i < 2; i++)
	{
		GThreadManager->Launch([=]()
			{
				while (true)
				{
					service->GetIocpCore()->Dispatch();
				}
			});
	}

	GThreadManager->Join();
}

