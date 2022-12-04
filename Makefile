OBJS	= main.o shader.o stbi_image.o texture.o
HEADER	= 
OUT	= SDLTetris
CC	 = g++
FLAGS	 = -g -c -Wall -Iinclude/
LFLAGS	 = -lSDL2 -lGLEW -lGL -fsanitize=address

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: src/main.cpp
	$(CC) $(FLAGS) src/main.cpp 
shader.o: src/shader.cpp
	$(CC) $(FLAGS) src/shader.cpp 
texture.o: src/texture.cpp
	$(CC) $(FLAGS) src/texture.cpp 

stbi_image.o: src/stbi_image.c
	$(CC) $(FLAGS) src/stbi_image.c 
clean:

	rm -f $(OBJS) $(OUT)
