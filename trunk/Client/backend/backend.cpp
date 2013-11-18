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

#include <stdlib.h> //TODO sacar

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
	vector<vector<int> > schema;
	for (int x=0;x<30;x++)
	{
		vector<int> column;
		for (int y=0;y<40;y++)
		{
			column.push_back(rand()%16);
		}

		schema.push_back(column);
	}

	return schema;
}

void Backend::async_get_room() {
	_operation_ended = true;
}

vector< vector<int> > Backend::get_board_schema() {
	//TODO:
	vector<vector<int> > schema;
	vector<int> column;
	for (int x=0;x<20;x++)
	{
		column.push_back(1);
	}
	for (int x=0;x<30;x++)
	{
		schema.push_back(column);
	}

	return schema;
}
