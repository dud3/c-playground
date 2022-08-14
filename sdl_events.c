#include <stdio.h>
#include <SDL.h>
#include "sdl_events.h"

typedef SDL_Keycode Se_KeyCode;

typedef struct Se_Mouse {
	int x;
	int y;
} Se_Mouse;

void se_register(void (*fn)(void* d0, void* d1))
{
	SDL_Event e;

	while(SDL_PollEvent(&e) != 0) {
		se_on_event(&e, fn);
	}
}

void se_on_event(SDL_Event* e, void (*fn)(void* d0, void* d1))
{
	printf("e->type: %d ", e->type);
	switch(e->type) {
		case SDL_KEYDOWN:
			(*fn)(&e->key.keysym.sym, NULL);
			break;
		default:
			// do nothing...
			break;
	}
}
