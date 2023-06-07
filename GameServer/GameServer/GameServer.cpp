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
		_typeId = IndexOf<TL, Player>::value;
	}

	using TL = TL;
	int _typeId;
};

class Knight : public Player
{
	Knight() { _typeId = IndexOf<TL, Knight>::value;  }
};

class Archer : public Player
{
	Archer() { _typeId = IndexOf<TL, Archer>::value;  }
};

int main()
{
} 

