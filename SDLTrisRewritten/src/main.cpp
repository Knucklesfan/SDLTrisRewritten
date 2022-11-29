#include <SDL2/SDL.h>
#include <gl\glew.h>
#include <SDL2/SDL_opengl.h>
#include <gl\glu.h>
#include <stdio.h>
#include <string>
#include "shader.h"
#include "texture.h"
#include <iostream>
#include "stb_image.h"

//Graphics program
GLuint gProgramID = 0;
GLint gVertexPos2DLocation = -1;
GLuint gVBO = 0;
GLuint gIBO = 0;

float vertices[] = {
	// positions          // colors           // texture coords
	 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   2.0f, 2.0f, // top right
	 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   2.0f, 0.0f, // bottom right
	-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
	-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 2.0f  // top left 
};
unsigned int indices[] = {
	0, 1, 2, // first triangle
	1, 2, 3
};

int main(int argc, char* argv[])
{
	// Initialize SDL with video
	SDL_Init(SDL_INIT_VIDEO);


	//Use OpenGL 3.1 core
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	// Create an SDL window
	SDL_Window*  window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

	// if failed to create a window
	if (!window)
	{
		// we'll print an error message and exit
		std::cerr << "Error failed to create window!\n";
		return 1;
	}


	// Create an OpenGL context (so we can use OpenGL functions)
	SDL_GLContext context = SDL_GL_CreateContext(window);

	// if we failed to create a context
	if (!context)
	{
		// we'll print out an error message and exit
		std::cerr << "Error failed to create a context\n!";
		return 2;
	}
	
	glewExperimental = GL_TRUE;
	GLenum glewError = glewInit();
	if (glewError != GLEW_OK)
	{
		printf("Error initializing GLEW! %s\n", glewGetErrorString(glewError));
	}

	//Use Vsync
	if (SDL_GL_SetSwapInterval(1) < 0)
	{
		printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());
	}

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
	bool running = true; // used to determine if we're running the game
	double angle = 0;

	glClearColor(0, 0, 0, 1);


	unsigned int VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	// texture coord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	//TODO: MAKE A SHADER CLASS!!!!!

		//** BEGIN TEXTURE
	unsigned int texture;
	{
		glGenTextures(1, &texture);
		glActiveTexture(GL_TEXTURE0); // activate the texture unit first before binding texture
		glBindTexture(GL_TEXTURE_2D, texture);
		// set the texture wrapping/filtering options (on the currently bound texture object)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		// load and generate the texture
		int width, height, nrChannels;
		unsigned char* data = stbi_load("./textures/container.jpg", &width, &height, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			std::cout << "Failed to load texture" << std::endl;
		}
		stbi_image_free(data);
	}//END TEXTURE

	//** BEGIN TEXTURE
	unsigned int texture2;
	{
		stbi_set_flip_vertically_on_load(true);

		glGenTextures(1, &texture2);
		glActiveTexture(GL_TEXTURE1); // activate the texture unit first before binding texture
		glBindTexture(GL_TEXTURE_2D, texture2);
		// set the texture wrapping/filtering options (on the currently bound texture object)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		// load and generate the texture
		int width, height, nrChannels;
		unsigned char* data = stbi_load("./textures/walmart.png", &width, &height, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			std::cout << "Failed to load texture" << std::endl;
		}
		stbi_image_free(data);
	}//END TEXTURE










	shader orange = shader("./shaders/vertex_unlit.shader", "./shaders/fragment_unlit.shader");
	shader rainbow = shader("./shaders/vertex_rainbow.shader", "./shaders/fragment_rainbow.shader");	SDL_Event event;	 // used to store any events from the OS

	while (running)
	{
		// poll for events from SDL
		while (SDL_PollEvent(&event))
		{
			// determine if the user still wants to have the window open
			// (this basically checks if the user has pressed 'X')
			running = event.type != SDL_QUIT;
		}

		glClear(GL_COLOR_BUFFER_BIT);

		glClear(GL_COLOR_BUFFER_BIT);
		float timeValue = SDL_GetTicks();
		float greenValue = sin(timeValue) / 2.0f + 0.5f;



		orange.activate();
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		// Swap OpenGL buffers
		SDL_GL_SwapWindow(window);
	}


	// Destroy the context
	SDL_GL_DeleteContext(context);

	// Destroy the window
	SDL_DestroyWindow(window);

	// And quit SDL
	SDL_Quit();

	return 0;
}
