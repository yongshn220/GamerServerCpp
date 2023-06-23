#include "pch.h"
#include <iostream>
#include "Service.h"
#include "Session.h"
#include "ThreadManager.h"

char sendBuffer[] = "Hello World";


class ServerSession : public Session
{
public:
	virtual void OnConnected() override
	{
		Send((BYTE*)sendBuffer, sizeof(sendBuffer));
	}

	virtual void OnDisconnected() override
	{
		cout << "Disconnected" << endl;
	}
	
	virtual int32 OnRecv(BYTE* buffer, int32 len) override
	{
		cout << "On Recv Len = " << len << endl;

		this_thread::sleep_for(1s);

		Send((BYTE*)sendBuffer, sizeof(sendBuffer));

		return len;
	}

	virtual void OnSend(int32 len) override
	{
		cout << "OnSend Len = " << len << endl;
	}
};
int main()
{
	this_thread::sleep_for(1s);

	ClientServiceRef service = MakeShared<ClientService>(
		NetAddress(L"127.0.0.1", 7777),
		MakeShared<IocpCore>(),
		MakeShared<ServerSession>,
		1);

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

