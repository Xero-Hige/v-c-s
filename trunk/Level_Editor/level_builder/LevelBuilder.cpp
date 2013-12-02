/**
 LevelBuilder.h

 Copyright 2013 Gaston Martinez Gaston.martinez.90@gmail.com

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses
 */

#include "LevelBuilder.h"

#include <string>

using std::string;
using std::vector;

LevelBuilder::LevelBuilder():win_points(0),columns(0),rows(0),max_players(0){}

LevelBuilder::~LevelBuilder() {}

void LevelBuilder::setBoardSchema(std::vector<std::vector<int> > board_schema) {
	this->board_schema = board_schema;

	vector<int> values;
	for (int i=0;i<5;i++)
	{
		values.push_back(1);
	}

	for (size_t i=0;i<board_schema.size();i++)
	{
		board_values.push_back(vector<vector<int> >());
		for (size_t j=0;j<board_schema[i].size();j++)
		{
			board_values[i].push_back(values);
		}
	}
}

vector<vector<int> >& LevelBuilder::getBoardSchema() {
	return this->board_schema;
}

std::string LevelBuilder::getName() {
	return level_name;
}

std::string LevelBuilder::getBackgroundFile() {
	return background_file;
}

int LevelBuilder::getWinPoints() {
	return win_points;
}

int LevelBuilder::getMaxPlayers() {
	return max_players;
}

int LevelBuilder::getColumns() {
	return columns;
}

int LevelBuilder::getRows() {
	return rows;
}

vector<string> LevelBuilder::getCellFiles() {
	return cell_files;
}

void LevelBuilder::setName(std::string name) {
	level_name = name;
}

void LevelBuilder::setBackgroundFile(std::string file) {
	background_file = file;
}

void LevelBuilder::setWinPoints(int points) {
	win_points = points;
}

void LevelBuilder::setMaxPlayers(int players) {
	max_players = players;
}

void LevelBuilder::setColumns(int columns) {
	this->columns = columns;
}

void LevelBuilder::setRows(int rows) {
	this->rows = rows;
}

void LevelBuilder::setCellFiles(std::vector<std::string> files) {
	this->cell_files = files;
}

void LevelBuilder::setProbValues(int x, int y, std::vector<int> values) {
	board_values[x][y] = values;
}

void LevelBuilder::store() {
}
