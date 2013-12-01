/*
 * take_out_product_effect.cpp
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

#include "take_out_product_effect.h"

#include "combination_effect.h"
#include "../position/position.h"
#include "../game_message_builder/interface_json_serializable.h"

#include <vector>
#include <jsoncpp/json.h>

using std::vector;

//void TakeOutProductEffect::applyEffect() {
//    //TODO
//}

vector<Position> TakeOutProductEffect::getEliminatedProducts() {
    vector<Position> products_to_eliminate;
    for (int x = ending_pos.getX(); x >= initial_pos.getX(); x--) {
        for (int y = ending_pos.getY(); y >= initial_pos.getY(); y--) {
            products_to_eliminate.push_back(Position(x,y));
        }
    }
    return products_to_eliminate;
}

void TakeOutProductEffect::serialize(Json::Value& root) {
    CombinationEffect::serialize(root);
    root["type"] = "TakeOutProductEffect";
    Json::Value initial_pos_value;
    initial_pos.serialize(initial_pos_value);
    root["initial pos"] = initial_pos_value;
    Json::Value ending_pos_value;
    ending_pos.serialize(ending_pos_value);
    root["ending pos"] = ending_pos_value;
}

void TakeOutProductEffect::deserialize(Json::Value& root) {
    CombinationEffect::deserialize(root);
    Json::Value initial_pos_value = root["initial pos"];
    initial_pos.deserialize(initial_pos_value);
    Json::Value ending_pos_value = root["ending pos"];
    ending_pos.deserialize(ending_pos_value);
}
