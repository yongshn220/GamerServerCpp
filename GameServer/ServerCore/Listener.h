#pragma once
#include "IocpCore.h"
#include "NetAddress.h"


class AcceptEvent;

/*-----------------
	  Listener
-------------------*/

class Listener : IocpObject
{
public:
	Listener() = default;
	~Listener();

public:
	/* Used outside of class*/
	bool StartAccept(NetAddress netAddress);
	void CloseSocket();

public:
	/* Interface */
	virtual HANDLE GetHandle() override;
	virtual void Dispatch(class IocpEvent* iocpEvent, int32 numOfBytes = 0) override;

private:
	/* Receiver */
	void RegisterAccept(AcceptEvent* acceptEvent);
	void ProcessAccept(AcceptEvent* acceptEvent);

protected:
	SOCKET _socket = INVALID_SOCKET;
	xvector<AcceptEvent*> _acceptEvents;
};

