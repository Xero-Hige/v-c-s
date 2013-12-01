/*
 * product.c
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

#include "product.h"

#include "../game_messages/interface_json_serializable.h"

#include <jsoncpp/json.h>

int Product::getColor() {
    return color;
}

int Product::getType() {
    return type;
}

void Product::serialize(Json::Value& root) {
    root["color"] = color;
    root["type"] = type;
}

void Product::deserialize(Json::Value& root) {
    color = root["color"].asInt();
    type = root["type"].asInt();
}
