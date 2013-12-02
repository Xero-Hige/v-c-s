/*
 * take_out_product_effect.h
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

#ifndef TAKE_OUT_PRODUCT_EFFECT_H_
#define TAKE_OUT_PRODUCT_EFFECT_H_

#include "combination_effect.h"

#include "../position/position.h"
#include "../game_messages/interface_json_serializable.h"

#include <vector>
#include <jsoncpp/json.h>

/* Clase que representa la eliminación de un producto simple */
class TakeOutProductEffect : public CombinationEffect {
private:
    Position initial_pos;
    Position ending_pos;

public:
    TakeOutProductEffect()
        : CombinationEffect(), initial_pos(Position()), ending_pos(Position()) {}
    explicit TakeOutProductEffect(Position origin)
        : CombinationEffect(origin) {}
    TakeOutProductEffect(Position origin, Position initial_pos, Position ending_pos)
        : CombinationEffect(origin), initial_pos(initial_pos), ending_pos(ending_pos) {}
    void applyEffect(Board& board);
    std::vector<Position> getEliminatedProducts();
    void serialize(Json::Value& root);
    void deserialize(Json::Value& root);
    ~TakeOutProductEffect() {}
};

#endif /* TAKE_OUT_PRODUCT_EFFECT_H_ */
