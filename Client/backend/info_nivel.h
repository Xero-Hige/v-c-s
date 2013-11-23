/*
 * info_nivel.h
 *
 * Created on: Nov 23, 2013
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

#ifndef INFO_NIVEL_H_
#define INFO_NIVEL_H_

#include <string>

std::string getLevelData() {
    std::string ret = "{\
        \"level_number\": 1,\
        \"board_width\": 12,\
        \"board_height\": 12,\
        \"goal_score\": 3,\
        \"number_players\": 2,\
        \"tiles\": [\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
    {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
    {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"hole\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"hole\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"hole\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"hole\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"hole\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"hole\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"hole\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"hole\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"hole\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"hole\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"hole\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
    {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"hole\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"hole\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"hole\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"hole\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
              {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
    {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
    {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
            {\
                \"type\": \"cell\"\
            },\
    {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                },\
                {\
                    \"type\": \"cell\"\
                }\
        ]\
    }";
    return ret;
}


#endif /* INFO_NIVEL_H_ */
