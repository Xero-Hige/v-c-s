/*
 * combination_effects_factory.h
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

#ifndef COMBINATION_EFFECTS_FACTORY_H_
#define COMBINATION_EFFECTS_FACTORY_H_

#include "../combination_effects/combination_effect.h"
#include "../combination_effects/change_product_effect.h"
#include "../combination_effects/clean_board_effect.h"
#include "../combination_effects/take_out_column_effect.h"
#include "../combination_effects/take_out_product_effect.h"
#include "../combination_effects/take_out_row_effect.h"

#include <string>

class CombinationEffectsFactory {
public:
    CombinationEffect* getCombinationEffect(std::string type);
};


#endif /* COMBINATION_EFFECTS_FACTORY_H_ */
