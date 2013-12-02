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

#ifndef LEVELBUILDER_H_
#define LEVELBUILDER_H_

#include <string>
#include <vector>

class LevelBuilder {

private:
	int columns;
	int rows;
	std::string level_name;
	std::string background_file;
	int win_points;
	int max_players;
	std::vector<std::string> cell_files;

private:
	std::vector<std::vector<int> > board_schema;

public:
	LevelBuilder();
	virtual ~LevelBuilder();

	void setBoardSchema(std::vector<std::vector<int> > board_schema);
	void setName(std::string name);
	void setBackgroundFile(std::string file);
	void setWinPoints(int points);
	void setMaxPlayers(int players);
	void setColumns(int columns);
	void setRows(int rows);
	void setCellFiles(std::vector<std::string> files);

	std::vector<std::vector<int> >& getBoardSchema();
	std::string getName();
	std::string getBackgroundFile();
	int getWinPoints();
	int getMaxPlayers();
	int getColumns();
	int getRows();
	std::vector<std::string> getCellFiles();
};

#endif /* LEVELBUILDER_H_ */
