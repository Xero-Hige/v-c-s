/*
 * simple_value.cpp
 *
 * Created on: Oct 24, 2013
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
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {
    // id
    // {
    //     number
    //     name
    // }
    string id1 = "{               \
                    \"number\":   \
                        \"1234\", \
                    \"name\":    \
                        \"test1\" \
                  }";
    string id2 = "{               \
                    \"number\":   \
                        \"5678\", \
                    \"name\":    \
                        \"test2\" \
                  }";
    string ids[2] = {id1, id2};
    // Parseo
    Json::Value buffer[2];
    Json::Reader reader;
    for (int i = 0; i < 2; i++) {
        bool parsed = reader.parse(ids[i], buffer[i], false);
        if(not parsed)
        {
            // Se muestran las fallas y su ubicación
            cout << "Error parseando" << endl;
            cout << reader.getFormatedErrorMessages() << endl;
            return 1;
        }
    }
    // Extraer valores e imprimirlos
    cout << "Nombre 1 (sin pasar a Json::Value): "
         << buffer[0]["name"].asString() << endl;
    Json::Value name = buffer[0]["name"];
    cout << "Nombre 1 (desde Json::Value): " << name.asString() << endl;
    // Imprime con formato
    cout << endl << "Impresión con formato: " << endl;
    cout << buffer[0].toStyledString();  // toStyledString le pone el \n
    cout << buffer[1].toStyledString();
    return 0;
}
