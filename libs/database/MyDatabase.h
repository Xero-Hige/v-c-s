/*
 * MyDatabase.h
 *
 *  Created on: 17/11/2013
 *      Author: juan
 */

#ifndef MYDATABASE_H_
#define MYDATABASE_H_

#include "Database.h"

class MyDatabase : public Database{
public:
	MyDatabase();
	int open();
	int createTable();
	int insertValues(std::string user, std::string passwd, int level);
	virtual ~MyDatabase();
};

#endif /* MYDATABASE_H_ */
