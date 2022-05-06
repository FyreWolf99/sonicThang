#pragma once

#include "input.hpp"
#include "render.hpp"
#include "vec2.hpp"

class player
{
	public:
		player(inpState* inputs, bool* run, app* appl);
		player();

		void update();
		void draw();
	private:
		inpState* inps;
		bool* run;
		app* application;

		SDL_Rect rect;
		vec2 pos;
		vec2 vel;

		bool isOnFloor = false;
};