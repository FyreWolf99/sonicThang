#include "obs.hpp"

obs::obs(app* application)
{
	this->application = application;
	
	obstacles = (SDL_Rect *) malloc(sizeof(SDL_Rect) * obsCount);
	obstacles[0] = (SDL_Rect) {1000, 900, 500, 50};
	obstacles[1] = (SDL_Rect) {400, 800, 100, 200};
}

bool obs::collide(vec2* plPos, vec2* plVel)
{
	for (int i = 0; i < obsCount; i++)
	{
		if (plPos->y + PL_SIZE >= obstacles[i].y && plPos->y <= obstacles[i].y + OBS_HOP_BUFF && plPos->x + PL_SIZE >= obstacles[i].x && plPos->x <= obstacles[i].x + obstacles[i].w)
		{
			plPos->y = obstacles[i].y - PL_SIZE;
			plVel->y = -PL_GRAV;
			return true;
		}
		else if (plPos->y + PL_SIZE >= obstacles[i].y && plPos->y <= obstacles[i].y + obstacles[i].h && plPos->x + PL_SIZE >= obstacles[i].x && plPos->x <= obstacles[i].x + obstacles[i].w)
		{
			if (plVel->x < 0)
			{
				plPos->x = obstacles[i].x + obstacles[i].w;
				plVel->x = 0;
			}
			else
			{
				plPos->x = obstacles[i].x - PL_SIZE;
				plVel->x = 0;
			}
			return true;
		}
		else if (plPos->x + PL_SIZE >= obstacles[i].x && plPos->x <= obstacles[i].x)
		{
			if (plVel->x < 0)
				plPos->x = obstacles[i].x + obstacles[i].w;
			else
				plPos->x = obstacles[i].x - PL_SIZE;
			
			return true;
		}
	}

	return false;
}

void obs::draw()
{
	SDL_SetRenderDrawColor(application->renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	for (int i = 0; i < obsCount; i++)
	{
		SDL_RenderDrawRect(application->renderer, &(obstacles[i]));
	}
}