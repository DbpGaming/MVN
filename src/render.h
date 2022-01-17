#include <SDL2/SDL_render.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_surface.h>
#include <stdio.h>
#include <stdlib.h>
#include <config.h>
#include "types.h"

extern SDL_Renderer* renderer;
extern SDL_Window* window;
extern SDL_Point ws;
void render_init();
void render_size(u16 w, u16 h);
void render_surface(SDL_Surface* Surface, SDL_Rect position);
SDL_Rect float_position(SDL_Surface* Surface, float y, float x, float w, float h);
void render_floating_image_rect(char* name, SDL_Rect surf_rect);
void render_floating_surface_rect(SDL_Surface* surf, SDL_Rect surf_rect);
void render_floating_text_rect(char* text, SDL_Rect surf_rect, SDL_Colour color);
SDL_Rect quick_rect(u8 y, u8 x, u8 w, u8 h);
u8 window_update();