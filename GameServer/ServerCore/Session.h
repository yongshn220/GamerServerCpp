#pragma once
#include "IocpCore.h"
#include "IocpEvent.h"
#include "NetAddress.h"

/*--------------
	Session
---------------*/

class Service;

class Session : public IocpObject
{
	friend class Listener;
	friend class IocpCore;
	friend class Service;

public:
	Session();
	virtual ~Session();

public:
	void				Disconnect(const WCHAR* reason);

	shared_ptr<Service> GetService() { return _service.lock(); }
	void				SetService(shared_ptr<Service> service) { _service = service; }

public:
	/* Info */
	void			SetNetAddress(NetAddress address) { _netAddress = address; }
	NetAddress		GetNetAddress() { return _netAddress; }
	SOCKET			GetSocket() { return _socket; }
	bool			IsConnected() { return _connected; }
	SessionRef		GetSessionRef() { return static_pointer_cast<Session>(shared_from_this()); }


private:
	/* Interface */
	virtual HANDLE  GetHandle() override;
	virtual void	Dispatch(class IocpEvent* iocpEvent, int32 numOfBytes = 0) override;


private:
	/* Transmit */
	void			RegisterConnect();
	void			RegisterRecv();
	void			RegisterSend();

	void			ProcessConnect();
	void			ProcessRecv(int32 numOfBytes);
	void			ProcessSend(int32 numOfBytes);

	void			HandleError(int32 errorCode);

protected:
	virtual void	OnConnected() {}
	virtual int32	OnRecv(BYTE* buffer, int32 len) { return len; }
	virtual void	OnSend(int32 len) {}
	virtual void	OnDisconnected() {}

public:
	char _recvBuffer[1000];

private:
	weak_ptr<Service>	_service;
	SOCKET				_socket = INVALID_SOCKET;
	NetAddress			_netAddress = {};
	Atomic<bool>		_connected = false;

private:
	USE_LOCK;

private:
	/* For reuse IocpEvent*/
	RecvEvent	_recvEvent;
};

