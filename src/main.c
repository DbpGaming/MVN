#include "main.h"
#include "render.h"
#include "lua.h"
#include <SDL2/SDL_hints.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_surface.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <stdio.h>

char update;
scene activeScene;
char* script;
SDL_Surface* images[255];
u16 sb = 0;
TTF_Font* font;
char* testchar;

void update_renderer(){
	SDL_RenderClear(renderer);
	for(u8 i = 0; activeScene.images[i].pos.w != 0; i++)
		render_floating_surface_rect(images[activeScene.images[i].id], activeScene.images[i].pos);
	SDL_RenderPresent(renderer);
	update = FALSE;
}

u8 check_events(){
	SDL_Event event;
	SDL_PollEvent(&event);
	
	switch (event.type) {
		case SDL_QUIT: return TRUE; break;
		case SDL_MOUSEBUTTONDOWN: sb++; break;
	}
	
	return FALSE;
}

void game_loop(){
	for(;;){
		if (check_events()) break;
		if (window_update()) update = TRUE;
		
		if (sb > 1) update = TRUE;
		if (sb > 1) sb = 0;
		
		if (update) update_renderer();
	}
}

void sdl_init(){
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 900, SDL_WINDOW_RESIZABLE);
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	SDL_GetWindowSize(window, &ws.x, &ws.y);
}

void font_init(){
	TTF_Init();
	font = TTF_OpenFont("fnt/SIXTY.TTF", 64);
	if (font == NULL) fprintf(stderr, FNT_ERR);
}

void lua_init(){
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	register_lua_functions(L);
	luaL_dofile(L, "lua/main.lua");
	lua_close(L);
}

int main(){
	sdl_init();
	font_init();
	lua_init();
	update = TRUE;
	game_loop();
	return 0;
}