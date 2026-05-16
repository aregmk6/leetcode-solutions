function ConvertToCamelCase(str)
	local newStr = ""
	local f = false
	for i = 1, #str do
		-- same as str.byte(self, i)
		local curChar = str:byte(i)
		if curChar == string.byte('-') or curChar == string.byte('_') then
			f = true
		else
			if f == true then
				newStr = newStr .. string.upper(string.char(curChar))
				f = false
			else
				newStr = newStr .. string.char(curChar)
			end
		end
	end

	return newStr
end

return ConvertToCamelCase
