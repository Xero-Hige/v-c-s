/*
 * take_out_row_effect.cpp
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

#include "take_out_row_effect.h"

#include "combination_effect.h"
#include "../position/position.h"
#include "../game_messages/interface_json_serializable.h"

#include <vector>
#include <jsoncpp/json.h>

using std::vector;

void TakeOutRowEffect::applyEffect(Board& board) {
    if (isApplied()) {
        return;
    }
    int row = origin.getY();
    board.takeOutRow(row);
    setApplied();
}

vector<Position> TakeOutRowEffect::getEliminatedProducts() {
    vector<Position> products_to_eliminate;
    int y = origin.getY();
    for (int x = board_width; x >= 0; x++) {
        products_to_eliminate.push_back(Position(x,y));
    }
    return products_to_eliminate;
}

void TakeOutRowEffect::serialize(Json::Value& root) {
    CombinationEffect::serialize(root);
    root["type"] = "TakeOutRowEffect";
    root["board width"] = board_width;
}

void TakeOutRowEffect::deserialize(Json::Value& root) {
    CombinationEffect::deserialize(root);
    board_width = root["board width"].asInt();
}
