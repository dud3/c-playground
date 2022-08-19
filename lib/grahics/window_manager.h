#ifndef _WINDOW_MANAGER_H_
#define _WINDOW_MANAGER_H_

#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>

typedef int (*__SingletonFI)(int);
typedef int (*__TupleFi)(int, int);
typedef int (*__TripleFi)(int, int, int);

typedef float WindowManager_dt;

typedef void (*__OnUpdate)(WindowManager_dt dt);
typedef void (*__OnRender)(WindowManager_dt dt);
typedef void (*__Onkeydown)(SDL_Keycode);
typedef void (*__Onkeyup)(SDL_Keycode);

typedef struct __Events {
        __Onkeydown onkeydown;
	__Onkeyup onkeyup;
} __Events;

typedef struct WindowManager {
	SDL_Window* window;
	SDL_Renderer* renderer;

	__OnUpdate on_update;
	__OnRender on_render;

	__Events events;
} WindowManager;

WindowManager* window_manager_create(int width, int height);
bool window_manager_main_loop(WindowManager* wm);
void window_gather_events(void (*fn)(void* d0, void* d1));
void window_manager_on_event(__Events events, SDL_Event* e);
void window_manager_destroy(SDL_Window*, SDL_Renderer*);

#endif

