/*
 * clean_board_effect.cpp
 *
 * Created on: Nov 26, 2013
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

#include "clean_board_effect.h"

#include "combination_effect.h"
#include "../position/position.h"
#include "../game_message_builder/interface_json_serializable.h"

#include <vector>
#include <jsoncpp/json.h>

using std::vector;

//void applyEffect() {
//    //TODO
//}

vector<Position> CleanBoardEffect::getEliminatedProducts() {
    vector<Position> ret_vector;
    // Una posición (-1,-1) indica que hay que borrar todos los productos
    ret_vector.push_back(Position(-1,-1));
    return ret_vector;
}

void CleanBoardEffect::serialize(Json::Value& root) {
    CombinationEffect::serialize(root);
    root["type"] = "CleanBoardEffect";
}

void CleanBoardEffect::deserialize(Json::Value& root) {
    CombinationEffect::deserialize(root);
}
