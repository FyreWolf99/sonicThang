#pragma once

#include <SDL2/SDL.h>

typedef struct inpState
{
	bool lft = false, rht = false, jmp = false, dwn = false;
} inpState;

namespace input
{
	inpState* init(bool* run);

	void poll();
}