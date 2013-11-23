/*
 * MyDatabase.h
 *
 *  Created on: 17/11/2013
 *      Author: juan
 */

#ifndef MYDATABASE_H_
#define MYDATABASE_H_

#define DB_PATH "test.db"

#include "../wrappers/Database.h"

class MyDatabase : public Database{
public:
	MyDatabase();
	int open();
	virtual ~MyDatabase();
};

#endif /* MYDATABASE_H_ */
