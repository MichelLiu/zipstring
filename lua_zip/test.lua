local lua_zip = require "luazip"
local t = {}
t["1.txt"] = "a"
t["2.txt"] = "b"

local str = lua_zip.zip_to_string(t)

local file=assert(io.open("1.zip","wb"))
file:write(str)
file:close()
