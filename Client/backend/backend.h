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
#include <vector>

#include "../../libs/boards/board.h"
#include "../../libs/boards/replacements_board.h"
#include "../../libs/checkers/combination_checker.h"
#include "../../libs/checkers/physical_checker.h"
#include "../../libs/messages/MsgConstants.h"
#include "../../libs/position/position.h"
#include "../../libs/level_reader/level_reader.h"

class Backend {

private:

	//Server_Connector server_connector;

	//Connection info
	std::string ip;
	int port;

	//Login info
	bool logged;
	std::string user_nick;
	std::string user_pass;

	std::vector<std::vector<int> > schema;

	//Async info
	bool _operation_ended;
	std::string _operation_error;

	// Tableros lógicos
	Board board;
	ReplacementsBoard replacements_board;

	// Checkers
//	PhysicalChecker physical_checker;
//	CombinationChecker combination_checker;

	LevelReader level_reader;

	Position l[2];

private:

	void setOperationEnded(bool b);
	void setLogged(bool b);

public:
	Backend();
	virtual ~Backend();

	/* Verifica si el cambio entre esas posiciones es válido */
	bool checkSwap(Position pos1, Position pos2);

	/* Verifica si hay combinación con el cambio de las dos posiciones *
	 * El cambio debe haberse efectuado                                */
	bool checkCombination(Position pos1, Position pos2);

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
	bool logged_in();

	/**
	 * Devuelve un esquema del tablero, 0 si no hay celda
	 * y otro numero si hay una celda (numero que se corresponde
	 * con la imagen de la celda)
	 */
	std::vector<std::vector<int> > get_board_schema();

	/**
	 * Devuelve la matriz de tablero completa (incluido el no visible)
	 * en el cual se le asigno a cada ficha un numero.
	 */
	std::vector<std::vector<int> > get_full_board();

	/**
	 * Devuelve una lista con los codigos de los sprites que se
	 * utilizaran para los pokemons de este nivel.
	 */
	std::vector<std::string> get_board_pokemon_codes();

	/**
	 * Devuelve una lista de las posiciones que se
	 * eliminan con el ultimo movimiento
	 */
	std::vector<Position> get_removed_pokemons();

	//ASYNC
	//Connect
	/**
	 * Envia el comando de conexion con el servidor
	 */
	void async_connect(const std::string& ip, int port);

	//Login
	/**
	 * Envia el comando de inicio de sesion
	 */
	void async_log_in(const std::string& user, const std::string& password,
			int auth_type = TYPE_LOGIN);

	//Rooms
	/**
	 * Envia el comando para obtener una room para el nivel actual
	 */
	void async_get_room();

	//Game
	/**
	 * Hace un swap entre los elementos. Devuelve true en caso que se pueda
	 * llegar a intercambiar, false en caso contrario.
	 */
	bool async_make_swap(Position pos1,Position pos2);
};

#endif /* BACKEND_H_ */
