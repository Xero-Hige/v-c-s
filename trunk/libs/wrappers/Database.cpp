/*
 * Database.cpp
 *
 *  Created on: 17/11/2013
 *      Author: juan
 */

#include "Database.h"

Database::Database() {
	db = NULL;
}

int Database::open(std::string path){
	return sqlite3_open_v2(path.c_str(), &db,
			SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);
}

int Database::exec(std::string query,int(*callback)(void*,int,char**,char**),
		void * callback_data){
	mutx.lock();
	int r = sqlite3_exec(db, query.c_str(), callback, callback_data, NULL);
	mutx.unlock();
	return r;
}

int Database::close(){
	return sqlite3_close(db);
}

Database::~Database() {
	// TODO Auto-generated destructor stub
}

