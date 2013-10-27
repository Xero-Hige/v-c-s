#Project Builder

#Graphic libs builder

CPPFLAGS = -Wall -Wextra -g -pedantic `sdl2-config --cflags` -lstdc++ -lm #//TODO: arreglar

SDL_LDFLAGS=`sdl2-config --libs` -lSDL2 -lSDL2_image -lSDL2_mixer

GRAPHIC_LIBS = surface.o sprite.o animated_sprite.o window.o

surface.o: libs/surface/surface.h libs/surface/surface.cpp
	$(CC) $(CPPFLAGS) -c libs/surface/surface.cpp
	
sprite.o: libs/sprite/sprite.h libs/sprite/sprite.cpp
	$(CC) $(CPPFLAGS) -c libs/sprite/sprite.cpp

animated_sprite.o: libs/animated_sprite/animated_sprite.h libs/animated_sprite/animated_sprite.cpp
	$(CC) $(CPPFLAGS) -c libs/animated_sprite/animated_sprite.cpp

window.o: libs/window/window.h libs/window/window.cpp
	$(CC) $(CPPFLAGS) -c libs/window/window.cpp

#Sound libs builder

SOUND_LIBS = 