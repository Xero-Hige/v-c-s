/*
 * message_builder_test.cpp
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

#include "../../vcs/libs/game_message_builder/game_message_builder.h"
#include "../../vcs/libs/game_message_builder/interface_json_serializable.h"

#include <iostream>
#include <string>
#include <vector>
#include <list>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::list;

class TestClass : public IJsonSerializable {
private:
    string a_string;
    int a_int;

public:
    TestClass(string a_string, int a_int)
        :a_string(a_string), a_int(a_int) {}

    void serialize(Json::Value& root) {
        root["a_string"] = a_string;
        root["a_int"] = a_int;
    }

    void deserialize(Json::Value& root) {
        a_string = root["a_string"].asString();
        a_int = root["a_int"].asInt();
    }

    void print() {
        cout << "Cadena: " << a_string << " - Número: " << a_int << endl;
    }
};

int main() {
    GameMessageBuilder msg_builder;
    msg_builder.startNewMessage();
    msg_builder.addStringField("clave cadena", "cadena");
    msg_builder.addIntField("clave int", 0);
    TestClass test_object = TestClass("clave objeto", 0);
    msg_builder.addObjectField("objeto", &test_object);
    vector<IJsonSerializable*> test_vector;
    test_vector.push_back(new TestClass("clave objeto 1", 1));
    test_vector.push_back(new TestClass("clave objeto 2", 2));
    msg_builder.addObjectArrayField("vector", test_vector);
    list<IJsonSerializable*> test_list;
    test_list.push_back(new TestClass("clave objeto 3", 3));
    test_list.push_back(new TestClass("clave objeto 4", 4));
    msg_builder.addObjectArrayField("list", test_list);
    cout << msg_builder.getParsedMessage();
    test_vector.clear();
}
