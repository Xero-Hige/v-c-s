CC = gcc
OBJECTS = App.o Surface.o SoundBank.o


CPPFLAGS = -Wall -Wextra -g `sdl-config --cflags`
LDFLAGS=`sdl-config --libs` -lSDL -lSDL_image -lSDL_mixer -lstdc++

EXEC = sdl

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) $(CPPFLAGS) $(LDFLAGS) -o $(EXEC)
	
App.o: App.h App.cpp
	$(CC) $(CPPFLAGS) -c App.cpp

Surface.o: Surface.h Surface.cpp
	$(CC) $(CPPFLAGS) -c Surface.cpp

SoundBank.o: SoundBank.h SoundBank.cpp
	$(CC) $(CPPFLAGS) -c SoundBank.cpp

# cleanup
clean:
	rm *.o *.save $(EXEC)

# EOF
