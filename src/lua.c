#include "lua.h"
#include "main.h"
#include "render.h"
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int set_img(lua_State* L){
	//activeScene.images[lua_tointeger(L, 1)].name = strdup(lua_tostring(L, 2));
	activeScene.images[lua_tointeger(L, 1)].id = lua_tointeger(L, 2);
	
	return 0;
}

int load_img(lua_State* L){
	images[lua_tointeger(L, 1)] = IMG_Load(lua_tostring(L, 2));

	return 0;
}

int set_pos(lua_State* L){
	activeScene.images[lua_tointeger(L, 1)].pos = quick_rect(lua_tointeger(L, 2), lua_tointeger(L, 3), lua_tointeger(L, 4), lua_tointeger(L, 5));
	
	return 0;
}

int set_text(lua_State* L){
	activeScene.textbox.text = strdup(lua_tostring(L, 1)); //make my own strdup function so i can use c99
	
	return 0;
}

int set_text_pos(lua_State* L){
	activeScene.textbox.pos = quick_rect(lua_tointeger(L, 1), lua_tointeger(L, 2), lua_tointeger(L, 3), lua_tointeger(L, 4));
	
	return 0;
}

int set_render_color(lua_State* L){
	SDL_SetRenderDrawColor(renderer, lua_tointeger(L, 1), lua_tointeger(L, 2), lua_tointeger(L, 3), lua_tointeger(L, 4));
	
	return 0;
}

int set_text_color(lua_State* L){
	SDL_Color color = {lua_tointeger(L, 1), lua_tointeger(L, 2), lua_tointeger(L, 3), lua_tointeger(L, 4)};
	activeScene.textbox.color = color;
	
	return 0;
}

void register_lua_functions(lua_State* L){
	lua_register(L, "set_img", set_img);
	lua_register(L, "load_img", load_img);
	lua_register(L, "set_pos", set_pos);
	lua_register(L, "set_text", set_text);
	lua_register(L, "set_text_pos", set_text_pos);
	lua_register(L, "set_render_color", set_render_color);
	lua_register(L, "set_text_color", set_text_color);
}