/**
 backend.cpp

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

#include "backend.h"

#include "../../libs/boards/board.h"
#include "../../libs/boards/tile.h"
#include "../../libs/checkers/combination_checker.h"
#include "../../libs/checkers/physical_checker.h"
#include "../../libs/level_reader/level_reader.h"

#include <stddef.h>
#include <cstdlib> //TODO sacar

#include <iostream> // FIXME borrame
#include "info_nivel.h" // FIXME borrame

using std::string;
using std::vector;

Backend::Backend() {

	ip="";
	port=0;

	logged=false;
	user_nick="";
	user_pass="";

	_operation_ended = true;
	_operation_error = "";
}

void Backend::async_connect(const std::string& ip,int port){
	//this->server_connector.makeConnection(ip, port);
}

bool Backend::logged_in(){
	return logged;
}

bool Backend::operation_ended() {
	return _operation_ended;
}

void Backend::setOperationEnded(bool b){
	this->_operation_ended = b;
}
void Backend::setLogged(bool b){
	this->logged = b;
}

string Backend::operation_error() {
	return _operation_error;
}

void Backend::async_log_in
(const std::string& user,const std::string& password,int auth_type){
	//this->server_connector.connectServer(user, password, "1");
}
Backend::~Backend() {
	// TODO Auto-generated destructor stub
}

void Backend::configureBoards() {
    board = Board(level_reader.getBoardHeight(), level_reader.getBoardWidth());
    replacements_board = Board(level_reader.getBoardHeight(), level_reader.getBoardWidth());
    physical_checker = PhysicalChecker(board);
    combination_checker = CombinationChecker(&board);
}

vector<string> Backend::get_board_pokemon_codes() {
	vector<string> codes;
	codes.push_back("001");
	codes.push_back("025");
	codes.push_back("108");
	codes.push_back("156");
	codes.push_back("197");

	return codes;
}

std::vector<std::vector<int> > Backend::get_full_board() {
	vector<vector<int> > products;
	for (int x = 0; x < board.getWidth(); x++) {
		vector<int> column;
		column.resize(board.getHeight()*2);
		for (int y = 0; y < board.getHeight(); y++) {
		    int product_code;
		    //TODO Pedirlo a board y a replacements_board en lugar de inventarlo acá
			if (board.getTileType(x, y) == Tile::CELL){
//				product_code = rand()%15+1;
				//FIXME
				product_code = ((y%5)*3)+1;
			}
			else
			{
				product_code = -1;
			}
	        // Tablero de reemplazos
			column[y] = product_code;
	        // Tablero de juego
			column[y+board.getHeight()] = product_code;
		}
		products.push_back(column);
	}

	return products;
}

vector<Position> Backend::get_removed_pokemons() {

	Position a=l[0];
	Position b=l[1];

	int x_a = a[0];
	int x_b = b[0];

	int y_a = a[1];
	int y_b = b[1];

	//TODO:
	vector<Position> res;
	res.push_back(Position(x_a,y_a));
	res.push_back(Position(x_a,y_a+1));
	res.push_back(Position(x_a,y_a-1));
	res.push_back(Position(x_b,y_b));
	res.push_back(Position(x_b,y_b+1));
	res.push_back(Position(x_b,y_b-1));

	return res;
}

void Backend::async_get_room() {
	_operation_ended = true;
}

vector<vector<int> > Backend::get_board_schema() {
    // FIXME Esto no va acá, hay que llamarlo al final de la screen de room o al princio del screen de level
    asyncGetLevelSpecification();
    configureBoards();
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    vector<vector<int> > schema = level_reader.getBoardSchema();
    board.setSchema(schema);
    replacements_board.setSchema(schema);
    return schema;
}

bool Backend::async_make_swap(Position pos1, Position pos2) {
    l[0] = pos1;
    l[1] = pos2;
    int x_difference = pos1.getX() - pos2.getX();
    int y_difference = pos1.getY() - pos2.getY();
    if (x_difference == 0) {
        if (y_difference == 1 || y_difference == -1) {
            return true;
        }
    } else if (y_difference == 0) {
        if (x_difference == 1 || x_difference == -1) {
            return true;
        }
    }
    return false;
}

void Backend::asyncGetLevelSpecification() {
    //TODO Que ande en serio
    string level_data = getLevelData();
    level_reader.changeLevelData(level_data);
}

//bool Backend::checkSwap(Position pos1, Position pos2) {
//    return physical_checker.checkSwap(pos1, pos2);
//}
//
//bool Backend::checkCombination(Position pos1, Position pos2) {
//    board.swapProducts(pos1, pos2);
//    if (combination_checker.check(pos1) || combination_checker.check(pos2)) {
//        return true;
//    }
//    board.swapProducts(pos1, pos2);
//    return false;
//}
