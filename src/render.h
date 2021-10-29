#include <SDL2/SDL_render.h>
SDL_Renderer* get_renderer();
SDL_Window* get_window();
void render_init();
void render_size(int w, int h);
void render_surface(SDL_Surface* Surface, SDL_Rect position);
SDL_Rect float_position(SDL_Surface* Surface, float y, float x, float w, float h);
void render_image(char* filename, SDL_Rect position);
void render_floating_image(char* filename, float y, float x, float w, float h);