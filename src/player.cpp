#include "player.hpp"

player::player(inpState* inputs, bool* runn, app* appl)
{
	inps = inputs;
	run = runn;
	application = appl;

	rect = (SDL_Rect) {0, HEIGHT / 2, PL_SIZE, PL_SIZE};
}

void player::update()
{
	// Horizontal Input
	int inp = inps->rht - inps->lft;
	
	if (inp == 0)
		revTimer--;
	else
		revTimer = PL_REV_BUFF;
	
	// Horizontal Velocity
	if ((inp < 0 && vel.x > 0) || (inp > 0 && vel.x < 0))
		vel.x *= -0.9375f;
	else if (inp == 0 && revTimer <= 0)
	{
		if (vel.x >= 25)
			vel.x -= PL_FRICTION;
		else if (vel.x <= -25)
			vel.x += PL_FRICTION;
		else
			vel.x = 0;
	}
	else if (vel.x < PL_MAX_SPD || vel.x > -PL_MAX_SPD)
		vel.x += inp * PL_ACC;

	// Vertical Velocity
	vel.y += PL_GRAV;

	if (inps->jmp && isOnFloor)
	{
		vel.y -= PL_JMP_SPD;
		isOnFloor = false;
	}
	
	// Update Position
	pos += vel;
	
	// Use Edge of Screen as Walls
	if (pos.x > WIDTH - PL_SIZE)
	{
		pos.x = WIDTH - PL_SIZE;
		vel.x *= -1;
	}
	else if (pos.x < 0)
	{
		pos.x = 0;
		vel.x *= -1;
	}

	// Use bottom of screen as floor
	if (pos.y > HEIGHT - PL_SIZE)
	{
		pos.y = HEIGHT - PL_SIZE;
		vel.y = 0;
		isOnFloor = true;
	}
}

void player::draw()
{
	rect = (SDL_Rect) {(int) pos.x, (int) pos.y, PL_SIZE, PL_SIZE};
	
	SDL_SetRenderDrawColor(application->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(application->renderer, &rect);
}