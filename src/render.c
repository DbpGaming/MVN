#include <SDL2/SDL.h>
#include <config.h>
#include "render.h"

SDL_Renderer *renderer;
SDL_Window *window;

SDL_Renderer* get_renderer(){
	return renderer;
}

void render_present(){
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void render_init(){
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);
	render_present();
}

void render_size(int w, int h){
	SDL_SetWindowSize(window, w, h);
	render_present();
}

