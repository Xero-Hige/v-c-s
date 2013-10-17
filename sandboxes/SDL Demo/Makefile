# Automatically generated Makefile for project: sdl_coords_and_blitting
# Created on  by gaten for sdltutorials.com
# Comments, suggestions and bugs email: gaten DOT net AT gmail DOT com

# Compiler
CC = gcc

# Objects
OBJECTS = App.o Surface.o

# Compiler flags
CPPFLAGS = -Wall -Wextra -g `sdl-config --cflags`

# Linker flags
LDFLAGS=`sdl-config --libs` -lSDL -lSDL_image -lstdc++

main: App.cpp
	$(CC) $(CPPFLAGS) -c App.cpp Surface.cpp
	$(CC) $(OBJECTS) $(CPPFLAGS) $(LDFLAGS) -o sdl

# cleanup
clean:
	rm -rf $(OBJECTS)

# EOF
