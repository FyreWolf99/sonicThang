#include "input.hpp"

inpState inp;
bool* running;

inpState* input::init(bool* run)
{
	running = run;
	return &inp;
}

void input::poll()
{
	inp.jmp = false;
	
	SDL_Event e;

	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
			case SDL_QUIT:
				*running = false;
				break;
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym)
				{
					case SDLK_d:
					case SDLK_RIGHT:
						inp.rht = true;
						break;
					case SDLK_a:
					case SDLK_LEFT:
						inp.lft = true;
						break;
					case SDLK_DOWN:
					case SDLK_s:
						inp.dwn = true;
						break;
					case SDLK_SPACE:
					case SDLK_w:
					case SDLK_UP:
						inp.jmp = true;
						break;
				}
				break;
			case SDL_KEYUP:
				switch (e.key.keysym.sym)
				{
					case SDLK_d:
					case SDLK_RIGHT:
						inp.rht = false;
						break;
					case SDLK_a:
					case SDLK_LEFT:
						inp.lft = false;
						break;
					case SDLK_DOWN:
					case SDLK_s:
						inp.dwn = false;
						break;
				}
				break;
		}
	}
}