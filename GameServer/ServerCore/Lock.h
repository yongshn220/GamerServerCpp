#pragma once
#include "Types.h"

/*-------------
*  RW SpinLock
---------------*/

/*-------------
* 32 bits
* [WWWWWWWW][WWWWWWWW][RRRRRRRR][RRRRRRRR]
---------------*/
class Lock
{
	enum : uint32
	{
		ACQUIRE_TIMEOUT_TICK = 10000,
		MAX_SPIN_COUNT = 5000,
		WRITE_THREAD_MASK = static_cast<uint32>(0xFFFF0000),
		READ_COUNT_MASK = 0x0000FFFF,
		EMPTY_FLAG = 0x00000000
	};

public:
	void WriteLock(const char* name);
	void WriteUnlock(const char* name);
	void ReadLock(const char* name);
	void ReadUnlock(const char* name);

private:
	Atomic<uint32> _lockFlag = EMPTY_FLAG;
	uint16 _writeCount = 0;
};


/*--------------------------
*    LockGuards
--------------------------*/

class ReadLockGuard
{

public:
	ReadLockGuard(Lock& lock, const char* name) : _lock(lock), _name(name)
	{ 
		_lock.ReadLock(_name); 
	}
	~ReadLockGuard() 
	{ 
		_lock.ReadUnlock(_name); 
	}

private:
	Lock& _lock;
	const char* _name;
};

class WriteLockGuard
{
public:
	WriteLockGuard(Lock& lock, const char* name) : _lock(lock), _name(name)
	{ 
		_lock.WriteLock(_name); 
	}
	~WriteLockGuard() 
	{ 
		_lock.WriteUnlock(_name); 
	};

private:
	Lock& _lock;
	const char* _name;
};