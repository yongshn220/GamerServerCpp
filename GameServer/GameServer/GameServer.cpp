#include "pch.h"
#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <windows.h>
#include <future>
#include "ThreadManager.h"
#include "RefCounting.h"

class Wraight : public RefCountable
{
public:
	int _hp = 150;
	int _posX = 0;
	int _posY = 0;
};

class Missile : public RefCountable
{
public:
	void SetTarget(Wraight* target)
	{
		_target = target;
		target->AddRef();
	}

	bool Update()
	{
		if (_target == nullptr) return true;
		int posX = _target->_posX;
		int posY = _target->_posY;

		if (_target->_hp == 0)
		{
			_target->ReleaseRef();
			_target = nullptr;
		}
		return false;
	}

	Wraight* _target = nullptr;
};


using WraightRef = TSharedPtr<Wraight>;
using MissileRef = TSharedPtr<Missile>;

int main()
{
	WraightRef wraight(new Wraight());
	wraight->ReleaseRef();
	MissileRef missile(new Missile());
	missile->ReleaseRef();

	missile->SetTarget(wraight);

	wraight->_hp = 0;
	wraight = nullptr;
	wraight = WraightRef(nullptr);




	while (true)
	{
		if (missile)
		{
			if (missile->Update())
			{
				missile->ReleaseRef();
				missile = nullptr;
			}
		}
	}
	
	if (missile)
	{
		missile->ReleaseRef();
		missile = nullptr;
	}
} 

