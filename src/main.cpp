#include "render.hpp"
#include "input.hpp"
#include "player.hpp"
#include "obs.hpp"

int main(void)
{
	bool running = true;

	app* application = render::init();
	if (application == NULL) return -1;

	inpState* inp = input::init(&running);
	
	obs obstacles(application);
	player p(inp, &running, application, &obstacles);
	
	while (running)
	{
		p.update();

		input::poll();

		// Start Drawing
		render::startDraw();
		
			// Draw Player
			p.draw();
			
			// Draw Obstacles
			obstacles.draw();

		// Stop Rendering
		render::endDraw();
	}
	
	return 0;
}