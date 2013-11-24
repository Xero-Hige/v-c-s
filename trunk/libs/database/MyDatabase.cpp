/*
 * MyDatabase.cpp
 *
 *  Created on: 17/11/2013
 *      Author: juan
 */

#include "MyDatabase.h"
#include <sstream>

#define DB_CREATE_TABLE "CREATE TABLE "
#define DB_INSERT "INSERT INTO "
#define DB_VALUES " VALUES "
#define DB_UPDATE "UPDATE "
#define DB_WHERE " WHERE "
#define DB_SET " SET "

#define TABLE_NAME "USERS"
#define COLUMNS "(ID       TEXT    PRIMARY KEY  NOT NULL," \
				"PASSWD    TEXT    NOT NULL," \
				"LEVEL     INT     NOT NULL);"

#define COLUMN_ID "ID"
#define COLUMN_PASS "PASSWD"
#define COLUMN_LEVEL "LEVEL"
#define SEMICOLON ";"
#define EQUALS "="
#define APHOSTROPHE "'"
#define POS_BEGGINING 0
#define DB_PATH "test.db"

MyDatabase::MyDatabase() {
	// TODO Auto-generated constructor stub

}

void insertAphostrophes(std::string & arg0){
	arg0.insert(POS_BEGGINING, APHOSTROPHE);
	arg0.append(APHOSTROPHE);
}

std::string itostring(int arg0){
	std::stringstream ss;
	ss << arg0;
	return ss.str();
}

std::string valuesConcatenation(std::string arg0, std::string arg1, int arg2){
	//Tiene que devolver los valores en un string como si fuera una query de base
	//de datos, es decir, ('arg0', 'arg1', arg2);
	std::stringstream ss;
	ss << "(";
	insertAphostrophes(arg0);
	insertAphostrophes(arg1);
	ss << arg0;
	ss << ", ";
	ss << arg1;
	ss << ", ";
	ss << itostring(arg2);
	ss << ")";
	return ss.str();
}

int MyDatabase::insertValues(std::string user, std::string passwd, int level){
	return Database::exec(std::string(DB_INSERT) + TABLE_NAME + DB_VALUES +
			valuesConcatenation(user, passwd, level) + SEMICOLON);
}

std::string concatenateLevelValue(int arg0){
	std::string s (COLUMN_LEVEL);
	s.append(EQUALS);
	s.append(itostring(arg0));
	return s;
}

std::string concatenateUserValue(std::string arg0){
	std::string s (COLUMN_ID);
	s.append(EQUALS);
	insertAphostrophes(arg0);
	s.append(arg0);
	return s;
}

int MyDatabase::updateLevel(std::string user, int new_level){
	return Database::exec(std::string(DB_UPDATE) + TABLE_NAME + DB_SET +
			concatenateLevelValue(new_level) + DB_WHERE + concatenateUserValue(user)
			+ SEMICOLON);
}

int MyDatabase::createTable(){
	return Database::exec(std::string(DB_CREATE_TABLE) + TABLE_NAME + COLUMNS);
}

int MyDatabase::open() {
	return Database::open(DB_PATH);
}

MyDatabase::~MyDatabase() {
	// TODO Auto-generated destructor stub
}
