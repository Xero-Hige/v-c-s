/*
 * level_reader.h
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

#ifndef LEVEL_READER_H_
#define LEVEL_READER_H_

#include "../boards/tile.h"
#include "../boards/product.h"

#include <jsoncpp/json.h>
#include <string>
#include <vector>
#include <list>
#include <map>

class LevelReader {
private:
    Json::Value level_data;

public:
    /* Solo se usa como dummy, no queda de forma válida ni usable         *
     * Si se usa, todos los métodos devolveran valores inválidos según el *
     * campo, o tendrán valores inesperados                               */
    LevelReader() { level_data["valid"] = false; }
    explicit LevelReader(std::string& input_data);
    void changeLevelData(std::string& input_data);
    int getLevelNumber();
    int getGoalScore();
    int getNumberOfPlayers();

    int getBoardWidth();
    int getBoardHeight();
    void getBoardSchema(std::vector<std::vector<int> >& schema);
    void getInitialProducts(std::list<Product*>& products);

    bool getProbabilitiesTable(int column, std::map<std::string, int>& probabilities_table);
};

#endif /* LEVEL_READER_H_ */
