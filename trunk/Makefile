#Project Builder
#General
CC = gcc
CPPFLAGS = -Wall -Wextra -g -pedantic `sdl2-config --cflags` -lstdc++ -lm


#Graphic libs builder

SDL_CPPFLAGS = -Wall -Wextra -g -pedantic `sdl2-config --cflags` -lstdc++ -lm #//TODO: arreglar

SDL_LDFLAGS =`sdl2-config --libs` -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

GRAPHIC_LIBS = surface.o sprite.o animated_sprite.o window.o text_drawer.o

surface.o: libs/surface/surface.h libs/surface/surface.cpp
	$(CC) $(SDL_CPPFLAGS) -c libs/surface/surface.cpp
	
sprite.o: libs/sprite/sprite.h libs/sprite/sprite.cpp
	$(CC) $(SDL_CPPFLAGS) -c libs/sprite/sprite.cpp

animated_sprite.o: libs/animated_sprite/animated_sprite.h libs/animated_sprite/animated_sprite.cpp
	$(CC) $(SDL_CPPFLAGS) -c libs/animated_sprite/animated_sprite.cpp

window.o: libs/window/window.h libs/window/window.cpp
	$(CC) $(SDL_CPPFLAGS) -c libs/window/window.cpp
	
text_drawer.o: libs/text_drawer/text_drawer.h libs/text_drawer/text_drawer.cpp
	$(CC) $(SDL_CPPFLAGS) -c libs/text_drawer/text_drawer.cpp
	
#Sound libs builder

SOUND_LIBS = 

#Client

CLIENT_OBJ = $(GRAPHIC_LIBS) login_screen.o client_app.o 

CLIENT_NAME = game-client

login_screen.o: Client/login_screen.cpp Client/login_screen.h
	$(CC) $(SDL_CPPFLAGS) -c Client/login_screen.cpp

client_app.o: Client/client_app.cpp Client/client_app.h
	$(CC) $(SDL_CPPFLAGS) -c Client/client_app.cpp

client: Client/client.cpp $(CLIENT_OBJ)
	$(CC) $(SDL_CPPFLAGS) $(SDL_LDFLAGS) $(CLIENT_OBJ) Client/client.cpp -o $(CLIENT_NAME)
		
#Cleanup
clean:
	rm *.o *.save $(CLIENT_NAME)
	
#Run
run-client: client
	./CLIENT_NAME