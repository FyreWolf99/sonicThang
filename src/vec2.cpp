#include "vec2.hpp"

vec2::vec2(float x, float y)
{
	this->x = x;
	this->y = y;
}

vec2::vec2()
{
	this->x = 0;
	this->y = 0;
}

void vec2::normalize()
{
	float inv = 1 / (this->x * this->x + this->y * this->y);
	
	*this = *this * inv;
}