/*
 * level_reader.cpp
 *
 * Created on: Nov 18, 2013
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

#include "level_reader.h"

#include "../boards/tile.h"
#include "../boards/product.h"
#include "../boards/product_generator.h"

#include <jsoncpp/json.h>
#include <string>
#include <vector>
#include <list>
#include <map>

#include <iostream> //FIXME

using std::string;
using std::vector;
using std::list;
using std::map;

LevelReader::LevelReader(string& input_data) {
    this->changeLevelData(input_data);
}

void LevelReader::changeLevelData(string& input_data) {
    Json::Reader reader;
    bool parsed = reader.parse(input_data, level_data, false);
    // TODO Chequear si hubo error en el parseo y hacer algo (tirar una excepción?)
    level_data["valid"] = true;
}

int LevelReader::getLevelNumber() {
    if (! level_data["valid"].asBool()) {
        return 0;
    }
    return level_data["level_number"].asInt();
}

int LevelReader::getGoalScore() {
    if (! level_data["valid"].asBool()) {
        return 0;
    }
    return level_data["goal_score"].asInt();
}

int LevelReader::getNumberOfPlayers() {
    if (! level_data["valid"].asBool()) {
        return 0;
    }
    return level_data["number_players"].asInt();
}

int LevelReader::getBoardWidth() {
    if (! level_data["valid"].asBool()) {
        return -1;
    }
    return level_data["board_width"].asInt();
}

int LevelReader::getBoardHeight() {
    if (! level_data["valid"].asBool()) {
        return -1;
    }
    return level_data["board_height"].asInt();
}

void LevelReader::getBoardSchema(std::vector<std::vector<int> >& schema) {
    if (! level_data["valid"].asBool()) {
        schema = vector<vector<int> >();
    }
    int width = getBoardWidth();
    int height = getBoardHeight();
    Json::Value tiles = level_data["tiles"];
    for (int x = 0; x < width; x++) {
        schema.push_back(vector<int>());
    }
    int index = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Json::Value tile = tiles[index];
            if (tile["type"].asString() == "hole") {
                schema[x].push_back(+Tile::HOLE);
            } else {
                schema[x].push_back(+Tile::CELL);
            }
            index++;
        }
    }
}

void LevelReader::getInitialProducts(list<Product*>& products) {
    if (! level_data["valid"].asBool()) {
        products = list<Product*>();
    }
    Json::Value tiles = level_data["tiles"];
    int n_tiles = tiles.size();
    for (int index = 0; index < n_tiles; index++) {
        Json::Value current_tile = tiles[index];
        if (current_tile["type"].asString() == "hole") {
            continue;
        }
        map<string, int> probabilities_table;
        probabilities_table["red"] = current_tile["red"].asInt();
        probabilities_table["yellow"] = current_tile["yellow"].asInt();
        probabilities_table["green"] = current_tile["green"].asInt();
        probabilities_table["blue"] = current_tile["blue"].asInt();
        probabilities_table["violet"] = current_tile["violet"].asInt();
        ProductGenerator product_generator = ProductGenerator(probabilities_table);
        products.push_back(product_generator.getNewProduct());
    }
}

bool LevelReader::getProbabilitiesTable(int column, map<string, int>& probabilities_table) {
    if (! level_data["valid"].asBool()) {
        return false;
    }
    if (! level_data["columns probabilities"].isValidIndex(column)) {
        return false;
    }
    Json::Value probabilities = level_data["columns probabilities"][column];
    probabilities_table["red"] = probabilities["red"].asInt();
    probabilities_table["yellow"] = probabilities["yellow"].asInt();
    probabilities_table["green"] = probabilities["green"].asInt();
    probabilities_table["blue"] = probabilities["blue"].asInt();
    probabilities_table["violet"] = probabilities["violet"].asInt();
    return true;
}
