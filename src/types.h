#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_rect.h>

#ifndef TYPES
#define TYPES
#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t
#define u64 uint64_t

#define TRUE 1
#define FALSE 0

#define IB (1 << 0) //image background

typedef struct rect{
	u8 x, y, w, h;
} rect;

typedef struct{
	char* name; //to remove raw image identifier
	u8 id;
	u16 iid; //image identifier
	u16 flags; //image flags
	rect is; //imagespace
	SDL_Rect pos; //to remove SDL_rect imagespace
} image;

typedef struct{
	char* name;
	char* text;
	SDL_Color color;
	SDL_Rect pos;
} textbox;

typedef struct{
	image background;
	image images[255];
	textbox textbox;
} scene;

#endif