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

#ifndef PACKET_H_
#define PACKET_H_

#include <iostream>
#include <sstream>

namespace ws {

class HandShakePacket {
public:
	HandShakePacket();
	HandShakePacket(const std::string& hostname, const std::string& origin, const std::string& protocol = "");
	~HandShakePacket();

	const std::string ToString();

private:
	const std::string generateHandShake();

	std::string hostname;
	std::string origin;
	std::string protocol;
};

class Packet {
public:
	Packet(char *data, size_t size);
	~Packet();

	const char *PacketResponse();

private:
	char *data;
};

} /* namespace websocket */
#endif /* PACKET_H_ */
