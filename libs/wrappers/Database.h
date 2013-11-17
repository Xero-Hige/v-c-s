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

class Database {
	sqlite3 * db;
public:
	Database();
	int open(std::string path);
	int exec(std::string query, std::string errmsg);
	int close();
	virtual ~Database();
};

#endif /* DATABASE_H_ */
