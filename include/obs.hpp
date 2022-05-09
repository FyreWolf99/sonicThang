#pragma once

#include "vec2.hpp"
#include "render.hpp"
#include "defs.h"

class obs
{
	public:
		obs(app* application);

		bool collide(vec2* plPos, vec2* plVel);
		
		void draw();

	private:
		const int obsCount = 2;

		SDL_Rect* obstacles;
		app* application;
};