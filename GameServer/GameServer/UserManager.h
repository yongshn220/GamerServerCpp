#pragma once


class UserManager
{
	USE_LOCK;

public:
	void UserThenPlayer();
	void Lock();


};

extern UserManager GUserManager;

