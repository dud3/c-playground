#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>

#include "window_manager.h"
// #include "sdl_events.h"

int main()
{
	void on_update(WindowManager_dt dt)
        {
                // printf("WindowManager_dt: %f\n", dt);
        }
	void on_render(WindowManager_dt dt)
	{

	}
        void on_key_down(SDL_Keycode keycode)
        {
                printf("OnKeyDown: %d\n", keycode);
        }
	void on_key_up(SDL_Keycode keycode)
	{
		printf("OnKeyUp: %d\n", keycode);
	}

	WindowManager* wm = window_manager_create(400, 400);

	wm->on_update = on_update;
	wm->on_render = on_render;
	wm->events.onkeydown = on_key_down;
	wm->events.onkeyup = on_key_up;

    	window_manager_main_loop(wm);

    	return 0;
}

