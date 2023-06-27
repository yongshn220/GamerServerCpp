#include "pch.h"
#include <iostream>
#include "ThreadManager.h"
#include "Service.h"
#include "Session.h"
#include "GameSession.h"
#include "GameSessionManager.h"
#include "BufferWriter.h"
#include "ServerPacketHandler.h"

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
		vector<BuffData> buffs{ BuffData{100, 1.0f}, BuffData{200, 2.0f}, BuffData{300, 3.0f} };

		SendBufferRef sendBuffer = ServerPacketHandler::Make_S_TEST(1001, 100, 12, buffs, L"안녕");
		GSessionManager.Broadcast(sendBuffer);
		this_thread::sleep_for(250ms);
	}

	GThreadManager->Join();
}

