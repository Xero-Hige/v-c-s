/*
 * combination_effect.h
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

#ifndef COMBINATION_EFFECT_H_
#define COMBINATION_EFFECT_H_

#include "../position/position.h"

/* Clase base para los efectos a aplicar como resultado de una combinación */
class CombinationEffect {
protected:
    Position origin;
public:
    CombinationEffect(Position origin)
        : origin(origin) {}
    //TODO ver bien que pasarle de parámetro y si tiene que devolver algo (Gaston si ves esto, con vos tengo que hablarlo =P)
    virtual void applyEffect() = 0;
    virtual ~CombinationEffect();
};

#endif /* COMBINATION_EFFECT_H_ */
