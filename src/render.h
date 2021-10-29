#include <SDL2/SDL_render.h>
SDL_Renderer* get_renderer();
void render_present();
void render_init();
void render_size(int w, int h);