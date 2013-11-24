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

int Database::initialize(){
	return sqlite3_initialize();
}

int Database::open(std::string path){
	return sqlite3_open_v2(path.c_str(), &db,  SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);
}

int Database::prepare(std::string query, sqlite3_stmt * stmt){
	return sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
}

int Database::query(std::string query){
	sqlite3_stmt * new_stmt = NULL;
	int err_prep = prepare(query.c_str(), new_stmt);
	if (err_prep != SQLITE_OK) return err_prep;
	int err_step = step(new_stmt);
	if (err_step != SQLITE_DONE) return err_step;
	return sqlite3_finalize(new_stmt);
}


static int callback(void *NotUsed, int argc, char **argv, char **azColName){
   int i;
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int Database::exec(std::string query){
	return sqlite3_exec(db, query.c_str(), callback, NULL, NULL);
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
