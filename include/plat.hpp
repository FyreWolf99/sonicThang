#pragma once

#include "render.hpp"
#include "vec2.hpp"

typedef struct platform
{
    vec2 start;
    int length;
} platform;

class plat
{
    public:
        plat(app* application);
        void draw();

        int isColliding(vec2* pos); // 0 is not colliding, 1 is from bottom, 2 is from top
    private:
        platform* platforms;
        app* application;
        
        const int platCount = 2;
};