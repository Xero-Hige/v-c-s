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

/* Clase que representa el efecto de cambiar un producto a otro del mismo *
 * color y distinto tipo, como resultado de una combinación               */
class ChangeProductEffect : public CombinationEffect {
private:
    int new_type;
public:
    ChangeProductEffect(Position origin, int new_type)
        : CombinationEffect(origin), new_type(new_type) {}
    void applyEffect();
};


#endif /* CHANGE_PRODUCT_EFFECT_H_ */