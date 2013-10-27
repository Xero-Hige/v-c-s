/*
 * basic_file_parse.cpp
 *
 * Created on: Oct 26, 2013
 * 
 * Copyright 2013 Bruno Merlo Schurmann <brunomerloschurmann@gmail.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses 
 */

#include <jsoncpp/json.h>
#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;

int main() {
    Json::Reader reader;
    Json::Value buffer;
    bool parsed;
    ifstream file_stream;
    file_stream.open("basic_data.json");
    parsed = reader.parse(file_stream, buffer, false);
    if (! parsed) {
        cout << "Error parseando" << endl;
        cout << reader.getFormatedErrorMessages() << endl;
        return 1;
    }
    // \Todo el contenido
    // (si no pongo la \ lo toma como TO DO y lo marca =P )
    cout << "Todo el contenido:" << endl;
    cout << buffer.toStyledString();
    // Datos de la dirección
    Json::Value address = buffer["address"];
    cout << endl << "Datos de la dirección:" << endl;
    cout << "Dirección: " << address["streetAddress"].asString() << endl;
    cout << "Ciudad: " << address["city"].asString() << endl;
    cout << "Estado: " << address["state"].asString() << endl;
    cout << "Código postal: " << address["postalCode"].asInt() << endl;
    return 0;
}


