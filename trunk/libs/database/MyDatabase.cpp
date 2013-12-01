/*
 * MyDatabase.cpp
 *
 *  Created on: 17/11/2013
 *      Author: juan
 */

#include "MyDatabase.h"
#include <sstream>
#include <stdlib.h>
#include <string>

/*
 * Constantes referidas a las palabras reservadas de SQL
 */
#define DB_CREATE_TABLE "CREATE TABLE "
#define DB_INSERT "INSERT INTO "
#define DB_VALUES " VALUES "
#define DB_UPDATE "UPDATE "
#define DB_WHERE " WHERE "
#define DB_SET " SET "
#define DB_SELECT "SELECT "
#define DB_FROM " FROM "
/*
 * path de la base de datos a crear
 */
#define DB_PATH "test.db"

/*
 * constantes que indican como va a ser la base de datos que se va a usar en nuestra
 * aplicacion
 */
#define TABLE_NAME "USERS"
#define COLUMNS "(ID       TEXT    PRIMARY KEY  NOT NULL," \
				"PASSWD    TEXT    NOT NULL," \
				"LEVEL     INT     NOT NULL);"
#define COLUMN_ALL "*"
#define COLUMN_ID "ID"
#define COLUMN_PASS "PASSWD"
#define COLUMN_LEVEL "LEVEL"
#define COLUMN_ID_NUMBER 0
#define COLUMN_PASS_NUMBER 1
#define COLUMN_LEVEL_NUMBER 2
#define SEMICOLON ";"
#define EQUALS "="
#define APHOSTROPHE "'"
#define POS_BEGGINING 0

MyDatabase::MyDatabase() {
}

/*
 * insertAphostrophes agrega apostrofes al principio y final de un string.
 */
void insertAphostrophes(std::string & arg0){
	arg0.insert(POS_BEGGINING, APHOSTROPHE);
	arg0.append(APHOSTROPHE);
}

/*
 * itostring transforma un integer en un string.
 */
std::string itostring(int arg0){
	std::stringstream ss;
	ss << arg0;
	return ss.str();
}

/*
 * valuesConcatenation formatea los argumentos para que concuerde con el formato de
 * una query de una base de datos
 * Por ejemplo, en este caso: ('arg0', 'arg1', arg2)
 */
std::string valuesConcatenation(std::string arg0, std::string arg1, int arg2){
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

int MyDatabase::registerUser(std::string user, std::string passwd, int level){
	if (userAlreadyRegistered(user)) return -1;
	std::string query(DB_INSERT);
	query = query + TABLE_NAME + DB_VALUES +
				valuesConcatenation(user, passwd, level) + SEMICOLON;
	return Database::exec(query);
}

int MyDatabase::createTable(){
	std::string query(DB_CREATE_TABLE);
	query = query + TABLE_NAME + COLUMNS;
	return Database::exec(query);
}

/*
 * concatenateLevelValue formatea el nivel indicado para que concuerde con el
 * formato de una base de datos, por ejemplo: LEVEL=arg0
 */
std::string concatenateLevelValue(int arg0){
	std::string s(COLUMN_LEVEL);
	s.append(EQUALS);
	s.append(itostring(arg0));
	return s;
}

/*
 * concatenateUserValue formatea el usuario indicado para que concuerde con el
 * formato de una base de datos, por ejemplo: USER='arg0'
 */
std::string concatenateUserValue(std::string arg0){
	std::string s(COLUMN_ID);
	s.append(EQUALS);
	insertAphostrophes(arg0);
	s.append(arg0);
	return s;
}

int MyDatabase::updateLevel(std::string user, int new_level){
	std::string query(DB_UPDATE);
	query = query + TABLE_NAME + DB_SET + concatenateLevelValue(new_level)
			+ DB_WHERE + concatenateUserValue(user) + SEMICOLON;
	return Database::exec(query);
}

int callback_reqPass(void * data, int cols ,char** row_values,char** cols_name){
	//data es el valor que se le pasa a la funcion exc en el 4to parametro, en este
	//caso le paso un string porque quiero conseguir el passwd del user.
	//casteo el puntero
	std::string * s_ptr = (std::string*)data;
	s_ptr->clear();
	s_ptr->append(row_values[COLUMN_PASS_NUMBER]);
	return 0;
}

int MyDatabase::requestPasswd(std::string user, std::string & passwd){
	std::string query(DB_SELECT);
	query = query + COLUMN_ALL + DB_FROM + TABLE_NAME + DB_WHERE
		+ concatenateUserValue(user);
	return Database::exec(query, callback_reqPass, (void*)&passwd);
}

int callback_alreadyRegistered
(void * data, int cols ,char** row_values,char** cols_name){
	//Si se llama esta funcion significa que hay un user con ese nombre.
	bool * b = (bool*)data;
	*b = true;
	return 0;
}

bool MyDatabase::userAlreadyRegistered(std::string user){
	std::string query(DB_SELECT);
	query = query + COLUMN_ID + DB_FROM + TABLE_NAME + DB_WHERE
		+ concatenateUserValue(user);
	bool b = false;
	Database::exec(query, callback_alreadyRegistered, (void*)&b);
	return b;
}

int callback_reqLevel
(void * data, int cols ,char** row_values,char** cols_name){
	//Idem callback_reqPass(). Uso strings y despues lo convierto en int
	std::string * s_ptr = (std::string*)data;
	s_ptr->clear();
	s_ptr->append(row_values[COLUMN_LEVEL_NUMBER]);
	return 0;
}

int MyDatabase::requestLevel(std::string user, unsigned & level){
	std::string query(DB_SELECT);
	query = query + COLUMN_ALL + DB_FROM + TABLE_NAME + DB_WHERE
			+ concatenateUserValue(user);
	std::string s_level;
	int r = Database::exec(query, callback_reqLevel, (void*)&s_level);
	level = atoi(s_level.c_str());
	return r;
}

int MyDatabase::open() {
	return Database::open(DB_PATH);
}

MyDatabase::~MyDatabase() {
	// TODO Auto-generated destructor stub
}
