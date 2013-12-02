/*
 * score_tracker.cpp
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

#include "score_tracker.h"

#include <string>
#include <map>

using std::string;
using std::map;

bool ScoreTracker::addPlayer(string user_id) {
    if (scores.find(user_id) != scores.end()) {
        return false;
    }
    scores[user_id] = 0;
    n_players++;
    return true;
}

void ScoreTracker::removePlayer(string user_id) {
    if (scores.erase(user_id) != 0) {
        if (user_id == lead_player) {
            calculateLeadPlayer();
        }
        n_players--;
    }
}

int ScoreTracker::getNumberOfPlayers() {
    return n_players;
}

int ScoreTracker::getGoalScore() {
    return goal_score;
}

void ScoreTracker::setGoalScore(int goal_score) {
    this->goal_score = goal_score;
}

int ScoreTracker::getPlayerScore(string user_id) {
    if (scores.find(user_id) == scores.end()) {
        return -1;
    }
    return scores[user_id];
}

int ScoreTracker::addToPlayerScore(string user_id, int score) {
    if (scores.find(user_id) == scores.end()) {
        return -1;
    }
    scores[user_id]+= score;
    if (scores[user_id] > scores[lead_player]) {
        lead_player = user_id;
    }
    return scores[user_id];
}

bool ScoreTracker::setPlayerScore(string user_id, int score) {
    if (scores.find(user_id) == scores.end()) {
        return false;
    }
    scores[user_id] = score;
    if (user_id == lead_player) {
        calculateLeadPlayer();
    }
    return true;
}

bool ScoreTracker::goalScoreReached() {
    if (lead_player == string()) {
        calculateLeadPlayer();
    }
    return (scores[lead_player] >= goal_score);
}

string ScoreTracker::getLeadPlayer() {
    if (lead_player == string()) {
        calculateLeadPlayer();
    }
    return lead_player;
}

void ScoreTracker::calculateLeadPlayer() {
    map<string, int>::iterator it = scores.begin();
    string current_lead_player = (*it).first;
    while (it != scores.end()) {
        if (scores[current_lead_player] < (*it).second) {
            current_lead_player = (*it).first;
        }
        ++it;
    }
    lead_player = current_lead_player;
}
