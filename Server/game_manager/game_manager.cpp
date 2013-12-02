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

#include <string>
#include <list>
#include <vector>
#include <map>

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
    score_tracker.setGoalScore(level_reader->getGoalScore());
}

bool GameManager::addPlayer(std::string user_id) {
    return score_tracker.addPlayer(user_id);
}

//TODO comunicación! Mandarle a los clientes los resultados y eso
void GameManager::makeSwap(Position position1, Position position2, string user_id) {
    // Chequeo físico
    if (! checkSwap(position1, position2)) {
        return;
//        return false;
    }
    // Chequeo de combinación
    if (! checkCombination(position1, position2)) {
        return;
//        return false;
    }
    list<CombinationEffect*> effects = combiner.makeCombinations(position1, position2);
    do {
        //TODO mandar los CombinationEffects
        int combination_score = combiner.getLastCombinationsPoints();
        score_tracker.addToPlayerScore(user_id, combination_score);
        //TODO chequeo si termino el juego. Hay que cerrar la room?
        //TODO mandar el puntaje, y si ganó algún jugador
        for (int column = 0; column < board.getWidth(); column++) {
            int empty_cells = replacements_board.getEmptyCellsInColumn(column);
            if (empty_cells > 0) {
                list<Product*> replacements = replacements_generator.getReplacements(empty_cells, column);
                //TODO mandar los reemplazos
                refiller.addReplacements(column, replacements);
            }
        }
        refiller.realocateBoard();
        effects = combiner.makeChainedCombinations();
    } while (effects.size() > 0);
//    return true;
}

void GameManager::configureBoards() {
    board = Board(level_reader->getBoardHeight(), level_reader->getBoardWidth());
    replacements_board = Board(level_reader->getBoardHeight(), level_reader->getBoardWidth());
    physical_checker = PhysicalChecker(board);
    combination_checker = CombinationChecker(&board);
    vector<vector<int> > schema = level_reader->getBoardSchema();
    board.setSchema(schema);
    replacements_board.setSchema(schema);
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
        level_reader->getProbabilitiesTable(column, probabilities_table));
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
