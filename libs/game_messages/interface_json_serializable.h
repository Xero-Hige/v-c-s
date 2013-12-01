/*
 * interface_json_serializable.h
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

#ifndef INTERFACE_JSON_SERIALIZABLE_H_
#define INTERFACE_JSON_SERIALIZABLE_H_

#include <jsoncpp/json.h>

/* Interfaz para los objetos que deben serializarse/deserializarse en *
 * formato Json                                                       */
class IJsonSerializable {
public:
    virtual void serialize(Json::Value& root) =0;
    virtual void deserialize(Json::Value& root) =0;
    virtual ~IJsonSerializable() {}
};

#endif /* INTERFACE_JSON_SERIALIZABLE_H_ */
