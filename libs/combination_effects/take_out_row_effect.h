/*
 * take_out_row_effect.h
 *
 * Created on: Nov 24, 2013
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

#ifndef TAKE_OUT_ROW_EFFECT_H_
#define TAKE_OUT_ROW_EFFECT_H_

#include "combination_effect.h"

#include "../position/position.h"
#include "../game_messages/interface_json_serializable.h"

#include <vector>
#include <jsoncpp/json.h>

/* Clase que representa la eliminación de una fila debido a una *
 * barra horizontal o una combinación estrella+barra            */
class TakeOutRowEffect : public CombinationEffect {
private:
    int board_width;
public:
    TakeOutRowEffect()
        : CombinationEffect(), board_width(-1) {}
    TakeOutRowEffect(Position origin, int board_width)
        : CombinationEffect(origin), board_width(board_width) {}
    void applyEffect(Board& board);
    std::vector<Position> getEliminatedProducts();
    void serialize(Json::Value& root);
    void deserialize(Json::Value& root);
    ~TakeOutRowEffect() {}
};

#endif /* TAKE_OUT_ROW_EFFECT_H_ */
