/**
 backend.cpp

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

#include "backend.h"

#include "../../libs/boards/board.h"
#include "../../libs/boards/tile.h"
#include "../../libs/boards/product.h"
#include "../../libs/checkers/combination_checker.h"
#include "../../libs/checkers/physical_checker.h"
#include "../../libs/level_reader/level_reader.h"

#include <stddef.h>
#include <cstdlib> //TODO sacar

#include <iostream> // FIXME borrame
#include "info_nivel.h" // FIXME borrame
#include "../../libs/combiner/combiner.h" // FIXME borrame

using std::string;
using std::vector;
using std::list;

Backend::Backend() {

	ip="";
	port=0;

	logged=false;
	user_nick="";
	user_pass="";

	_operation_ended = true;
	_operation_error = "";
}

void Backend::async_connect(const std::string& ip,int port){
	this->server_connector.makeConnection(ip, port);
}

bool Backend::logged_in(){
	return logged;
}

bool Backend::operation_ended() {
	return _operation_ended;
}

void Backend::setOperationEnded(bool b){
	this->_operation_ended = b;
}
void Backend::setLogged(bool b){
	this->logged = b;
}

string Backend::operation_error() {
	return _operation_error;
}

void Backend::async_log_in
(const std::string& user,const std::string& password,int auth_type){
    //FIXME lo comenté porque se rompía
//	this->server_connector.connectServer(user, password, "1");
}
Backend::~Backend() {
	// TODO Auto-generated destructor stub
}

void Backend::configureBoards() {
    board = Board(level_reader.getBoardHeight(), level_reader.getBoardWidth());
    replacements_board = Board(level_reader.getBoardHeight(), level_reader.getBoardWidth());
    physical_checker = PhysicalChecker(board);
    combination_checker = CombinationChecker(&board);
}

vector<string> Backend::get_board_pokemon_codes() {
	vector<string> codes;
	codes.push_back("001");
	codes.push_back("025");
	codes.push_back("108");
	codes.push_back("156");
	codes.push_back("197");

	return codes;
}

std::vector<std::vector<int> > Backend::get_full_board() {
    //TODO esto no va acá, hay que acomodarlo donde corresponda
    asyncSetUpInitialProducts();
    ///////////////////////////////////////////////////////////
    // Los tableros tienen el mismo esquema, así que las cosas físicas se
    // toman y chequean de uno, pero también es válido para el otro
	vector<vector<int> > products;
	for (int x = 0; x < board.getWidth(); x++) {
		vector<int> column;
		column.resize(board.getHeight()*2);
		for (int y = 0; y < board.getHeight(); y++) {
		    int product_code;
		    int replacement_code;
			if (board.getTileType(x, y) == Tile::CELL){
				product_code = getProductCode(board, x, y);
				replacement_code = getProductCode(replacements_board, x, y);
			}
			else
			{
				product_code = replacement_code = -1;
			}
	        // Tablero de reemplazos
			column[y] = replacement_code;
	        // Tablero de juego
			column[y+board.getHeight()] = product_code;
		}
		products.push_back(column);
	}

	return products;
}

bool Backend::poolEffect() {
    return false;
}

vector<Position> Backend::get_removed_pokemons() {
    return products_to_remove;
//	Position a=l[0];
//	Position b=l[1];
//
//	int x_a = a[0];
//	int x_b = b[0];
//
//	int y_a = a[1];
//	int y_b = b[1];
//
//	//TODO:
//	vector<Position> res;
//	res.push_back(Position(x_a,y_a));
//	res.push_back(Position(x_a,y_a+1));
//	res.push_back(Position(x_a,y_a-1));
//	res.push_back(Position(x_b,y_b));
//	res.push_back(Position(x_b,y_b+1));
//	res.push_back(Position(x_b,y_b-1));
//
//	return res;
}

Position Backend::getEffectOrigin() {
    return Position(-1,-1);
}

int Backend::getEffectAnimation() {
    return 0;
}

void Backend::async_get_room() {
	_operation_ended = true;
}

vector<vector<int> > Backend::get_board_schema() {
    // FIXME Esto no va acá, hay que llamarlo al final de la screen de room o al princio del screen de level
    asyncGetLevelSpecification();
    configureBoards();
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    vector<vector<int> > schema = level_reader.getBoardSchema();
    // TODO Esto no me gusta acá, habría que ver donde/como se puede poner. Dónde se configuran los tableros (configureBoards)??
    board.setSchema(schema);
    replacements_board.setSchema(schema);
    return schema;
}

bool Backend::async_make_swap(Position pos1_graphic, Position pos2_graphic) {
    //TODO lo que sea lanzar thread y/o comunicarse con el server
    l[0] = pos1_graphic;
    l[1] = pos2_graphic;
    Position pos1_logic = graphicToLogicPos(pos1_graphic);
    Position pos2_logic = graphicToLogicPos(pos2_graphic);
    // Chequeo físico
    if (! checkSwap(pos1_logic, pos2_logic)) {
        return false;
    }
    // Chequeo de combinación
    if (! checkCombination(pos1_logic, pos2_logic)) {
        std::cout << "No hay combinación en las posiciones (" << pos1_logic.getX() << "," << pos1_logic.getY();
        std::cout << ") y (" << pos2_logic.getX() << "," << pos2_logic.getY() << ")" << std::endl;
        return false;
    }
    //TODO esto va en el server y/o otro lado
    Combiner combiner = Combiner(board);
    list<CombinationEffect> effects = combiner.makeCombinations(pos1_logic, pos2_logic);
    combination_effects_queue.splice(combination_effects_queue.end(), effects);
    std::cout << "Puntos obtenidos en el último movimiento: " << combiner.getLastCombinationsPoints() << std::endl;
    std::cout << "Efectos a aplicar: " << combination_effects_queue.size() << std::endl;
    /////////////////////////////////////////
    return true;
}

void Backend::asyncGetLevelSpecification() {
    //TODO Que ande en serio
    string level_data = getLevelData();
    level_reader.changeLevelData(level_data);
}

void Backend::asyncSetUpInitialProducts() {
    //TODO que en serio lo pida al server, no que lo invente acá
    for (int x = 0; x < board.getWidth(); x++) {
        for (int y = 0; y < board.getHeight(); y++) {
            //TODO Pedirlo a board y a replacements_board en lugar de inventarlo acá
            if (board.getTileType(x, y) == Tile::CELL){
//                int color = rand()%5;
//                int type = rand()%3;
//                Product* product = new Product(color, type);
//                Product* replacement = new Product(color, type);
                //FIXME
                int color = y%5;
                Product* product = new Product(color, Product::BUTTON);
                board.setProduct(product, x, y);
                Product* replacement = new Product(color, Product::BUTTON);
                replacements_board.setProduct(replacement, x, y);
            }
        }
    }
}

bool Backend::checkSwap(Position pos1_logic, Position pos2_logic) {
    return physical_checker.checkSwap(pos1_logic, pos2_logic);
}

bool Backend::checkCombination(Position pos1_logic, Position pos2_logic) {
    board.swapProducts(pos1_logic, pos2_logic);
    if (combination_checker.check(pos1_logic) || combination_checker.check(pos2_logic)) {
        return true;
    }
    board.swapProducts(pos1_logic, pos2_logic);
    return false;
}

Position Backend::graphicToLogicPos(Position& pos_graphic) {
    int x = pos_graphic.getX();
    int y = pos_graphic.getY() % board.getHeight();
    return Position(x, y);
}

int Backend::getProductCode(Board& board, int x, int y) {
    int color = board.getProductColor(x, y);
    int type = board.getProductType(x, y);
    if (type == Product::STAR) {
        return (Product::N_COLORS * (Product::N_TYPES-1) + 1);
    }
    return (color*(Product::N_TYPES-1) + type + 1);
}
