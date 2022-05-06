#include "render.hpp"
#include "input.hpp"
#include "player.hpp"

int main(void)
{
	bool running = true;

	app* application = render::init();
	if (application == NULL) return -1;

	inpState* inp = input::init(&running);
	
	player p(inp, &running, application);
	
	while (running)
	{
		p.update();

		input::poll();

		// Start Drawing
		render::startDraw();
		
			// Draw Player
			p.draw();

		// Stop Rendering
		render::endDraw();
	}
	
	return 0;
}