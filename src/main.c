#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <config.h>
#include "render.h"

int main(){
	render_init();
	SDL_SetRenderDrawColor(get_renderer(), 255, 128, 255, 255);
	SDL_RenderClear(get_renderer());
	render_floating_image("1615350775259.jpg", 128, 128, 121, 121);
	SDL_RenderPresent(get_renderer());
	SDL_Delay(2500);
	SDL_SetWindowPosition(get_window(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	SDL_RenderClear(get_renderer());
	render_floating_image("1615350775259.jpg", 128, 128, 121, 121);
	SDL_RenderPresent(get_renderer());
	SDL_Delay(2500);
	return 0;
}