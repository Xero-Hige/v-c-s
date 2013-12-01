/*
 * position.h
 *
 * Created on: Nov 17, 2013
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

#ifndef POSITION_H_
#define POSITION_H_

#include "../game_messages/interface_json_serializable.h"

#include <jsoncpp/json.h>

/* Define un par ordenado para la ubicación de las cosas en los tableros *
 * usando coordenadas                                                    *
 * Se usará -1 como valor inválido para alguno de los miembros           */
class Position : public IJsonSerializable {
private:
    int x;
    int y;

public:
    Position()
        : x(-1), y(-1) {}
    Position(int x, int y)
        : x(x), y(y) {}
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    /* El índice 0 se refiere a la coordenada x, el 1 a la coordenada y *
     * Otro índice se considerará inválido y se devolverá -1            */
    int operator[](int pos);
    Position operator+(Position rhs);
    /**
     * Devuelve si la posicion actual es valida. Una
     * posicion valida tiene en sus coordenadas valores
     * mayores o iguales a 0
     */
    bool is_valid();
    void serialize(Json::Value& root);
    void deserialize(Json::Value& root);
};


#endif /* POSITION_H_ */
