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
	return sqlite3_open(path.c_str(), &db);
}

int Database::prepare(std::string query, sqlite3_stmt * stmt){
	return sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
}

int Database::query(std::string query){
	sqlite3_stmt * new_stmt;
	prepare(query.c_str(), new_stmt);
	step(new_stmt);
	sqlite3_finalize(new_stmt);
}

int Database::step(sqlite3_stmt * stmt){
	return sqlite3_step(stmt);
}

int Database::close(){
	return sqlite3_close(db);
}

Database::~Database() {
	// TODO Auto-generated destructor stub
}

