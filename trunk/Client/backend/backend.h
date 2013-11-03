/**
 backend.h

 Copyright 2013 Gaston Martinez Gaston.martinez.90@gmail.com

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses
 */
#ifndef BACKEND_H_
#define BACKEND_H_

#include <string>

class Backend {
public:
	Backend();
	virtual ~Backend();

	//Async control
	/**
	 * Devuelve si la ultima operacion asincronica se termino de ejecutar
	 * Similar a hacer poll en un subproceso
	 */
	bool operation_ended();
	/**
	 * Devuelve el error asociado a la ultima operacion o una cadena
	 * vacia si la operacion fue exitosa
	 */
	std::string operation_error();

	//Sync ops
	/**
	 * Devuelve si el backend tiene una sesion iniciada
	 */
	bool logued_in();

	//Login
	/**
	 * Envia el comando de inicio de sesion
	 */
	void async_log_in(const std::string user,const std::string password);

};

#endif /* BACKEND_H_ */
