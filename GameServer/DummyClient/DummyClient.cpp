#include "pch.h"
#include <iostream>

#include <WinSock2.h>
#include <mswsock.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")


void HandleError(const char* cause)
{
	int32 errCode = ::WSAGetLastError();
	cout << errCode << endl;
}

int main()
{
	this_thread::sleep_for(2s);
	// Init Winsock (ws2_32)
	WSAData wsaData;
	if (::WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		return 0;
	
	// af       : Address Family (AF_INET = IPv4, AF_INET6 = IPv6)
	// type     : TCP(SOCK_STREAM), UDP (SOCK_DGRAM)
	// protocol : 0
	// return   : descriptor
	SOCKET clientSocket = ::socket(AF_INET, SOCK_STREAM, 0);

	u_long on = 1;
	if (::ioctlsocket(clientSocket, FIONBIO, &on) == INVALID_SOCKET)
	{
		return 0;
	}

	SOCKADDR_IN serverAddr;
	::memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	::inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);
	serverAddr.sin_port = ::htons(7777);


	cout << "c1" << endl;
	// Connect
	while (true)
	{
		if (::connect(clientSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
		{
			if (::WSAGetLastError() == WSAEWOULDBLOCK)
			{
				cout << "c2" << endl;
				continue;
			}
			if (::WSAGetLastError() == WSAEISCONN)
				break;

			// Error
			cout << "c error" << endl;
			break;
		}
	}

	cout << "Connected to Server" << endl;

	char sendBuffer[100] = "Hello World";
	WSAEVENT wsaEvent = ::WSACreateEvent();
	WSAOVERLAPPED overlapped = {};
	overlapped.hEvent = wsaEvent;

	while (true)
	{
		WSABUF wsaBuf;
		wsaBuf.buf = sendBuffer;
		wsaBuf.len = 100;

		DWORD sendLen = 0;
		DWORD flags = 0;
		::WSASend(clientSocket, &wsaBuf, 1, &sendLen, flags, &overlapped, nullptr);


		if (::WSASend(clientSocket, &wsaBuf, 1, &sendLen, flags, &overlapped, nullptr) == SOCKET_ERROR)
		{	  
			if (::WSAGetLastError() == WSA_IO_PENDING)
			{
				::WSAWaitForMultipleEvents(1, &wsaEvent, TRUE, WSA_INFINITE, FALSE);
				::WSAGetOverlappedResult(clientSocket, &overlapped, &sendLen, FALSE, &flags);
			}
			else
			{
				// error
				break;
			}
		}

		cout << "Send Data Len " << sizeof(sendBuffer) << endl;

		this_thread::sleep_for(1s);

	}

	::closesocket(clientSocket);
	::WSACleanup();
}

