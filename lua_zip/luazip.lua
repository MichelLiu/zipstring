local lua_zip = require "lua_zip"

local function zip_to_string(file_info)
    if "table" == type(file_info) then
        return lua_zip.zip_to_string(file_info)
    end
    return nil
end

return
{
    zip_to_string = zip_to_string;
}
