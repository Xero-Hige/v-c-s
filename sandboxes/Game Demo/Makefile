CC = gcc
OBJECTS = App.o surface.o sprite.o window.o SoundBank.o


CPPFLAGS = -Wall -Wextra -g -pedantic `sdl2-config --cflags`
LDFLAGS=`sdl2-config --libs` -lSDL2 -lSDL2_image -lSDL2_mixer -lstdc++

EXEC = sdl

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) $(CPPFLAGS) $(LDFLAGS) -o $(EXEC)
	
App.o: App.h App.cpp
	$(CC) $(CPPFLAGS) -c App.cpp

surface.o: libs/surface/surface.h libs/surface/surface.cpp
	$(CC) $(CPPFLAGS) -c libs/surface/surface.cpp
	
sprite.o: libs/sprite/sprite.h libs/sprite/sprite.cpp
	$(CC) $(CPPFLAGS) -c libs/sprite/sprite.cpp

animated_sprite.o: libs/animated_sprite/animated_sprite.h libs/animated_sprite/animated_sprite.cpp
	$(CC) $(CPPFLAGS) -c libs/animated_sprite/animated_sprite.cpp

window_surface.o: libs/window_surface/window_surface.h libs/window_surface/window_surface.cpp
	$(CC) $(CPPFLAGS) -c libs/window_surface/window_surface.cpp

window.o: libs/window/window.h libs/window/window.cpp
	$(CC) $(CPPFLAGS) -c libs/window/window.cpp

SoundBank.o: SoundBank.h SoundBank.cpp
	$(CC) $(CPPFLAGS) -c SoundBank.cpp

# cleanup
clean:
	rm *.o *.save $(EXEC)

# EOF
