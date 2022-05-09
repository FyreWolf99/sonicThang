#include "render.hpp"
#include "input.hpp"
#include "player.hpp"
#include "plat.hpp"

int main(void)
{
	bool running = true;

	app* application = render::init();
	if (application == NULL) return -1;

	inpState* inp = input::init(&running);
	
	plat platforms(application);
	player p(inp, &running, application, &platforms);
	
	while (running)
	{
		p.update();

		input::poll();

		// Start Drawing
		render::startDraw();
		
			// Draw Player
			p.draw();

			// Draw Platforms
			platforms.draw();

		// Stop Rendering
		render::endDraw();
	}
	
	return 0;
}