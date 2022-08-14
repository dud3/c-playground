#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>

#include "window_manager.h"
// #include "sdl_events.h"

int main()
{
	WindowManager* vm = window_manager_create(400, 400);

    void on_update(WindowManager_dt dt) {
        // printf("WindowManager_dt: %f\n", dt);
    }
    void on_event(void *e0, void* e1) {
        SDL_Keycode* k = (SDL_Keycode*) e0;
        printf("Keycode: %d\n", *k);
    }

    window_manager_render(vm, on_event, on_update, on_update);

    return 0;
}

