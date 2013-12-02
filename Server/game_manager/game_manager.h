/*
 * game_manager.h
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

#ifndef GAME_MANAGER_H_
#define GAME_MANAGER_H_

#include "../../libs/position/position.h"
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
#include "../../libs/level_reader/level_reader.h"

#include <string>
#include <list>

class GameManager {
private:
    Room* room;
    LevelReader* level_reader;  //TODO puntero o referencia?

    // Tableros lógicos
    Board board;
    Board replacements_board;
    // Reemplazos
    Refiller refiller;
    ReplacementsGenerator replacements_generator;

    // Checkers
    PhysicalChecker physical_checker;
    CombinationChecker combination_checker;
    Combiner combiner;

    ScoreTracker score_tracker;

    GameMessageBuilder msg_builder;

public:
    GameManager(Room* room, LevelReader* level_reader);
    void configure();
    bool addPlayer(std::string user_id);
    void makeSwap(Position position1, Position position2, std::string user_id);

private:
    /* Configura los tableros (tamaño y esquema) según los datos del nivel */
    void configureBoards();
    /* Configura el generador de reemplazos según los datos del nivel */
    void configureReplacementsGenerator();

    /* Verifica si el cambio entre esas dos posiciones es válido */
    bool checkSwap(Position position1, Position position2);

    /* Verifica si hay combinación con el cambio de las dos posiciones *
     * De ser así, hace el cambio de productos en el tablero           */
    bool checkCombination(Position position1, Position position2);
};

#endif /* GAME_MANAGER_H_ */
