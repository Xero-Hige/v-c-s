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

class MsgInterpreter {
	virtual void manageBoard() = 0;
	virtual void manageReplacements() = 0;
	virtual void manageLevel() = 0;
	virtual void closeConnection() = 0;
	virtual void exitRoom() = 0;
	virtual void exitCharPressed() = 0;
	virtual void interpretParticularMsg(std::string s) = 0;
public:
	MsgInterpreter();
	bool interpret(std::string s);
	virtual ~MsgInterpreter();
};

#endif /* MSGINTERPRETER_H_ */
