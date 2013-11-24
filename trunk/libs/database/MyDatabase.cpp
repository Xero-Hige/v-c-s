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

#define TABLE_NAME "USERS"
#define COLUMNS "(ID       TEXT    PRIMARY KEY  NOT NULL," \
				"PASSWD    TEXT    NOT NULL," \
				"LEVEL     INT     NOT NULL);"

#define SEMICOLON ";"
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

int MyDatabase::createTable(){
	return Database::exec(std::string(DB_CREATE_TABLE) + TABLE_NAME + COLUMNS);
}

int MyDatabase::open() {
	return Database::open(DB_PATH);
}

MyDatabase::~MyDatabase() {
	// TODO Auto-generated destructor stub
}
