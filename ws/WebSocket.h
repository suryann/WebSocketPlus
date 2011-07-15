/*
 * WebSocket.h
 *
 *  Created on: Jun 24, 2011
 *      Author: hekar
 */

#ifndef WEBSOCKET_H_
#define WEBSOCKET_H_

#include "Socket.h"

namespace ws {
class WebSocket {
public:
	WebSocket(Socket *socket, std::string url);
	virtual ~WebSocket();

	virtual void Write(char *message, size_t len);

	virtual void OnMessage(char *message, size_t len);
	virtual void OnOpen();
	virtual void OnError();
	virtual void OnClose();

	virtual void Close();

protected:
	std::string url;
	std::string protocol;
	std::string extensions;
	Socket *socket;
};

}
#endif /* WEBSOCKET_H_ */
