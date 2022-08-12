#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main() {
	if (SDL_INIT_VIDEO < 0) {
		printf("SDL could not be initialized!\n"
               	"SDL_Error: %s\n", SDL_GetError());
        	return 0;
	}

	SDL_Window *window = SDL_CreateWindow("Sample window",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);

	if (!window) {
		printf("SDL window init error\n");
		printf("SDL_Error: %s\n", SDL_GetError());
		return -1;
	}

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (!renderer) {
		printf("Renderer failed\n");
		printf("SDL_ERROR: %s\n", SDL_GetError());
		return -1;
	}

	// Rect
	
	SDL_Rect rect;

	rect.w = 200;
	rect.h = 200;

	rect.x = SCREEN_WIDTH / 2 - rect.w / 2;
	rect.y = SCREEN_HEIGHT / 2 - rect.h / 2;

	bool quit = false;
	
	// Event loop
	while(!quit)
        {
                SDL_Event e;

                // Wait indefinitely for the next available event
                SDL_WaitEvent(&e);

                // User requests quit
                if(e.type == SDL_QUIT)
                {
                    quit = true;
                }

                // Initialize renderer color white for the background
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

                // Clear screen
                SDL_RenderClear(renderer);

                // Set renderer color red to draw the square
                SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);

                // Draw filled square
                SDL_RenderFillRect(renderer, &rect);

                // Update screen
                SDL_RenderPresent(renderer);
            }

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}

