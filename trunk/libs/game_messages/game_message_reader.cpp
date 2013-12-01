/*
 * game_message_reader.cpp
 *
 * Created on: Dec 1, 2013
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

#include "game_message_reader.h"

#include "message_reader.h"
#include "interface_json_serializable.h"
#include "../position/position.h"
#include "../boards/product.h"
#include "../combination_effects/combination_effect.h"
#include "combination_effects_factory.h"

#include <string>
#include <vector>
#include <list>
#include <jsoncpp/json.h>

using std::string;
using std::vector;
using std::list;

void GameMessageReader::readScoreUpdateMsg(string& user_id, int& score, MessageReader& msg_body) {
    user_id = msg_body.getStringField("user id");
    score = msg_body.getIntField("score");
}

void GameMessageReader::readGameOverMsg(std::string& user_id, MessageReader& msg_body) {
    user_id = msg_body.getStringField("user id");
}

void GameMessageReader::readSwapMessage(std::string& user_id, Position& position1, Position& position2, MessageReader& msg_body) {
    user_id = msg_body.getStringField("user id");
    msg_body.getObjectField("position 1", &position1);
    msg_body.getObjectField("position 2", &position2);
}

void GameMessageReader::readProductRefill(int& column, std::list<Product*>& products, MessageReader& msg_body) {
    column = msg_body.getIntField("column");
    int n_products = msg_body.getObjectArraySize("products");
    for (int index = 0; index < n_products; index++) {
        Product* product = new Product();
        if (msg_body.getObjectFromArray("products", product, index)) {
            products.push_back(product);
        }

    }
}

void GameMessageReader::readCombinationEffectsMsg(std::list<CombinationEffect*>& effects, MessageReader& msg_body) {
    int n_effects = msg_body.getObjectArraySize("effects");
    for (int index = 0; index < n_effects; index++) {
        Json::Value effect_value;
        msg_body.getObjectFromArray("effects", effect_value, index);
        CombinationEffect* effect = effects_factory->getCombinationEffect(effect_value["type"].asString());
        msg_body.getObjectFromArray("effects", effect, index);
        effects.push_back(effect);
    }
}
