/*
 * change_product_effect.h
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

#ifndef CHANGE_PRODUCT_EFFECT_H_
#define CHANGE_PRODUCT_EFFECT_H_

#include "combination_effect.h"

#include "../position/position.h"
#include "../boards/product.h"
#include "../game_messages/interface_json_serializable.h"

#include <vector>
#include <jsoncpp/json.h>

/* Clase que representa el efecto de cambiar un producto a otro del mismo *
 * color y distinto tipo, como resultado de una combinación               */
class ChangeProductEffect : public CombinationEffect {
private:
    int color;
    int new_type;
public:
    ChangeProductEffect()
        : CombinationEffect(), color(Product::NO_COLOR), new_type(Product::NO_TYPE) {}
    ChangeProductEffect(Position origin, int color, int new_type)
        : CombinationEffect(origin), color(color), new_type(new_type) {}
    void applyEffect() {std::cout << "ChangeProductEffect" << std::endl; setApplied();}
    std::vector<Position> getChangedProducts();
    std::vector<int> getNewProductsTypes();
    std::vector<Position> getEliminatedProducts() {return std::vector<Position>();}
    void serialize(Json::Value& root);
    void deserialize(Json::Value& root);
    ~ChangeProductEffect() {}
};

#endif /* CHANGE_PRODUCT_EFFECT_H_ */
