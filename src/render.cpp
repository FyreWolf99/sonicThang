#include "render.hpp"

app application;

app* render::init()
{
	application.window = SDL_CreateWindow("Sanic Thong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL|SDL_WINDOW_FULLSCREEN_DESKTOP);
	if (application.window == NULL)
	{
		fprintf(stderr, "CREATING WINDOW HAS FAILED. ERR: %s\n", SDL_GetError());
		return NULL;
	}

	application.renderer = SDL_CreateRenderer(application.window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	if (application.renderer == NULL)
	{
		fprintf(stderr, "CREATING RENDERER HAS FAILED. ERR: %s\n", SDL_GetError());
		return NULL;
	}

	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);
	
	SDL_SetWindowSize(application.window, DM.w, DM.h);
	
	SDL_RenderSetLogicalSize(application.renderer, WIDTH, HEIGHT);
	
	return &application;
}

void render::startDraw()
{
	SDL_SetRenderDrawColor(application.renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(application.renderer);
}

void render::endDraw()
{
	SDL_RenderPresent(application.renderer);
}