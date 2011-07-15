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

#ifndef SOCKETEXCEPTION_H_
#define SOCKETEXCEPTION_H_

#include <iostream>

class SocketException {
public:
	SocketException();
	SocketException(char *message);
	SocketException(const std::string& message);

	const std::string& what() const;

private:
	std::string message;
};





#endif /* SOCKETEXCEPTION_H_ */
