/*
 * nested_file_parse.cpp
 *
 * Created on: Oct 27, 2013
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

void printBoard(unsigned int width, unsigned int height, Json::Value tiles) {
    Json::Value current_tile;
    for (unsigned int y = 0; y < height; y++) {
        for (unsigned int x = 0; x < width; x++) {
            current_tile = tiles[x + (y*width)];
            if (current_tile["type"].asString() == "cell") {
                cout << "C";
            } else {
                cout << "H";
            }
            cout << current_tile["number"].asInt() << " ";
        }
        cout << endl;
    }
}

int main() {
    Json::Reader reader;
    Json::Value buffer;
    bool parsed;
    ifstream file_stream;
    file_stream.open("nested_data.json");
    parsed = reader.parse(file_stream, buffer, false);
    if (! parsed) {
        cout << "Error parseando" << endl;
        cout << reader.getFormatedErrorMessages() << endl;
        return 1;
    }
    // Se obtiene:
    // Numero de nivel
    unsigned int level_number = buffer["number"].asUInt();
    // Dimensiones
    unsigned int dimensions[2];
    dimensions[0] = buffer["width"].asUInt();
    dimensions[1] = buffer["height"].asUInt();
    // Cantidad de jugadores
    unsigned int n_players = buffer["players"].asUInt();
    // Puntaje para pasar el nivel
    unsigned int goal_score = buffer["goalScore"].asUInt();
    cout << "Nivel número " << level_number << endl;
    cout << "Tamaño: " << dimensions[0] << "x" << dimensions[1] << endl;
    cout << "Cantidad de jugadores: " << n_players << endl;
    cout << "Puntaje para pasarlo: " << goal_score << endl;
    cout << "Tablero:" << endl;
    printBoard(dimensions[0], dimensions[1], buffer["tiles"]);
    return 0;
}


