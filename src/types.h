#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_rect.h>

#ifndef TYPES
#define TYPES
#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t
#define u64 uint64_t

#define IB (1 << 0) //image background

typedef struct rect{
	u8 x, y, w, h;
} rect;

typedef struct{
	char* name; //to remove raw image identifier
	u16 iid; //image identifier
	u16 flags; //image flags
	rect is; //imagespace
	SDL_Rect pos; //to remove SDL_rect imagespace
} image;

typedef struct{
	char* text;
	rect is;
	SDL_Rect pos;
} text;

typedef struct{
	image background;
	image images[255];
	text text1;
	text text2;
} layout;

#endif