local WHOLE_MSG_TRIGGERS = { -- These will only match the whole message
}

local PARTIAL_MSG_TRIGGERS = { -- These will match parts of the message
"wtb buff",
"wtb boof",
"wtb trib",
"wtb dm",
"lf dmt",
"lf buff",
"lf trib",
"lf dm buff",
"lf dmn buff",
"anyone selling buff",
"anyone selling dm",
"anyone selling trib"
}

local ipairs = ipairs
local strfind = string.find

HUNTERINVITER_ENABLED = false
SUMMON_ON = false
PORT_ON = false

for i, trigger in ipairs(WHOLE_MSG_TRIGGERS) do
	WHOLE_MSG_TRIGGERS[i] = "^" .. trigger .. "$"
end

local function isMatch(msg)
	for _, trigger in ipairs(PARTIAL_MSG_TRIGGERS) do
		if strfind(msg, trigger) then
			if (strfind(msg, "port") and not(PORT_ON)) then
				return false
			elseif (strfind(msg, "summon") and not(SUMMON_ON)) then
				return false
			else
				return true
			end
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

SLASH_HUNTERINVITE1 = "/hunterinvite"
SLASH_SUMMON1 = "/summon"
SLASH_PORT1 = "/port"

SlashCmdList.SUMMON = function(input)
	if(SUMMON_ON) then
		SUMMON_ON = false
	else
		SUMMON_ON = true
	end
end

SlashCmdList.PORT = function(input)
	if(PORT_ON) then
		PORT_ON = false
	else
		PORT_ON = true
	end
end

SlashCmdList.HUNTERINVITE = function(input)
	if (HUNTERINVITER_ENABLED) then
		HUNTERINVITER_ENABLED = false;
		ChatFrame_RemoveMessageEventFilter("CHAT_MSG_WHISPER", filter)
		ChatFrame_RemoveMessageEventFilter("CHAT_MSG_CHANNEL", filter)
		print("HunterInvite: Disabled")
	else
		HUNTERINVITER_ENABLED = true;
		ChatFrame_AddMessageEventFilter("CHAT_MSG_WHISPER", filter)
		ChatFrame_AddMessageEventFilter("CHAT_MSG_CHANNEL", filter)
		print("HunterInvite: Enabled")
	end
end