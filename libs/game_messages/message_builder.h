/*
 * message_builder.h
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

#ifndef MESSAGE_BUILDER_H_
#define MESSAGE_BUILDER_H_

#include "json_serializer.h"
#include "interface_json_serializable.h"

#include <jsoncpp/json.h>
#include <string>
#include <vector>
#include <list>

class MessageBuilder {
private:
    Json::Value message;
    JsonSerializer serializer;

public:
    void startNewMessage(std::string header);
    void addStringField(std::string key, std::string value);
    void addIntField(std::string key, int value);
    void addObjectField(std::string key, IJsonSerializable* value);
    void addObjectArrayField(std::string key, std::vector<IJsonSerializable*>& value);
    void addObjectArrayField(std::string key, std::list<IJsonSerializable*>& value);
    std::string getParsedMessage();
};

#endif /* MESSAGE_BUILDER_H_ */
