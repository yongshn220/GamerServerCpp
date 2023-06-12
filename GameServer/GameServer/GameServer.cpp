#include "pch.h"
#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <windows.h>
#include <future>
#include "ThreadManager.h"

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
	// Init Winsock (ws2_32)
	WSAData wsaData;
	if (::WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		return 0;
	
	SOCKET listenSocket = ::socket(AF_INET, SOCK_STREAM, 0);

	u_long on = 1;
	ioctlsocket(listenSocket, FIONBIO, &on);

	SOCKADDR_IN serverAddr;
	::memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = ::htonl(INADDR_ANY);
	serverAddr.sin_port = ::htons(7777);

	::bind(listenSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr));

	::listen(listenSocket, SOMAXCONN);

	SOCKADDR_IN clientAddr;
	int32 addrLen = sizeof(clientAddr);

	while (true)
	{
		SOCKET clientSocket = ::accept(listenSocket, (SOCKADDR*)&clientAddr, &addrLen);
		if (clientSocket == INVALID_SOCKET)
		{
			if (::WSAGetLastError() == WSAEWOULDBLOCK)
			{
				continue;
			}
		
			//Error
			break;
		}

		// Recv
		while (true)
		{
			char recvBuffer[1000];
			int32 recvLen = ::recv(clientSocket, recvBuffer, sizeof(recvBuffer), 0);
			if (recvLen == SOCKET_ERROR)
			{
				if (::WSAGetLastError() == WSAEWOULDBLOCK)
				{
					continue;
				}

				break;
			}

			else if (recvLen == 0)
			{
				break;
			}

			cout << "Recv Data Len" << recvLen << endl;

			// Send
			while (true)
			{
				if (::send(clientSocket, recvBuffer, recvLen, 0) == SOCKET_ERROR)
				{
					if (::WSAGetLastError() == WSAEWOULDBLOCK)
						continue;

					break;
				}

				cout << "Send Data Len = " << recvLen << endl;
				break;
			}
		}
	}


	::WSACleanup();

} 

