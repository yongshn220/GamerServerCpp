#pragma once
#include "IocpCore.h"
#include "NetAddress.h"


class AcceptEvent;
class ServerService;


/*-----------------
	  Listener
-------------------*/

class Listener : public IocpObject
{
public:
	Listener() {};
	~Listener();

public:
	/* Used outside of class*/
	bool StartAccept(ServerServiceRef service);
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
	ServerServiceRef _service;
};

