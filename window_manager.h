#ifndef _WINDOW_MANAGER_H_
#define _WINDOW_MANAGER_H_

#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>

typedef struct WindowManager {
	SDL_Window* window;
	SDL_Renderer* renderer;
} WindowManager;

typedef float WindowManager_dt;

WindowManager* window_manager_create(int width, int height);
bool window_manager_render(WindowManager* wm,
        void (*on_event)(void* d0, void* d1),
        void (*on_update)(WindowManager_dt dt),
        void (*on_render)(WindowManager_dt dt));
void window_gather_events(void (*fn)(void* d0, void* d1));
void window_manager_on_event(SDL_Event* e, void (*fn)(void* d0, void* d1));
void window_manager_destroy(WindowManager* wm);

#endif
