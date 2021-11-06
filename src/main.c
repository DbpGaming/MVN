#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_image.h>
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

layout current;

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
		if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
 			break;
		if (current.changed){
			SDL_RenderClear(get_renderer());
			for(int i = 0; current.images[i].position.w != 0; i++)
				render_floating_image(current.images[i].Surface, current.images[i].position.y, current.images[i].position.x, current.images[i].position.h, current.images[i].position.w);
			SDL_RenderPresent(get_renderer());
			current.changed = 0;
		}
	}
	SDL_FreeSurface(IMG[0]);
}

int main(){
	SDL_SetRenderDrawColor(get_renderer(), 255, 128, 255, 255);
	render_init();
	game_loop();
	//printf("%d", open_script("test.bin"));
	return 0;
}