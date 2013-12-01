/*
 * MyDatabase.h
 *
 *  Created on: 17/11/2013
 *      Author: juan
 */

#ifndef MYDATABASE_H_
#define MYDATABASE_H_

#include "../wrappers/Database.h"
#include <string>

class MyDatabase : public Database{
	/*
	 * userAlreadyRegistered devuelve si 'user' ya estaba registrado en la base
	 * de datos.
	 */
	bool userAlreadyRegistered(std::string user);

public:
	MyDatabase();

	/*
	 * Los siguientes metodos devuelven codigos de error acorde a lo especificado
	 * por las constantes de la api sqlite3, a menos que se especifique lo contrario.
	 */

	/*
	 * open abre una base de datos existente o crea una nueva.
	 */
	int open();
	/*
	 * createTable crea una tabla en la base de datos que contiene user, nivel y
	 * password.
	 */
	int createTable();
	/*
	 * updateLevel actualiza el nivel en el que se encuentra el usuario en la base
	 * de datos.
	 */
	int updateLevel(std::string user, int new_level);
	/*
	 * requestPassword le pide a la base de datos el password registrado para
	 * el usuario 'user'.
	 */
	int requestPasswd(std::string user, std::string & passwd);
	/*
	 * requestPassword le pide a la base de datos el nivel registrado para
	 * el usuario 'user'.
	 */
	int requestLevel(std::string user, unsigned & level);
	/*
	 * registerUser registra un nuevo usuario en la base de datos. En caso de que el
	 * usuario ya exista se devuelve -1
	 */
	int registerUser(std::string user, std::string passwd, int level);
	virtual ~MyDatabase();
};

#endif /* MYDATABASE_H_ */
