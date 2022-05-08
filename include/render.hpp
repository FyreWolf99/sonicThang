#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#include "defs.h"

typedef struct app
{
	SDL_Renderer* renderer = NULL;
	SDL_Window* window = NULL;
	SDL_Surface* surface = NULL;
}app;

namespace render
{
	app* init();
	
	void startDraw();
	void endDraw();
	
	void close();
}