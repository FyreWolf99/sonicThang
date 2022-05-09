#pragma once

#include "input.hpp"
#include "render.hpp"
#include "vec2.hpp"
#include "plat.hpp"

class player
{
	public:
		player(inpState* inputs, bool* run, app* appl, plat* platforms);
		player();

		void update();
		void draw();
	private:
		inpState* inps;
		bool* run;
		app* application;
		plat* platforms;

		SDL_Rect rect;
		const char* images[6] = {"../res/img/ball_1.png", "../res/img/ball_3.png", "../res/img/ball_4.png", "../res/img/ball_5.png", "../res/img/ball_6.png", "../res/img/ball_7.png"};
		SDL_Surface* surfaces[6];
		SDL_Texture* text;
		int surfaceIndex = 0;
		int animFrame = 0;
		vec2 pos;
		vec2 vel;

		bool isOnFloor = false;
		int revTimer = PL_REV_BUFF;
};