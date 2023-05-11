#include "pch.h"
#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <windows.h>
#include <future>
#include "ThreadManager.h"

#include "PlayerManager.h"
#include "AccountManager.h"

class TestLock
{
	USE_LOCK;

public:
	int32 TestRead()
	{
		READ_LOCK; 

		if (_queue.empty())
			return -1;

		return _queue.front();
	}

	void TestPush()
	{
		WRITE_LOCK;

		_queue.push(rand() % 100);
	}

	void TestPop()
	{
		WRITE_LOCK;

		if (_queue.empty() == false)
			_queue.pop();
	}

private:
	queue<int32> _queue;

};

TestLock testLock;


void ThreadWrite()
{
	while (true)
	{
		testLock.TestPush();
		this_thread::sleep_for(1ms);
		testLock.TestPop();
	}
}

void ThreadRead()
{
	while (true)
	{
		int32 value = testLock.TestRead();
		cout << value << endl;
		this_thread::sleep_for(1ms);
	}
}


int main()
{
	/*for (int32 i = 0; i < 2; i++)
	{
		GThreadManager->Launch(ThreadWrite);
	}

	for (int32 i = 0; i < 100; i++)
	{
		GThreadManager->Launch(ThreadRead);
	}

	GThreadManager->Join();*/

	GThreadManager->Launch([=]
		{
			while (true)
			{
				cout << "PlayerThenAcccount" << endl;
				GPlayerManager.PlayerThenAccount();
				this_thread::sleep_for(100ms);
			}
		});

	GThreadManager->Launch([=]
		{
			while (true)
			{
				cout << "AccountThenPlayer" << endl;
				GAccountManager.AccountThenPlayer();
				this_thread::sleep_for(100ms);
			}
		});
	GThreadManager->Join();

} 

