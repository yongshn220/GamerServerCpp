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
#include "TypeCast.h"

using TL = TypeList<class Player, class Knight, class Archer>;

class Player
{
public:
	Player()
	{
		INIT_TL(Player);
	}

	DECLARE_TL
};

class Knight : public Player
{
public:
	Knight() 
	{
		INIT_TL(Knight);
	}
};

class Archer : public Player
{
public:
	Archer() 
	{
		INIT_TL(Knight);
	}
};

int main()
{
	{
		Player* player = new Knight();

		bool canCast = CanCast<Knight*>(player);
		Knight* knight = TypeCast<Knight*>(player);


		delete player;
	}

} 

