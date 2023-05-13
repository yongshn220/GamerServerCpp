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
#include "UserManager.h"

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




bool IsPrime(int num)
{
	if (num == 1) return false;
	if (num == 2) return true;

	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}


int CountPrimes(int s, int e)
{
	int count = 0;
	for (int i = s; i < e; i++)
	{
		if (IsPrime(i))
			count++;
	}
	return count;
}

int main()
{
	vector<thread> threads;
	atomic<int> count = 0;

	const int MAX_NUMBER = 10;

	int coreCount = thread::hardware_concurrency();
	cout << coreCount << endl;

	int jobCount = MAX_NUMBER / coreCount + 1;

	for (int i = 0; i < coreCount; i++)
	{
		int s = i * jobCount + 1;
		int e = min(MAX_NUMBER, (i + 1) * jobCount);

		threads.push_back(thread([s, e, &count]() {
			count += CountPrimes(s, e);
			}));
	}

	for (thread& t : threads)
	{
		t.join();
	}

	cout << "count: " << count << endl;

} 

