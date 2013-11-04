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

Backend::Backend() {
}

void Backend::async_connect(const std::string& ip,int port){
	this->server_connector.makeConnection(ip, port);
}

bool Backend::logged_in(){
	return logged;
}

void Backend::async_log_in
(const std::string& user,const std::string& password,int auth_type){
	int err = 0;
	//ESTO ES ASYNC?
	this->server_connector.connectServer(err, user, password, "1");
	if (err){
		//todo
	}
}

Backend::~Backend() {
	// TODO Auto-generated destructor stub
}

