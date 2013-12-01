/*
 * score_tracker.h
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

#ifndef SCORE_TRACKER_H_
#define SCORE_TRACKER_H_

#include <string>
#include <map>

class ScoreTracker {
private:
    std::map <std::string, int> scores;
    int n_players;
    int goal_score;
    std::string lead_player;

public:
    ScoreTracker()
        : n_players(0), goal_score(-1) {}
    ScoreTracker(int goal_score)
        : n_players(0), goal_score(goal_score) {}
    bool addPlayer(std::string user_id);
    void removePlayer(std::string user_id);
    int getNumberOfPlayers();
    int getGoalScore();
    void setGoalScore(int goal_score);
    int getPlayerScore(std::string user_id);
    int addToPlayerScore(std::string user_id, int score);
    bool setPlayerScore(std::string user_id, int score);
    bool goalScoreReached();
    std::string getLeadPlayer();

private:
    void calculateLeadPlayer();
};

#endif /* SCORE_TRACKER_H_ */
