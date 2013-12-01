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

LevelBuilder::LevelBuilder() {
	// TODO Auto-generated constructor stub

}

LevelBuilder::~LevelBuilder() {
	// TODO Auto-generated destructor stub
}

void LevelBuilder::setBoardSchema(
		std::vector<std::vector<int> > board_schema) {
	this->board_schema = board_schema;
}

vector<vector<int> >& LevelBuilder::getBoardSchema() {
	return this->board_schema;
}

vector<string> LevelBuilder::getCellFiles() {
	vector<string> files;
	files.push_back("cell_A");
	files.push_back("hover_cell_A");
	return files;
}
