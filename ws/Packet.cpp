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

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "Packet.h"

//TODO: Provide method is validate challenge code

namespace ws {

HandShakePacket::HandShakePacket() {
}

HandShakePacket::HandShakePacket(const std::string & hostname,
		const std::string & origin, const std::string & protocol) {
	this->hostname.assign(hostname);
	this->origin.assign(origin);
	this->protocol.assign(protocol);
}

HandShakePacket::~HandShakePacket() {
}

const std::string HandShakePacket::ToString() {
	return generateHandShake();
}

const std::string HandShakePacket::generateHandShake() {
	std::stringstream str;

#define WS_KEY_ONE "6 4X 3$62 s032`x1"
#define WS_KEY_TWO "33SY< #]Z9 JE/ F12! 194&9   6"

	str << "GET / HTTP/1.1" << "\r\n";
	str << "Connection: Upgrade" << "\r\n";
	str << "Host: " << hostname << "\r\n";
	str << "Origin: " << origin << "\r\n";
	str << "Sec-WebSocket-Key1:" << WS_KEY_ONE << "\r\n";
	str << "Sec-WebSocket-Key2:" << WS_KEY_TWO << "\r\n";
	if (protocol != "") {
		str << "Sec-WebSocket-Protocol: " << protocol << "\r\n";
	}
	str << "Upgrade: WebSocket" << "\r\n\r\n";

	// Write the 8 byte 3rd key
	str << 0xFED87921CB526798 << "\r\n" << EOF;

	return str.str();
}

ws::Packet::Packet(char *data, size_t size) {
	size_t packetSize = size + 2;
	this->data = new char[packetSize];
	data[0] = 0x00;
	memcpy(this->data + 1, data, packetSize - 1);
	data[packetSize - 2] = 0x00;
}

ws::Packet::~Packet() {
	delete[] data;
}

const char *Packet::PacketResponse() {
	return data;
}

} /* namespace websocket */

