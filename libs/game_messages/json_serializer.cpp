/*
 * json_serializer.cpp
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

#include "json_serializer.h"

#include "interface_json_serializable.h"

#include <jsoncpp/json.h>
#include <string>
#include <vector>
#include <list>

using std::string;
using std::vector;
using std::list;

void JsonSerializer::startNewObject() {
    object = Json::Value();
}

void JsonSerializer::addStringField(string key, string value) {
    object[key] = value;
}

void JsonSerializer::addIntField(string key, int value) {
    object[key] = value;
}

void JsonSerializer::addObjectField(string key, IJsonSerializable* value) {
    Json::Value object;
    value->serialize(object);
    this->object[key] = object;
}

void JsonSerializer::addObjectArrayField(string key, vector<IJsonSerializable*>& value) {
    Json::Value value_array = Json::Value(Json::arrayValue);
    vector<IJsonSerializable*>::iterator it;
    for (it = value.begin(); it != value.end(); ++it) {
        Json::Value object;
        (*it)->serialize(object);
        value_array.append(object);
    }
    this->object[key] = value_array;
}

void JsonSerializer::addObjectArrayField(string key, list<IJsonSerializable*>& value) {
    Json::Value value_array = Json::Value(Json::arrayValue);
    list<IJsonSerializable*>::iterator it;
    for (it = value.begin(); it != value.end(); ++it) {
        Json::Value object;
        (*it)->serialize(object);
        value_array.append(object);
    }
    this->object[key] = value_array;
}

Json::Value JsonSerializer::getObject() {
    return object;
}

string JsonSerializer::getParsedObject() {
    return object.toStyledString();
}
