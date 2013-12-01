/*
 * combination_effect.cpp
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

#include "combination_effect.h"

#include "../game_message_builder/interface_json_serializable.h"

#include <jsoncpp/json.h>

bool CombinationEffect::isApplied() {
    return applied;
}
void CombinationEffect::setApplied() {
    applied = true;
}

Position CombinationEffect::getOrigin() {
    return origin;
}

void CombinationEffect::serialize(Json::Value& root) {
    Json::Value origin_value;
    origin.serialize(origin_value);
    root["origin"] = origin_value;
}
void CombinationEffect::deserialize(Json::Value& root) {
    Json::Value origin_value = root["origin"];
    origin.deserialize(origin_value);
}
