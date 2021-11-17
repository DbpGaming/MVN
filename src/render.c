#include "render.h"
#include "main.h"

SDL_Renderer* renderer;
SDL_Window* window;
SDL_Texture* Texture;
SDL_Point ws;

void render_size(u16 w, u16 h){
	SDL_SetWindowSize(window, w, h);
	SDL_GetWindowSize(window, &ws.x, &ws.y);
}

void render_surface(SDL_Surface* surf, SDL_Rect pos){
	Texture = SDL_CreateTextureFromSurface(renderer, surf);
	SDL_RenderCopy(renderer, Texture, NULL, &pos);
}

SDL_Rect quick_rect(u8 y, u8 x, u8 w, u8 h){
	SDL_Rect pos = {x,y,w,h};
	return pos;
}

float calc_scale(float a, float b, float c){
	return (a / 255 * b) / c * ws.y * 2;
}

float calc_pos(float a, float b, float c){
	return (a / 255 * b) - c * 0.5;
}

SDL_Rect float_position_rect(SDL_Surface* surf, SDL_Rect rect){
	SDL_Rect pos = {0, 0, calc_scale(rect.w, surf->w, surf->h), calc_scale(rect.h, surf->h, surf->h)};
	pos.y = calc_pos(rect.y, ws.y, pos.h);
	pos.x = calc_pos(rect.x, ws.x, pos.w);
	return pos;
}

void render_floating_surface_rect(SDL_Surface* surf, SDL_Rect surf_rect){
	render_surface(surf, float_position_rect(surf, surf_rect));
}

void render_floating_surface(SDL_Surface* surf, float y, float x, float w, float h){
	render_floating_surface_rect(surf, quick_rect(y, x, w, h));
}

void render_floating_image_rect(char* name, SDL_Rect surf_rect){
	SDL_Surface* surf = IMG_Load(name);
	render_floating_surface_rect(surf, surf_rect);
	SDL_FreeSurface(surf);
}

void render_floating_text_rect(char* text, SDL_Rect surf_rect){
	SDL_Color testcol = {0, 0, 0, 255};
	SDL_Surface* surf = TTF_RenderText_Blended_Wrapped(font, text, testcol, 100);
	render_floating_surface_rect(surf, surf_rect);
	SDL_FreeSurface(surf);
}

void render_floating_text(char* text, u8 y, u8 x, u8 w, u8 h){
	render_floating_text_rect(text, quick_rect(y,x,w,h));
}