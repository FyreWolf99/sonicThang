#include "plat.hpp"

plat::plat(app* application)
{
    this->application = application;
    
    platforms = (platform *) calloc(platCount, sizeof(platform));
    
    platforms[0] = (platform) {vec2(1300, 1000), 400};
    platforms[1] = (platform) {vec2(400, 900), 600};
}

int plat::isColliding(vec2* pos)
{
    for (int i = 0; i < platCount; i++)
    {
        if (pos->x + PL_SIZE <= platforms[i].start.x + platforms[i].length && pos->x >= platforms[i].start.x)
        {
            if (pos->y <= platforms[i].start.y && pos->y + PL_SIZE / 4 > platforms[i].start.y)
            {
                pos->y = platforms[i].start.y;
                return 1;
            }
            else if (pos->y + PL_SIZE / 4 <= platforms[i].start.y && pos->y + PL_SIZE >= platforms[i].start.y)
            {
                pos->y = platforms[i].start.y - PL_SIZE;
                return 2;
            }
        }
    }
    return 0;
}

void plat::draw()
{
    SDL_SetRenderDrawColor(application->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    for (int i = 0; i < platCount; i++)
    {
        SDL_RenderDrawLine(application->renderer, platforms[i].start.x, platforms[i].start.y, platforms[i].start.x + platforms[i].length, platforms[i].start.y);
    }
}