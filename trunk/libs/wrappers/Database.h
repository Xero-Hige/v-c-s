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
	int prepare(std::string query, sqlite3_stmt * stmt);
	int step(sqlite3_stmt * stmt);
public:
	Database();
	int initialize();
	int exec(std::string query);
	int open(std::string path);
	int query(std::string query);
	int close();
	virtual ~Database();
};

#endif /* DATABASE_H_ */
