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
bool window_manager_render(WindowManager* wm,
        void (*on_event)(void* d0, void* d1),
        void (*on_update)(WindowManager_dt dt),
        void (*on_render)(WindowManager_dt dt))
{
        bool quit = false;

        // note: why does passing wm->renderer directly to SDL_SetRenderDrawColor
        // result in "Segmentation fault"
        SDL_Renderer* renderer = wm->renderer;

        while(!quit) {
                SDL_Event event;

                while(SDL_PollEvent(&event) != 0) {
                        switch (event.type) {
			        case SDL_QUIT:
                                        quit = true;
				break;
                        }

                        window_manager_on_event(&event, on_event);
                }

                // update...

                (*on_update)(dt);

                // render

                // Initialize renderer color white for the background
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

                // Clear screen
                SDL_RenderClear(renderer);

                (*on_render)(dt);

                // Set renderer color red to draw the square
                SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);

                // Draw filled square
                // SDL_RenderFillRect(renderer, &rect);

                // Update screen
                SDL_RenderPresent(renderer);

		SDL_Delay(1000 / 60);
        }

        // window_manager_render(wm, on_update, on_render);

        window_manager_destroy(wm);

        return quit;
}

void window_manager_on_event(SDL_Event* e, void (*fn)(void* d0, void* d1))
{
	switch(e->type) {
		case SDL_KEYDOWN:
			(*fn)(&e->key.keysym.sym, NULL);
			break;
		default:
			// do nothing...
			break;
	}
}

void window_manager_destroy(WindowManager* wm) {
	SDL_DestroyRenderer(wm->renderer);
        SDL_DestroyWindow(wm->window);
        SDL_Quit();
}
