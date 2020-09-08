local WHOLE_MSG_TRIGGERS = { -- These will only match the whole message
"org",
"uc",
"tb",
"water",
"food",
"port"
}

local PARTIAL_MSG_TRIGGERS = { -- These will match parts of the message
"org",
"uc",
"tb",
"food",
"water",
"port"
}

local ipairs = ipairs
local strfind = string.find

MAGEINVITER_ENABLED = false

for i, trigger in ipairs(WHOLE_MSG_TRIGGERS) do
	WHOLE_MSG_TRIGGERS[i] = "^" .. trigger .. "$"
end

local function isMatch(msg)
	if(strfind(msg, "wtb")) then
		msg = string.gsub(msg, "wtb", "");
	end
	
	for _, trigger in ipairs(PARTIAL_MSG_TRIGGERS) do
		if (strfind(msg, trigger) and not(strfind(msg, "sell")) and not(strfind(msg, "wts"))) then
			return true
		end
	end

	return false
end

local function isFullMatch(msg)
	for _, trigger in ipairs(WHOLE_MSG_TRIGGERS) do
		if strfind(msg, trigger) then
			return true
		end
	end
	
	return false
end

local function filter(self, event, msg, author, ...)
	-- NOTE: I don't think this Classic API supports grabbing number of group members. This is commented out until it is supported.
	-- isFullMessage(author)
	 -- if isFull() then
	  -- SendChatMessage(isFullMessage(author), "WHISPER", nil, author)
	 -- end
	local message = string.lower(msg);

	if isMatch(message) then
		InviteUnit(author)
	end

	if isFullMatch(message) then
		InviteUnit(author)
	end

end

SLASH_MAGEINVITE1 = "/mageinvite"

SlashCmdList.MAGEINVITE = function(input)
	if (MAGEINVITER_ENABLED) then
		MAGEINVITER_ENABLED = false;
		ChatFrame_RemoveMessageEventFilter("CHAT_MSG_WHISPER", filter)
		ChatFrame_RemoveMessageEventFilter("CHAT_MSG_SAY", filter)
		ChatFrame_RemoveMessageEventFilter("CHAT_MSG_YELL", filter)
		print("MageInvite: Disabled")
	else
		MAGEINVITER_ENABLED = true;
		ChatFrame_AddMessageEventFilter("CHAT_MSG_WHISPER", filter)
		ChatFrame_AddMessageEventFilter("CHAT_MSG_SAY", filter)
		ChatFrame_AddMessageEventFilter("CHAT_MSG_YELL", filter)
		print("MageInvite: Enabled")
	end
end