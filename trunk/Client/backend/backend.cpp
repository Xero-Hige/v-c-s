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

//#include "../../libs/boards/board.h"
//#include "../../libs/boards/replacements_board.h"
//#include "../../libs/checkers/combination_checker.h"
//#include "../../libs/checkers/physical_checker.h"

#include <stddef.h>
#include <cstdlib> //TODO sacar

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
	//TODO:
	vector<vector<int> > board;
	for (size_t x=0;x<schema.size();x++)
	{
		vector<int> column;
		for (size_t y=0;y<(schema[0].size()*2);y++)
		{
			if (schema[x][y%schema[0].size()] != 0){
				column.push_back(rand()%15 + 1);
			}
			else
			{
				column.push_back(0);
			}
		}

		board.push_back(column);
	}

	return board;
}

vector<Position> Backend::get_removed_pokemons() {
	//TODO:
	vector<Position> res;
	res.push_back(Position(10,35));
	res.push_back(Position(10,36));
	res.push_back(Position(10,37));
	res.push_back(Position(10,38));
	res.push_back(Position(10,39));
	res.push_back(Position(10,40));

	return res;
}

void Backend::async_get_room() {
	_operation_ended = true;
}

vector<vector<int> > Backend::get_board_schema() {
	//TODO:
	if (schema.size() == 0) {
		vector<int> column;
		for (int y = 0; y < 20; y++) {
			int a = rand()%7;
			column.push_back(a<2 ? 0:1);
		}
		for (int x = 0; x < 30; x++) {
			schema.push_back(column);
		}
	}
	return schema;
}

bool Backend::async_make_swap(Position pos_1, Position pos_2) {
	//TODO:
	return true;
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
