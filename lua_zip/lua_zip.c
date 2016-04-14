
#include <lua.h>
#include <lauxlib.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "zip.h"

static int l_zip_to_string (lua_State *L);

static const struct luaL_reg zip_lib[] = {
    {"zip_to_string", l_zip_to_string},
    {NULL, NULL}
};


int luaopen_lua_zip(lua_State *L) 
{
    luaL_openlib(L, "lua_zip", zip_lib, 0);
    return 1;
}


static int l_zip_to_string (lua_State *L)
{
    char **pBuf;
    size_t size = 0;
    char c = '\0';
    char *t;
    t = &c;
    pBuf = &t;

    struct zip_t *zip = zip_open(ZIP_DEFAULT_COMPRESSION_LEVEL, 0);
    // we should check if zip is NULL
    if(zip)
    {
        size_t bufsize = 0;
        lua_pushnil(L);
        while (lua_next(L, -2))
        {
            zip_entry_open(zip, lua_tostring(L, -2));
            {
                const char *pstr = lua_tolstring(L, -1, &bufsize);
                zip_entry_write(zip, pstr, bufsize*sizeof(char));
            }
            zip_entry_close(zip);
            lua_pop(L, 1);
        }
        // always remember to close and release resources 
        zip_close(zip, (void**)pBuf, &size);   
    }

    lua_pushlstring(L, *pBuf, size);
    free(*pBuf);
    *pBuf=NULL;
    return 1;
}
