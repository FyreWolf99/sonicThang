#pragma once

class vec2
{
	public:
		float x, y;

		vec2(float x, float y);
		vec2();
		
		void normalize();

		vec2 operator+(vec2 add)
		{
			return vec2(this->x + add.x, this->y + add.y);
		}
		void operator+=(vec2 add)
		{
			*this = *this + add;
		}
		vec2 operator*(float f)
		{
			return vec2(this->x * f, this->y * f);
		}
};