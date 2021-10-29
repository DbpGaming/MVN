#include <SDL2/SDL.h>
#include <config.h>
#include "render.h"

int main(){
	render_init();
	SDL_SetRenderDrawColor(get_renderer(), 255, 128, 255, 255);
	render_present();
	SDL_Delay(2500);
	render_size(1000, 1000);
	SDL_Delay(2500);
	return 0;
}