/*
 * MsgInterpreter.h
 *
 *  Created on: 03/11/2013
 *      Author: juan
 */

#ifndef MSGINTERPRETER_H_
#define MSGINTERPRETER_H_

#include <string>
#include "MsgConstants.h"

namespace std {

class MsgInterpreter {
	virtual void exitRoom() = 0;
	virtual void exitCharPressed() = 0;

public:
	MsgInterpreter();
	bool interpret(string s);
	virtual ~MsgInterpreter();
};

} /* namespace std */
#endif /* MSGINTERPRETER_H_ */
