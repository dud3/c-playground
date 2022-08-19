#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include <unistd.h>

#include "window_manager.h"

WindowManager* window_manager_create(int width, int height) {
	WindowManager wm;

	if (SDL_INIT_VIDEO < 0) {
                printf("SDL could not be initialized!\n"
                "SDL_Error: %s\n", SDL_GetError());
                return NULL;
        }

        wm.window = SDL_CreateWindow("Sample window",
                        SDL_WINDOWPOS_UNDEFINED,
                        SDL_WINDOWPOS_UNDEFINED,
                        width, height,
                        SDL_WINDOW_SHOWN);

        if (!wm.window) {
                printf("SDL window init error\n");
                printf("SDL_Error: %s\n", SDL_GetError());
                return NULL;
        }

        wm.renderer = SDL_CreateRenderer(wm.window,
                -1, SDL_RENDERER_ACCELERATED);

        if (!wm.renderer) {
                printf("Renderer failed\n");
                printf("SDL_ERROR: %s\n", SDL_GetError());
                return NULL;
        }

        WindowManager* wmp = &wm;

        return wmp;
}

float dt = 0.0f; // delta time
bool window_manager_main_loop(WindowManager* wm)
{
        bool quit = false;

        // note: why does passing wm->renderer
	// directly to SDL_SetRenderDrawColor
        // result in "Segmentation fault"
        SDL_Window* window = wm->window;
        SDL_Renderer* renderer = wm->renderer;

	__OnUpdate on_update = wm->on_update;
	__OnRender on_render = wm->on_render;

	__Events events = wm->events;

        while(!quit) {
                SDL_Event event;

                while(SDL_PollEvent(&event) != 0) {
                        switch (event.type) {
			        case SDL_QUIT:
                                        quit = true;
				break;
                        }

                        window_manager_on_event(events, &event);
                }

                // update...

                on_update(dt);

                // render

                // Initialize renderer color white for the background
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

                // Clear screen
                SDL_RenderClear(renderer);

                on_render(dt);

                // Set renderer color red to draw the square
                SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);

                // Draw filled square
                // SDL_RenderFillRect(renderer, &rect);

                // Update screen
                SDL_RenderPresent(renderer);

		SDL_Delay(1000 / 60);
        }

	window_manager_destroy(window, renderer);
}

void window_manager_on_event(__Events events, SDL_Event* e)
{
	switch(e->type) {
		case SDL_KEYDOWN:
			if (events.onkeydown == NULL) break;
			events.onkeydown(e->key.keysym.sym);
			break;
		case SDL_KEYUP:
			if(events.onkeyup == NULL) break;
			events.onkeyup(e->key.keysym.sym);
			break;
		default:
			// do nothing...
			break;
	}
}

void window_manager_destroy(SDL_Window* window, SDL_Renderer* renderer) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);

        SDL_Quit();
}

