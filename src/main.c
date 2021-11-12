#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <config.h>
#include "render.h"
#include "script.h"

typedef struct image{
	SDL_Surface* Surface;
	SDL_Rect position;
} image;

typedef struct layout{
	image images[255];
	char changed;
} layout;

/*typedef struct script{
	char* data;
	char* name;
} script;*/

layout current;
char* script;
int sb = 0;
SDL_Color testcol = {0, 0, 0, 255};
TTF_Font* font;
SDL_Surface* text;

char readComm(int i){
	//i++;
	//return script[i--];
	return script[i];
}

void game_loop(){
	SDL_Surface* IMG[255];
	IMG[0] = IMG_Load("1615350775259small.jpg");
	current.images[0].Surface = IMG[0];
	current.images[0].position = quick_rect(128, 128, 121, 121);
	current.images[1].Surface = IMG[0];
	current.images[1].position = quick_rect(0, 128, 121, 121);
	current.changed = 1;
	for(;;){
		SDL_Event event;
		SDL_PollEvent(&event);
		int quit = 0;

		switch (event.type) {
			case SDL_QUIT: quit = 1; break;
			case SDL_MOUSEBUTTONDOWN: sb++; break;
		}

		if (quit == 1) break;
		if (current.changed){
			SDL_RenderClear(get_renderer());
			for(int i = 0; current.images[i].position.w != 0; i++)
				render_floating_image(current.images[i].Surface, current.images[i].position.y, current.images[i].position.x, current.images[i].position.h, current.images[i].position.w);
			render_floating_image(text, 128, 128, 32, 32);
			SDL_RenderPresent(get_renderer());
			current.changed = 0;
		}
	}
	SDL_FreeSurface(IMG[0]);
}
int main(){
	SDL_SetRenderDrawColor(get_renderer(), 255, 128, 255, 255);
	render_init();
	TTF_Init();
	font = TTF_OpenFont("ShortBaby.ttf", 64);
	if (font == NULL) return 204;
	text = TTF_RenderText_Blended_Wrapped(font, "test", testcol, 100);
	script = open_script("test.bin");
	game_loop();
	return 0;
}