/*
 * message_builder.cpp
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

#include "message_builder.h"

#include "json_serializer.h"
#include "interface_json_serializable.h"

#include <jsoncpp/json.h>
#include <string>
#include <vector>
#include <list>

using std::string;
using std::vector;
using std::list;

void MessageBuilder::startNewMessage(string header) {
    message = Json::Value();
    message["header"] = header;
    serializer.startNewObject();
}

void MessageBuilder::addStringField(string key, string value) {
    serializer.addStringField(key, value);
}

void MessageBuilder::addIntField(string key, int value) {
    serializer.addIntField(key, value);
}

void MessageBuilder::addObjectField(string key, IJsonSerializable* value) {
    serializer.addObjectField(key, value);
}

void MessageBuilder::addObjectArrayField(string key, vector<IJsonSerializable*>& value) {
    serializer.addObjectArrayField(key, value);
}

void MessageBuilder::addObjectArrayField(string key, list<IJsonSerializable*>& value) {
    serializer.addObjectArrayField(key, value);
}

string MessageBuilder::getParsedMessage() {
    message["body"] = serializer.getObject();
    return message.toStyledString();
}
