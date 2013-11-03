/**
 client_app.h

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
#ifndef CLIENT_APP_H_
#define CLIENT_APP_H_

#include <SDL.h>

#include <vector>

#include "login_screen.h"
#include "backend/backend.h"

class Client_App : public App{

private:
	bool running;
	std::vector<App*> apps;

	Backend backend;

public:
	Client_App();
	~Client_App();
	int run();

	bool initialize();
	void handle_event(SDL_Event& event);
	void loop();
	void render();
	void cleanup();
};
#endif /* CLIENT_APP_H_ */
