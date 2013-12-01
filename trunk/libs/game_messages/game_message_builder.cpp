/*
 * game_message_builder.cpp
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

#include "game_message_builder.h"

#include "message_builder.h"
#include "interface_json_serializable.h"
#include "../position/position.h"
#include "../boards/product.h"
#include "../combination_effects/combination_effect.h"

#include <string>
#include <vector>
#include <list>

using std::string;
using std::vector;
using std::list;


string GameMessageBuilder::buildScoreUpdateMsg(string user_id, int score) {
    msg_builder.startNewMessage("score update");
    msg_builder.addStringField("user id", user_id);
    msg_builder.addIntField("score", score);
    return msg_builder.getParsedMessage();
}

string GameMessageBuilder::buildGameOverMsg(string user_id) {
    msg_builder.startNewMessage("game over");
    msg_builder.addStringField("user id", user_id);
    return msg_builder.getParsedMessage();
}

string GameMessageBuilder::buildSwapMessage(string user_id, Position position1, Position position2) {
    msg_builder.startNewMessage("swap");
    msg_builder.addStringField("user id", user_id);
    msg_builder.addObjectField("position 1", &position1);
    msg_builder.addObjectField("position 2", &position2);
    return msg_builder.getParsedMessage();
}

string GameMessageBuilder::buildProductRefill(int column, list<Product*>& products) {
    msg_builder.startNewMessage("product refill");
    msg_builder.addIntField("column", column);
    msg_builder.addObjectArrayField("products", (list<IJsonSerializable*>&)products);
    return msg_builder.getParsedMessage();
}

string GameMessageBuilder::buildCombinationEffectsMsg(list<CombinationEffect*>& effects) {
    msg_builder.startNewMessage("combination effects");
    msg_builder.addObjectArrayField("effects", (list<IJsonSerializable*>&)effects);
    return msg_builder.getParsedMessage();
}
