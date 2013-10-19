CC = gcc
OBJECTS = App.o surface.o window_surface.o sprite.o animated_sprite.o SoundBank.o


CPPFLAGS = -Wall -Wextra -g `sdl-config --cflags`
LDFLAGS=`sdl-config --libs` -lSDL -lSDL_image -lSDL_mixer -lstdc++

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

SoundBank.o: SoundBank.h SoundBank.cpp
	$(CC) $(CPPFLAGS) -c SoundBank.cpp

# cleanup
clean:
	rm *.o *.save $(EXEC)

# EOF
