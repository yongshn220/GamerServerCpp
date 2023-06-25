#include "pch.h"
#include <iostream>
#include "ThreadManager.h"
#include "Service.h"
#include "Session.h"
#include "GameSession.h"
#include "GameSessionManager.h"

int main()
{
	ServerServiceRef service = MakeShared<ServerService>(
		NetAddress(L"127.0.0.1", 7777),
		MakeShared<IocpCore>(),
		MakeShared<GameSession>,
		1
	);
	
	ASSERT_CRASH(service->Start());

	for(int32 i = 0; i < 5; i++)
	{
		GThreadManager->Launch([=]()
			{
				while (true)
				{
					service->GetIocpCore()->Dispatch();
				}
			});
	}

	char sendData[] = "Hello World";

	while (true)
	{
		if (GSessionManager.IsEmpty())
			continue;

		SendBufferRef sendBuffer = GSendBufferManager->Open(5500);

		BYTE* buffer = sendBuffer->Buffer();
		((PacketHeader*)buffer)->size = (sizeof(sendData) + sizeof(PacketHeader));
		((PacketHeader*)buffer)->id = 1; 
		::memcpy(&buffer[4], sendData, sizeof(sendData));
		sendBuffer->Close((sizeof(sendData) + sizeof(PacketHeader)));

		GSessionManager.Broadcast(sendBuffer);
		this_thread::sleep_for(250ms);
	}

	GThreadManager->Join();
}

