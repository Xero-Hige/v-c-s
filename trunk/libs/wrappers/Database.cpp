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

int Database::exec(std::string query, std::string errmsg){
	//No hay ningun dato sobre un error ya que estoy pasando todo NULL
	//para simplificar.
	return sqlite3_exec(db, query.c_str(), NULL, NULL, NULL);
}

int Database::close(){
	return sqlite3_close(db);
}

Database::~Database() {
	// TODO Auto-generated destructor stub
}

