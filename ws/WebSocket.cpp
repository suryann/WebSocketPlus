/*
 * WebSocket.cpp
 *
 *  Created on: Jun 24, 2011
 *      Author: hekar
 */

#include "WebSocket.h"

namespace ws {

WebSocket::WebSocket(Socket *socket, std::string url) {
}

WebSocket::~WebSocket() {
	delete socket;
}

void WebSocket::Write(char *message, size_t len) {
}

void WebSocket::OnMessage(char *message, size_t len) {
}

void WebSocket::OnOpen() {
}

void WebSocket::OnError() {
}

void WebSocket::OnClose() {
}

void WebSocket::Close() {
}

}
