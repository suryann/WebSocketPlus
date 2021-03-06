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


#ifndef LINUXSOCKET_H_
#define LINUXSOCKET_H_

#include <cstdio>
#include "Socket.h"

class LinuxSocket {
public:
	LinuxSocket();
	virtual ~LinuxSocket();

	virtual void Read(char *buffer, size_t len);
	virtual void Write(char *buffer, size_t len);

private:

};

#endif /* LINUXSOCKET_H_ */
