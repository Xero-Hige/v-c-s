/*
 * game_message_reader.h
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

#ifndef GAME_MESSAGE_READER_H_
#define GAME_MESSAGE_READER_H_

#include "message_reader.h"
#include "interface_json_serializable.h"
#include "../position/position.h"
#include "../boards/product.h"
#include "../combination_effects/combination_effect.h"
#include "combination_effects_factory.h"
#include "game_msg_constants.h"

#include <string>
#include <vector>
#include <list>

class GameMessageReader {
    CombinationEffectsFactory* effects_factory;
public:
    GameMessageReader() {effects_factory = new CombinationEffectsFactory();}
    GameMessageReader(CombinationEffectsFactory* effects_factory)
        : effects_factory(effects_factory) {}
    void readScoreUpdateMsg(std::string& user_id, int& score, MessageReader& msg_body);
    void readGameOverMsg(std::string& user_id, MessageReader& msg_body);
    void readSwapMessage(std::string& user_id, Position& position1, Position& position2, MessageReader& msg_body);
    void readProductRefill(int& column, std::list<Product*>& products, MessageReader& msg_body);
    void readCombinationEffectsMsg(std::list<CombinationEffect*>& effects, MessageReader& msg_body);
    ~GameMessageReader() {delete effects_factory;}
};

#endif /* GAME_MESSAGE_READER_H_ */
