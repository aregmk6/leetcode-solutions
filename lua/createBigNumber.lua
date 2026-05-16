function CreateBigNumber(num)
	local numStr = tostring(num)

	local arr = {}
	for i = 1, 10 do
		arr[i] = 0
	end

	for i = 1, #numStr do
		local n = numStr:byte(i) - string.byte("0")
		arr[n + 1] = arr[n + 1] + 1
	end

	local retNumStr = ""
	for i = #arr, 1, -1 do
		while arr[i] ~= 0 do
			retNumStr = retNumStr .. tostring(i - 1)
			arr[i] = arr[i] - 1
		end
	end

	return tonumber(retNumStr)
end

return CreateBigNumber
