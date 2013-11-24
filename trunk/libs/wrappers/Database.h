/*
 * Database.h
 *
 *  Created on: 17/11/2013
 *      Author: juan
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#include <sqlite3.h>
#include <stdio.h>
#include <string>

class Database {
	sqlite3 * db;
public:
	Database();
	int exec(std::string query, int(*callback)(void*,int,char**,char**) = NULL
			, void * callback_data = NULL);
	int open(std::string path);
	int close();
	virtual ~Database();
};

#endif /* DATABASE_H_ */
