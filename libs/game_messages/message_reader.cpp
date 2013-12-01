/*
 * message_reader.cpp
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

#include "message_reader.h"

#include "json_deserializer.h"
#include "interface_json_serializable.h"

#include <jsoncpp/json.h>
#include <string>
#include <vector>
#include <list>

using std::string;
using std::vector;
using std::list;

bool MessageReader::processNewMessage(string& message_string) {
    bool header_parsed;
    JsonDeserializer aux_deserializer;
    header_parsed = aux_deserializer.processNewObject(message_string);
    header = aux_deserializer.getStringField("header");
    bool body_parsed;
    Json::Value body;
    aux_deserializer.getObject("body", body);
    string body_str = body.toStyledString();
    body_parsed = deserializer.processNewObject(body_str);
    return (header_parsed && body_parsed);
}

string MessageReader::getMessageHeader() {
    return header;
}

string MessageReader::getStringField(string key) {
    return deserializer.getStringField(key);
}

int MessageReader::getIntField(string key) {
    return deserializer.getIntField(key);
}

void MessageReader::getObjectField(string key, IJsonSerializable* buffer) {
    deserializer.getObjectField(key, buffer);
}

void MessageReader::getObject(string key, Json::Value& value) {
    deserializer.getObject(key, value);
}

void MessageReader::getObjectWithKey(string key, Json::Value& value) {
    deserializer.getObjectWithKey(key, value);
}

bool MessageReader::getObjectFromArray(string key, Json::Value& value, int index) {
    return deserializer.getObjectFromArray(key, value, index);
}

bool MessageReader::getObjectFromArray(std::string key, IJsonSerializable* value, int index) {
    return deserializer.getObjectFromArray(key, value, index);
}

int MessageReader::getObjectArraySize(string key) {
    return deserializer.getObjectArraySize(key);
}

int MessageReader::getObjectArrayField(string key, vector<IJsonSerializable*>& buffer) {
    return getObjectArrayField(key, buffer);
}

int MessageReader::getObjectArrayField(string key, list<IJsonSerializable*>& buffer) {
    return getObjectArrayField(key, buffer);
}
