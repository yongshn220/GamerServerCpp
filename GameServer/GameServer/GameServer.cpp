#include "pch.h"
#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <windows.h>
#include <future>
#include "ThreadManager.h"
#include "RefCounting.h"
#include "Memory.h"
#include "Allocator.h"


class Knight
{
public:
	int32 _hp = rand() % 1000;
};


SLIST_HEADER* GHeader;

int main()
{
	for (int32 i = 0; i < 4; i++)
	{
		GThreadManager->Launch([]()
			{
				while (true)
				{
					Knight* knight = xnew<Knight>();
					cout << knight->_hp << endl;
					this_thread::sleep_for(10ms);
					xdelete(knight);
				}
			}
		);
	}

	GThreadManager->Join();
} 

