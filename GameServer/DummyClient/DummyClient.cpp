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

	while (true)
	{
		if (::send(clientSocket, sendBuffer, sizeof(sendBuffer), 0) == SOCKET_ERROR)
		{
			if (::WSAGetLastError() == WSAEWOULDBLOCK)
				continue;
			break;

		}

		cout << "Send Data Len = " << sizeof(sendBuffer) << endl;

		char recvBuffer[1000];
		int32 recvLen = ::recv(clientSocket, recvBuffer, sizeof(recvBuffer), 0);
		if (recvLen == SOCKET_ERROR)
		{
			if (::WSAGetLastError() == WSAEWOULDBLOCK)
				continue;

			break;
		}

		else if (recvLen == 0)
		{
			break;
		}

		cout << "Recv Data Len" << recvLen << endl;


		this_thread::sleep_for(1s);
	}

	::closesocket(clientSocket);
	::WSACleanup();
}

