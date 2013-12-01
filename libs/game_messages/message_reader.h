/*
 * message_reader.h
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

#ifndef MESSAGE_READER_H_
#define MESSAGE_READER_H_

#include "json_deserializer.h"
#include "interface_json_serializable.h"

#include <jsoncpp/json.h>
#include <string>
#include <vector>
#include <list>

class MessageReader {
private:
    Json::Value message;
    JsonDeserializer deserializer;

public:
    bool processNewMessage(std::string& message_string);
    std::string getMessageHeader();
    std::string getStringField(std::string key);
    int getIntField(std::string key);
    void getObjectField(std::string key, IJsonSerializable* buffer);
    void getObject(std::string key, Json::Value& value,bool get_root = false);
    void getObjectWithKey(std::string key, Json::Value& value);
    bool getObjectFromArray(std::string key, Json::Value& value, int index);
    int getObjectArraySize(std::string key);
};


#endif /* MESSAGE_READER_H_ */
