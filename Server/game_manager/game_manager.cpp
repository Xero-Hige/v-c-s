/*
 * game_manager.cpp
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

#include "game_manager.h"

#include "../../libs/boards/product.h"
#include "../../libs/boards/tile.h"
#include "../../libs/boards/board.h"
#include "../../libs/boards/refiller.h"
#include "../../libs/boards/product_generator.h"
#include "../../libs/boards/replacements_generator.h"
#include "../../libs/checkers/physical_checker.h"
#include "../../libs/checkers/combination_checker.h"
#include "../../libs/combiner/combiner.h"  //FIXME cuando se saque el combiner del cliente y de libs, y se pase al server, hay que arreglar este include
#include "../../libs/score_tracker/score_tracker.h"
#include "../../libs/game_messages/game_message_builder.h"
#include "../rooms/Room.h"
#include "../../libs/game_messages/json_serializer.h"

#include <string>
#include <list>
#include <vector>
#include <map>

#include <iostream> //FIXME borrar

using std::string;
using std::list;
using std::vector;
using std::map;

GameManager::GameManager(Room* room, LevelReader* level_reader)
    : combiner(board) {
    this->room = room;
    this->level_reader = level_reader;
    refiller = Refiller(&board, &replacements_board);
}

void GameManager::configure() {
    configureBoards();
    configureReplacementsGenerator();
    setInitialProducts();
    refill(false);
    score_tracker.setGoalScore(level_reader->getGoalScore());
}

bool GameManager::addPlayer(std::string user_id) {
    return score_tracker.addPlayer(user_id);
}

void GameManager::removePlayer(std::string user_id) {
    score_tracker.removePlayer(user_id);
}

//TODO comunicación! Mandarle a los clientes los resultados y eso
void GameManager::makeSwap(Position position1, Position position2, string user_id) {
    // Chequeo físico
    if (! checkSwap(position1, position2)) {
//        return false;
        return;
    }
    // Chequeo de combinación
    if (! checkCombination(position1, position2)) {
//        return false;
        return;
    }
    list<CombinationEffect*> effects = combiner.makeCombinations(position1, position2);
    do {
        std::cout << "Combinación hecha" << std::endl;
        //TODO mandar los CombinationEffects (hecho, probarlo)
        string combination_effects_msg = msg_builder.buildCombinationEffectsMsg(effects);
        room->notifyClients(combination_effects_msg);
        /////////////////////////////////////////////////////////////////////////////////
        int combination_score = combiner.getLastCombinationsPoints();
        score_tracker.addToPlayerScore(user_id, combination_score);
        std::cout << "Añadidos " << combination_score << " puntos al jugador " << user_id << std::endl;
        //TODO mandar el puntaje (hecho, probarlo) y si ganó algún jugador, terminar la partida (ver método de Room)
        string score_update_msg = msg_builder.buildScoreUpdateMsg(user_id, score_tracker.getPlayerScore(user_id));
        room->notifyClients(score_update_msg);
        if (score_tracker.goalScoreReached()) {
            // Terminó la partida
            std::cout << "Terminó la partida" << std::endl;
            room->endMatch();
        }
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////
        std::cout << "Generando productos de relleno" << std::endl;
        refill();
        std::cout << "Reordenando tableros" << std::endl;
        refiller.realocateBoard();
        std::cout << "Chequeando combinaciones encadenadas" << std::endl;
        effects = combiner.makeChainedCombinations();
    } while (effects.size() > 0);
}

void GameManager::getSerializedBoardProducts(std::string& serialized_products) {
    board.serializeProducts(serialized_products);
}

void GameManager::getSerializedReplacementProducts(std::string& serialized_products) {
    replacements_board.serializeProducts(serialized_products);
}

void GameManager::configureBoards() {
    board = Board(level_reader->getBoardHeight(), level_reader->getBoardWidth());
    replacements_board = Board(level_reader->getBoardHeight(), level_reader->getBoardWidth());
    physical_checker = PhysicalChecker(board);
    combination_checker = CombinationChecker(&board);
    vector<vector<int> > schema;
    level_reader->getBoardSchema(schema);
    board.setSchema(schema);
    replacements_board.setSchema(schema);
}

void GameManager::setInitialProducts() {
//    list<Product*> products;
//    level_reader->getInitialProducts(products);
//    list<Product*>::iterator it;
//    for (int x = 0; x < board.getWidth(); x++) {
//        for (int y = 0; y < board.getHeight(); y++) {
//            if (board.getTileType(x,y) == Tile::HOLE) {
//                continue;
//            }
//            board.setProduct((*it), x, y);
//            ++it;
//        }
//    }
    for (int x = 0; x < board.getWidth(); x++) {
        for (int y = 0; y < board.getHeight(); y++) {
            if (board.getTileType(x, y) == Tile::CELL) {
                //                int color = rand()%5;
                //                int type = rand()%3;
                //                Product* product = new Product(color, type);
                //                Product* replacement = new Product(color, type);
                //FIXME
                int color = y%5;
                Product* product = new Product(color, Product::BUTTON);
                board.setProduct(product, x, y);
//                Product* replacement = new Product(color, Product::BUTTON);
//                replacements_board.setProduct(replacement, x, y);
            }
        }
    }
}

void GameManager::configureReplacementsGenerator() {
    // Seteo de la tabla de conversión de los ProductGenerator
    map<string, unsigned int> convertion_table;
    convertion_table["red"] = Product::RED;
    convertion_table["yellow"] = Product::YELLOW;
    convertion_table["green"] = Product::GREEN;
    convertion_table["blue"] = Product::BLUE;
    convertion_table["violet"] = Product::VIOLET;
    ProductGenerator::setConvertionTable(convertion_table);
    // Seteo del ReplacementsGenerator
    vector<ProductGenerator*> product_generators;
    for (int column = 0; column < replacements_board.getWidth(); column++) {
        map<string, int> probabilities_table;
        level_reader->getProbabilitiesTable(column, probabilities_table);
        ProductGenerator* product_generator = new ProductGenerator(probabilities_table);
        product_generators.push_back(product_generator);
    }
    replacements_generator = ReplacementsGenerator(&replacements_board, product_generators);
}

bool GameManager::checkSwap(Position position1, Position position2) {
    return physical_checker.checkSwap(position1, position2);
}

bool GameManager::checkCombination(Position position1, Position position2) {
    board.swapProducts(position1, position1);
    if (combination_checker.check(position1) || combination_checker.check(position1)) {
        return true;
    }
    board.swapProducts(position1, position1);
    return false;
}

void GameManager::refill(bool send) {
    for (int column = 0; column < replacements_board.getWidth(); column++) {
        int empty_cells = replacements_board.getEmptyCellsInColumn(column);
        if (empty_cells > 0) {
            list<Product*> replacements = replacements_generator.getReplacements(empty_cells, column);
            if (send) {
                //TODO mandar los reemplazos (hecho, probarlo)
                string product_refill_msg = msg_builder.buildProductRefill(column, replacements);
                room->notifyClients(product_refill_msg);
                //////////////////////////////////////////////
            }
            refiller.addReplacements(column, replacements);
        }
    }
}
