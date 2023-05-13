#include "pch.h"
#include "UserManager.h"
#include "PlayerManager.h"

UserManager GUserManager;

void UserManager::UserThenPlayer()
{
	WRITE_LOCK;
	GPlayerManager.Lock();
}

void UserManager::Lock()
{
	WRITE_LOCK;
}
