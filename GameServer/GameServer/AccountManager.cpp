#include "pch.h"
#include "AccountManager.h"
#include "PlayerManager.h"
#include "UserManager.h"

AccountManager GAccountManager;


void AccountManager::AccountThenUser()
{
	WRITE_LOCK;
	GUserManager.Lock();
}

void AccountManager::Lock()
{
	WRITE_LOCK;
	this_thread::sleep_for(10ms);
}