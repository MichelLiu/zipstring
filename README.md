# zipstring

## Description

Zipstring is a simple extending-embadded module to create zip files in memory, derived from Miniz.
Miniz is a lossless, high performance data compression library in a single source file. 

Zipstring provide a simple interface to append buffers or files to the current zip-entry.You can use lua_zip to extend your lua applications, or py_zip to extend you python applications, without any other dependencies.

## How to use

 - Python Extending:

    % git clone https://github.com/MichelLiu/zipstring.git
    % cd py_zip
    % python setup.py install
    % python ziptest.py

 - Lua Extending:

    % git clone https://github.com/MichelLiu/zipstring.git
    % cd lua_zip
    % make all && make install
    % lua test.lua

## Zip string Example

 - Python

```python
import py_zip

c={"a.txt":"1","b.txt":"2"}
t=py_zip.zip_to_string(c)

f=open("data.zip", "wb")
f.write(t)
f.close()
```

 - Lua

```lua
local lua_zip = require "luazip"
local t = {}
t["1.txt"] = "a"
t["2.txt"] = "b"

local str = lua_zip.zip_to_string(t)

local file=assert(io.open("1.zip","wb"))
file:write(str)
file:close()
```

## Author

Created by MichelLiu 

Source : https://github.com/MichelLiu/zipstring

Forked Source : https://github.com/kuba--/zip

## Credits

Based on ZipArchive: http://code.google.com/p/ziparchive/ 


## License

MIT License
