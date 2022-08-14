#ifndef _SDL_EVENT_H_
#define _SDL_EVENT_H_

#include <SDL.h>

void se_register(void (*fn)(void* d0, void* d1));
void se_on_event(SDL_Event* e, void (*fn)(void* d0, void* d1));

#endif
