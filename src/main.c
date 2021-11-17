#include "main.h"
#include "render.h"

/*typedef struct script{
	char* data;
	char* name;
} script;*/

char changed;
layout current;
char* script;
u16 si; //script iteration
u16 sb = 0;
TTF_Font* font;

char GETCURRCMD(){
	si++;
	return GETCMD(script, si--);
}

void dumb_init(){
	SDL_SetRenderDrawColor(renderer, 255, 128, 255, 255);
	script = open_script("scrpt/test.bin");
	current.images[0].name = "img/1615350775259small.jpg";
	current.images[0].pos = quick_rect(128, 128, 121, 121);
	current.images[1].name = "img/1615350775259small.jpg";
	current.images[1].pos = quick_rect(0, 128, 121, 121);
	current.text1.text = "fuck";
	current.text1.pos = quick_rect(128, 128, 32, 32);
	changed = 1;
}

void game_loop(){
	for(;;){
		SDL_Event event;
		SDL_PollEvent(&event);
		u8 quit = 0;

		switch (event.type) {
			case SDL_QUIT: quit = 1; break;
			case SDL_MOUSEBUTTONDOWN: sb++; break;
		}

		if (quit == 1) break;
		if (changed){
			SDL_RenderClear(renderer);
			for(u8 i = 0; current.images[i].pos.w != 0; i++)
				render_floating_image_rect(current.images[i].name, current.images[i].pos);
			render_floating_text_rect(current.text1.text, current.text1.pos);
			SDL_RenderPresent(renderer);
			changed = 0;
		}
	}
}

void init(){
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, SDL_WINDOW_RESIZABLE);
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_GetWindowSize(window, &ws.x, &ws.y);
}

void setup(){
	font = TTF_OpenFont("fnt/ShortBaby.ttf", 64);
	if (font == NULL) fprintf(stderr, FNT_ERR);
}

int main(){
	init();
	setup();
	dumb_init();
	game_loop();
	return 0;
}