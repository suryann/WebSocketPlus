/*
  WebSocketPlus - A websockets library for C++
  version 0.1 July 7, 2011

  Copyright (C) 2011

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.

  Hekar Khani "hekark@gmail.h"

*/

#ifdef WIN32
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "LoseSocket.h"
#include "SocketException.h"

LoseSocket::LoseSocket() {
	closed = false;
	if (WSAStartup(0x202, &wsaData) == SOCKET_ERROR) {
		throw SocketException(
				std::string("Failure to initialize Windows Socket"));
	}
}

LoseSocket::~LoseSocket() {
	if (!closed) {
		Close();
	}
	WSACleanup();
}

void LoseSocket::Connect(const std::string& ip_addr, int port) {
	unsigned int addr;
	struct hostent *hp;
	struct sockaddr_in server;

	addr = inet_addr(ip_addr.c_str());
	if (addr == INADDR_NONE) {
		hp = gethostbyname(ip_addr.c_str());
		if (hp == NULL) {
			throw SocketException(std::string("Failure to resolve Hostname"));
		}

		addr = *((unsigned int *) hp->h_addr_list[0]);
	}

	memset(&server, 0, sizeof(server));
	server.sin_addr.s_addr = addr;
	server.sin_family = AF_INET;
	server.sin_port = htons(port);

	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (clientSocket == INVALID_SOCKET) {
		throw SocketException(std::string("Failure to initialize Socket"));
	}

	if (connect(clientSocket, (struct sockaddr *) &server, sizeof(server))
			== SOCKET_ERROR) {
		throw SocketException(std::string("Failure to connect"));
	}
}

void LoseSocket::Close() {
	closesocket(clientSocket);
	closed = true;
}

int LoseSocket::Read(char *buffer, size_t len) {
	memset(buffer, 0, len);
	return recv(clientSocket, buffer, len, 0);
}

void LoseSocket::Write(const char *buffer, size_t len) {
	send(clientSocket, buffer, strlen(buffer), 0);
}

#endif // WIN32
