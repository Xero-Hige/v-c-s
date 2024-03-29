/*
 * game_message_builder.h
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

#ifndef GAME_MESSAGE_BUILDER_H_
#define GAME_MESSAGE_BUILDER_H_

#include "message_builder.h"
#include "interface_json_serializable.h"
#include "../position/position.h"
#include "../boards/product.h"
#include "../combination_effects/combination_effect.h"
#include "game_msg_constants.h"

#include <string>
#include <vector>
#include <list>

class GameMessageBuilder {
private:
    MessageBuilder msg_builder;

public:
    std::string buildScoreUpdateMsg(std::string user_id, int score);
    std::string buildGameOverMsg(std::string user_id);
    std::string buildSwapMessage(std::string user_id, Position position1, Position position2);
    std::string buildProductRefill(int column, std::list<Product*>& products);
    std::string buildCombinationEffectsMsg(std::list<CombinationEffect*>& effects);
};

#endif /* GAME_MESSAGE_BUILDER_H_ */
