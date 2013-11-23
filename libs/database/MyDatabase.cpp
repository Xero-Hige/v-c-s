/*
 * MyDatabase.cpp
 *
 *  Created on: 17/11/2013
 *      Author: juan
 */

#include "MyDatabase.h"

MyDatabase::MyDatabase() {
	// TODO Auto-generated constructor stub

}

int MyDatabase::open() {
	return Database::open(DB_PATH);
}

MyDatabase::~MyDatabase() {
	// TODO Auto-generated destructor stub
}

