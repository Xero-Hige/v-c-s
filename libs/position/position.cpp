/*
 * position.cpp
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

#include "position.h"

#include "../game_message_builder/interface_json_serializable.h"

#include <jsoncpp/json.h>

int Position::getX() {
    return x;
}

int Position::getY() {
    return y;
}

void Position::setX(int x) {
    this->x = x;
}

void Position::setY(int y) {
    this->y = y;
}

int Position::operator[](int pos) {
    if (pos == 0) {
        return x;
    } else if (pos == 1) {
        return y;
    }
    return -1;
}

//const int Position::operator[](int pos) const {
//    if (pos == 0) {
//        return x;
//    } else if (pos == 1) {
//        return y;
//    }
//    return -1;
//}

Position Position::operator+(Position rhs) {
    Position res = Position(this->x, this->y);
    res.x += rhs.x;
    res.y += rhs.y;
    return res;
}

bool Position::is_valid() {
	return (x >= 0 and y >= 0);
}

void Position::serialize(Json::Value& root) {
    root["x"] = x;
    root["y"] = y;
}

void Position::deserialize(Json::Value& root) {
    x = root["x"].asInt();
    y = root["y"].asInt();
}
