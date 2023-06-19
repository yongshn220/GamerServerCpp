#pragma once
#include "IocpCore.h"
#include "IocpEvent.h"
#include "NetAddress.h"

/*--------------
	Session
---------------*/

class Session : public IocpObject
{
public:
	Session();
	virtual ~Session();


public:
	/* Info */
	void		SetNetAddress(NetAddress address) { _netAddress = address; }
	NetAddress	GetNetAddress() { return _netAddress; }
	SOCKET		GetSocket() { return _socket; }


public:
	/* Interface */
	virtual HANDLE   GetHandle() override;
	virtual void	 Dispatch(class IocpEvent* iocpEvent, int32 numOfBytes = 0) override;


public:
	char _recvBuffer[1000];

private:
	SOCKET		   _socket = INVALID_SOCKET;
	NetAddress     _netAddress = {};
	Atomic<bool>   _connected = false;
};

