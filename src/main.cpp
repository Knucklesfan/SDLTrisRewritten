#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <string>
#include "utils.h"
#include "shader.h"
#include "texture.h"
#include "skybox.h"
#include "plane.h"
#include "cube.h"
#include "sprite.h"
#include "buffermanager.h"
#include "pixfont.h"
#include "background.h"

#include <iostream>
#include <cmath>
#include "stb_image.h"

int WINDOW_WIDTH = INTERNAL_WIDTH;
int WINDOW_HEIGHT = INTERNAL_HEIGHT;



int main(int argc, char* argv[])
{
	// Initialize SDL with video
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);


	//Use OpenGL 3.1 core
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	// Create an SDL window
	SDL_Window*  window = SDL_CreateWindow("SDLTetris Rewritten", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

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

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
	    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
    }
	//Mix_Music* mus = Mix_LoadMUS("./cannery.mp3");
	//Mix_PlayMusic(mus,1);
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
	bool running = true; // used to determine if we're running the game
	double angle = 0;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);  
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  

	graphics::textures.push_back(new texture("./textures/awesomeface.png"));
	graphics::textures.push_back(new texture("./textures/grid.png"));
	graphics::textures.push_back(new texture("./textures/block.png"));
	graphics::textures.push_back(new texture("./textures/backdrop.png"));
	graphics::textures.push_back(new texture("./textures/block2.png"));

	
	graphics::shaders.push_back(new shader("./shaders/vertex_unlit.shader", "./shaders/fragment_unlit.shader"));
	graphics::shaders.push_back(new shader("./shaders/vertex_rainbow.shader", "./shaders/fragment_rainbow.shader"));
	graphics::shaders.push_back(new shader("./shaders/vertex_background.shader","./shaders/fragment_background.shader"));
	graphics::shaders.push_back(new shader("./shaders/vertex_aspect.shader","./shaders/fragment_aspect.shader"));
	graphics::shaders.push_back(new shader("./shaders/vertex_sprite.shader","./shaders/fragment_sprite.shader"));

	//below is all model stuff
	buffermanager buffer = buffermanager(INTERNAL_WIDTH,INTERNAL_HEIGHT);
	plane plan = plane(glm::vec3(0.0f,0.0f,-3.0f),glm::vec3(100.0f,100.0f,1.0f),glm::vec3((-85.0f), 0.0f, 0.0f));
	skybox backdrop = skybox();
	cube cub = cube(glm::vec3(3.0f,0.0f,-2.0f),glm::vec3(0.0f,0.0f,0.0f),
	glm::vec3(1.0f,1.0f,1.0f),glm::vec3((-85.0f), 45.0f, 0.0f));
	cube cub2 = cube(glm::vec3(3.0f,0.0f,-2.0f),glm::vec3(1.0f,0.0f,-0.0f),
	glm::vec3(1.0f,1.0f,1.0f),glm::vec3((-85.0f), 45.0f, 0.0f));
	cube cub3 = cube(glm::vec3(3.0f,0.0f,-2.0f),glm::vec3(-1.0f,0.0f,-0.0f),
	glm::vec3(1.0f,1.0f,1.0f),glm::vec3((-85.0f), 45.0f, 0.0f));
	cube cub4 = cube(glm::vec3(3.0f,0.0f,-2.0f),glm::vec3(0.0f,1.0f,-0.0f),
	glm::vec3(1.0f,1.0f,1.0f),glm::vec3((-85.0f), 45.0f, 0.0f));

	cube cub5 = cube(glm::vec3(-3.0f,0.0f,-2.0f),glm::vec3(0.0f,0.0f,0.0f),
	glm::vec3(1.0f,1.0f,1.0f),glm::vec3((-85.0f), 45.0f, 0.0f));
	cube cub6 = cube(glm::vec3(-3.0f,0.0f,-2.0f),glm::vec3(1.0f,0.0f,-0.0f),
	glm::vec3(1.0f,1.0f,1.0f),glm::vec3((-85.0f), 45.0f, 0.0f));
	cube cub7 = cube(glm::vec3(-3.0f,0.0f,-2.0f),glm::vec3(-1.0f,0.0f,-0.0f),
	glm::vec3(1.0f,1.0f,1.0f),glm::vec3((-85.0f), 45.0f, 0.0f));
	cube cub8 = cube(glm::vec3(-3.0f,0.0f,-2.0f),glm::vec3(-1.0f,1.0f,-0.0f),
	glm::vec3(1.0f,1.0f,1.0f),glm::vec3((-85.0f), 45.0f, 0.0f));

	spriteRenderer renderer = spriteRenderer();
	pixfont font = pixfont("8x8font");
	bg backg = bg("beachgrid",false);
	
	SDL_Event event;	 // used to store any events from the OS
	float fade = 0.0f;
	float posX=0.0f;
	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double deltaTime = 0;

	while (running)
	{

		// poll for events from SDL
		while (SDL_PollEvent(&event))
		{
			// determine if the user still wants to have the window open
			// (this basically checks if the user has pressed 'X')
			running = event.type != SDL_QUIT;
			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
					case SDLK_w:
						glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
						break;
					case SDLK_s:
						glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
						break;
					case SDLK_a:
						fade++;
						break;
					case SDLK_d:
						fade--;
						break;

				}
			}
			if(event.type == SDL_WINDOWEVENT) {
				if (event.window.event == SDL_WINDOWEVENT_RESIZED) {

					WINDOW_WIDTH =(event.window.data1);
					WINDOW_HEIGHT = (event.window.data2);
        		}
			}
		}
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();

		deltaTime = (double)((NOW - LAST)*1000 / (double)SDL_GetPerformanceFrequency() );

		posX+=deltaTime/0.0005;

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		buffer.enable();
		glm::mat4 projection;
		projection = glm::perspective(glm::radians(45.0f), (float)INTERNAL_WIDTH / (float)INTERNAL_HEIGHT, 0.001f, 10000.0f);
		glm::mat4 view = glm::mat4(1.0f); //view is the **Camera**'s perspective
		view = glm::translate(view, glm::vec3(0.0, 0, -6.0)); 

		//backdrop.render(utils::shaders[2],utils::textures[3]);
		// utils::shaders[1].activate();
		// utils::shaders[1].setFloat("fade",fade);
		// plan.position[0] = fmod(posX,0.5f);
		//plan.render(utils::shaders[0],utils::textures[1],projection,view);
		backg.logic(deltaTime);
		backg.render(graphics::shaders[2]);

		cub.rotation[0] = ((float)SDL_GetTicks()/10 * glm::radians(50.0f))/2;
		cub.rotation[1] = (float)SDL_GetTicks()/10 * glm::radians(50.0f);
		cub.render(graphics::shaders[1],graphics::textures[2],projection,view);
		cub2.rotation[0] = ((float)SDL_GetTicks()/10 * glm::radians(50.0f))/2;
		cub2.rotation[1] = (float)SDL_GetTicks()/10 * glm::radians(50.0f);
		cub2.render(graphics::shaders[1],graphics::textures[2],projection,view);
		cub3.rotation[0] = ((float)SDL_GetTicks()/10 * glm::radians(50.0f))/2;
		cub3.rotation[1] = (float)SDL_GetTicks()/10 * glm::radians(50.0f);
		cub3.render(graphics::shaders[1],graphics::textures[2],projection,view);
		cub4.rotation[0] = ((float)SDL_GetTicks()/10 * glm::radians(50.0f))/2;
		cub4.rotation[1] = (float)SDL_GetTicks()/10 * glm::radians(50.0f);
		cub4.render(graphics::shaders[1],graphics::textures[2],projection,view);

		cub5.rotation[0] = ((float)SDL_GetTicks()/10 * -glm::radians(40.0f))/2;
		cub5.rotation[1] = (float)SDL_GetTicks()/10 * -glm::radians(40.0f);
		cub5.render(graphics::shaders[1], graphics::textures[4],projection,view);
		cub6.rotation[0] = ((float)SDL_GetTicks()/10 * -glm::radians(40.0f))/2;
		cub6.rotation[1] = (float)SDL_GetTicks()/10 * -glm::radians(40.0f);
		cub6.render(graphics::shaders[1], graphics::textures[4],projection,view);
		cub7.rotation[0] = ((float)SDL_GetTicks()/10 * -glm::radians(40.0f))/2;
		cub7.rotation[1] = (float)SDL_GetTicks()/10 * -glm::radians(40.0f);
		cub7.render(graphics::shaders[1], graphics::textures[4],projection,view);
		cub8.rotation[0] = ((float)SDL_GetTicks()/10 * -glm::radians(40.0f))/2;
		cub8.rotation[1] = (float)SDL_GetTicks()/10 * -glm::radians(40.0f);
		cub8.render(graphics::shaders[1],graphics::textures[4],projection,view);


		font.render(&renderer,graphics::shaders[4],"Knuxfan's Tetriminos",320,200,true,255,255,255,0,false,(SDL_GetTicks()/(double)1000.0),5,5,1.0);
		font.render(&renderer,graphics::shaders[4],"2",320,216,true,255,255,255,0,false,(SDL_GetTicks()/(double)1000.0),5,5,1.0);
		font.render(&renderer,graphics::shaders[4],"Now with new OpenGL Renderer!",320,248,true,255,255,255,0,true,(SDL_GetTicks()/(double)1000.0),5,5,1.0);

		buffer.disable(WINDOW_WIDTH,WINDOW_HEIGHT);
		buffer.render(graphics::shaders[3],WINDOW_WIDTH,WINDOW_HEIGHT);
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
void renderObjects() {

}
