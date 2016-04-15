version=0.09

name=lua-zip
dist=$(name)-$(version)

LUA_VERSION =   5.1

CC = gcc
RM = rm -f

PREFIX ?=          /usr/local/nginx
LDFLAGS +=         -shared

LUA_INCLUDE_DIR ?= $(PREFIX)/include
LUA_LIB_DIR ?=     $(PREFIX)/lua/lib/lua/$(LUA_VERSION)

C_FLAGS ?= -Wall -Wpointer-arith -O2 -pipe -g -lm -D_REENTRANT -D_GUN_SOURCE #-D_USE_THREAD
override CFLAGS += -fPIC -I$(LUA_INCLUDE_DIR) 
#-I$(INC)

INSTALL ?= install

.PHONY: all clean dist lua_zip t


all: lua_zip.so

lua_zip.o: lua_zip.c zip.c

lua_zip.so: lua_zip.o zip.o
	$(CC) $(C_FLAGS) $(LDFLAGS) $^ -o $@ 

install:
	$(INSTALL) -d $(LUA_LIB_DIR)
	$(INSTALL) lua_zip.so $(LUA_LIB_DIR)
	$(INSTALL) luazip.lua $(LUA_LIB_DIR)        
clean:
	$(RM) *.so *.o
