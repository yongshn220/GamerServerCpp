#pragma once
class AccountManager
{
	USE_LOCK;

public:
	void AccountThenUser();
	void Lock();


};

extern AccountManager GAccountManager;

