/*
 * WebSocketConst.h
 *
 *  Created on: Jul 1, 2011
 *      Author: hekar
 */

#ifndef WEBSOCKETCONST_H_
#define WEBSOCKETCONST_H_

namespace ws {

enum ReadyState {
	CONNECTING = 0,
	OPENING,
	CLOSING,
	CLOSED
};

}

#endif /* WEBSOCKETCONST_H_ */
