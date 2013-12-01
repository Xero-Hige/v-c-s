/*
 * game_message_builder.cpp
 *
 * Created on: Nov 30, 2013
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

#include "interface_json_serializable.h"

#include <jsoncpp/json.h>
#include <string>
#include <vector>
#include <list>

using std::string;
using std::vector;
using std::list;

void GameMessageBuilder::startNewMessage() {
    message = Json::Value();
}

void GameMessageBuilder::addStringField(string key, string value) {
    message[key] = value;
}

void GameMessageBuilder::addIntField(string key, int value) {
    message[key] = value;
}

void GameMessageBuilder::addObjectField(string key, IJsonSerializable* value) {
    Json::Value object;
    value->serialize(object);
    message[key] = object;
}

void GameMessageBuilder::addObjectArrayField(string key, vector<IJsonSerializable*>& value) {
    Json::Value value_array = Json::Value(Json::arrayValue);
    vector<IJsonSerializable*>::iterator it;
    for (it = value.begin(); it != value.end(); ++it) {
        Json::Value object;
        (*it)->serialize(object);
        value_array.append(object);
    }
    message[key] = value_array;
}

void GameMessageBuilder::addObjectArrayField(string key, list<IJsonSerializable*>& value) {
    Json::Value value_array = Json::Value(Json::arrayValue);
    list<IJsonSerializable*>::iterator it;
    for (it = value.begin(); it != value.end(); ++it) {
        Json::Value object;
        (*it)->serialize(object);
        value_array.append(object);
    }
    message[key] = value_array;
}

string GameMessageBuilder::getParsedMessage() {
    return message.toStyledString();
}
