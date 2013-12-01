/*
 * json_deserializer.cpp
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

#include "json_deserializer.h"

#include "interface_json_serializable.h"

#include <jsoncpp/json.h>
#include <string>
#include <vector>
#include <list>

using std::string;
using std::vector;
using std::list;

bool JsonDeserializer::processNewObject(string& object_string) {
    Json::Reader reader;
    return reader.parse(object_string, root, false);
}

string JsonDeserializer::getStringField(string key) {
    return root[key].asString();
}

int JsonDeserializer::getIntField(string key) {
    return root[key].asInt();
}

void JsonDeserializer::getObjectField(string key, IJsonSerializable* buffer) {
    buffer->deserialize(root[key]);
}

void JsonDeserializer::getObject(string key, Json::Value& value,bool get_root = false) {
    if (get_root) {
        value = root;
    }
    value = root[key];
}

void JsonDeserializer::getObjectWithKey(std::string key, Json::Value& value) {
    value[key] = root[key];
}

bool JsonDeserializer::getObjectFromArray(std::string key, Json::Value& value, int index) {
    if (! root[key].isValidIndex(index)) {
        return false;
    }
    value = root[key][index];
    return true;
}

int JsonDeserializer::getObjectArraySize(std::string key) {
    return root[key].size();
}
