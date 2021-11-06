TARGET_EXEC := MVN
CC = gcc
INC_DIRS := /usr/include config
STDFLAGS   = -std=c99
LDFLAGS  = -lSDL2 -lSDL2_image
WARNINGFLAGS = -Wall -Wextra -Werror -Wno-unused-variable
OPTFLAGS = -Os
STATIC = #set to -static to compile statically