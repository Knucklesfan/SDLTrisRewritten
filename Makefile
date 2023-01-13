OBJS	= main.o shader.o stbi_image.o texture.o utils.o skybox.o plane.o cube.o sprite.o buffermanager.o pixfont.o background.o
HEADER	= 
OUT	= SDLTetris
CC	 = g++
FLAGS	 = -g -c -Wall -Iinclude/ -DCLIENT
LFLAGS	 = -lSDL2 -lSDL2_mixer -lGLEW -lGL -fsanitize=address

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: src/main.cpp
	$(CC) $(FLAGS) src/main.cpp 
shader.o: src/shader.cpp
	$(CC) $(FLAGS) src/shader.cpp 
texture.o: src/texture.cpp
	$(CC) $(FLAGS) src/texture.cpp 
utils.o: src/utils.cpp
	$(CC) $(FLAGS) src/utils.cpp 
skybox.o: src/skybox.cpp
	$(CC) $(FLAGS) src/skybox.cpp 
plane.o: src/plane.cpp
	$(CC) $(FLAGS) src/plane.cpp 
cube.o: src/cube.cpp
	$(CC) $(FLAGS) src/cube.cpp 
sprite.o: src/sprite.cpp
	$(CC) $(FLAGS) src/sprite.cpp 
buffermanager.o: src/buffermanager.cpp
	$(CC) $(FLAGS) src/buffermanager.cpp 
pixfont.o: src/pixfont.cpp
	$(CC) $(FLAGS) src/pixfont.cpp 
background.o: src/background.cpp
	$(CC) $(FLAGS) src/background.cpp 

stbi_image.o: src/stbi_image.c
	$(CC) $(FLAGS) src/stbi_image.c 
clean:

	rm -f $(OBJS) $(OUT)
