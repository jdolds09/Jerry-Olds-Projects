local WHOLE_MSG_TRIGGERS = { -- These will only match the whole message
"water",
"Water",
"WATER",

"food",
"Food",
"FOOD",

"org",
"Org",
"ORG",

"tb",
"Tb",
"TB",

"UC",
"uc",
"Uc",
}

local PARTIAL_MSG_TRIGGERS = { -- These will match parts of the message
"org pls",
"tb pls",
"uc pls",
"TB pls",
"UC pls",
"org plz",
"tb plz",
"TB plz",
"UC plz",
"org please",
"tb please",
"TB please",
"uc please",
"UC please",

"wtb port to org pls",
"wtb port to tb pls",
"wtb port to uc pls",
"wtb port to UC pls",
"wtb port to tb pls",
"wtb port to TB pls",
"wtb port to org plz",
"wtb port to tb plz",
"wtb port to uc plz",
"wtb port to UC plz",
"wtb port to tb plz",
"wtb port to TB plz",
"wtb port to org please",
"wtb port to tb please",
"wtb port to uc please",
"wtb port to UC please",
"wtb port to tb please",
"wtb port to TB please",
"WTB port to org pls",
"WTB port to tb pls",
"WTB port to uc pls",
"WTB port to UC pls",
"WTB port to tb pls",
"WTB port to TB pls",
"WTB water pls",
"WTB port to org plz",
"WTB port to tb plz",
"WTB port to uc plz",
"WTB port to UC plz",
"WTB port to tb plz",
"WTB port to TB plz",
"WTB water plz",
"WTB port to org please",
"WTB port to tb please",
"WTB port to uc please",
"WTB port to UC please",
"WTB port to tb please",
"WTB port to TB please",
"WTB water please",

"wtb mage services",
"WTB mage services",

"wtb water and port to org",
"wtb water and port to TB",
"wtb water and port to UC",
"wtb water and port to uc",
"wtb water and port to tb",
"WTB water and port to org",
"WTB water and port to TB",
"WTB water and port to UC",
"WTB water and port to uc",
"WTB water and port to tb",

"org port",
"Org port",
"ORG port",
"org Port",
"Org Port",
"ORG Port",
"org PORT",
"Org PORT",
"ORG PORT",

"tb port",
"Tb port",
"TB port",
"tb Port",
"Tb Port",
"TB Port",
"tb PORT",
"Tb PORT",
"TB PORT",

"uc port",
"Uc port",
"UC port",
"uc Port",
"Uc Port",
"UC Port",
"uc PORT",
"Uc PORT",
"UC PORT",

"wtb water",
"Wtb water",
"WTB water",
"wtb Water",
"Wtb Water",
"WTB Water",
"wtb WATER",
"Wtb WATER",
"WTB WATER",

"wtb food",
"Wtb food",
"WTB food",
"wtb Food",
"Wtb Food",
"WTB Food",
"wtb FOOD",
"Wtb FOOD",
"WTB FOOD",

"wtb mage water",
"Wtb mage water",
"WTB mage water",
"wtb Mage Water",
"Wtb Mage Water",
"WTB Mage Water",
"WTB MAGE WATER",
"wtb 6 stacks of water",
"wtb 6 stacks water",
"wtb 55 water",
"WTB 55 WATER",
"WTB 55 MAGE WATER",
"wtb 55 mage water",

"wtb org port",
"Wtb org port",
"WTB org port",
"wtb org Port",
"Wtb org Port",
"WTB org Port",
"wtb Org port",
"Wtb Org port",
"WTB Org port",
"wtb Org Port",
"Wtb Org Port",
"WTB Org Port",
"wtb ORG port",
"Wtb ORG port",
"WTB ORG port",
"wtb ORG Port",
"Wtb ORG Port",
"WTB ORG Port",

"lf org port",
"Lf org port",
"LF org port",
"lf org Port",
"Lf org Port",
"LF org Port",
"lf Org port",
"Lf Org port",
"LF Org port",
"lf Org Port",
"Lf Org Port",
"LF Org Port",
"lf ORG port",
"Lf ORG port",
"LF ORG port",
"lf ORG Port",
"Lf ORG Port",
"LF ORG Port",
"lf ORG PORT",
"Lf ORG PORT",
"LF ORG PORT",

"lf port org",
"lf port to org",
"LF port org",
"lf port to org",
"lf port Org",
"lf port to Org",
"LF port Org",
"LF port to Org",

"lf uc port",
"Lf uc port",
"LF uc port",
"lf uc Port",
"Lf uc Port",
"LF uc Port",
"lf Uc port",
"Lf Uc port",
"LF Uc port",
"lf Uc Port",
"Lf Uc Port",
"LF Uc Port",
"lf UC port",
"Lf UC port",
"LF UC port",
"lf UC Port",
"Lf UC Port",
"LF UC Port",
"lf UC PORT",
"Lf UC PORT",
"LF UC PORT",

"lf port uc",
"lf port to uc",
"lf port UC",
"lf port to UC",
"LF port uc",
"LF port to uc",
"LF port UC",
"LF port to UC",

"lf tb port",
"Lf tb port",
"LF tb port",
"lf tb Port",
"Lf tb Port",
"LF tb Port",
"lf Tb port",
"Lf Tb port",
"LF Tb port",
"lf Tb Port",
"Lf Tb Port",
"LF Tb Port",
"lf TB port",
"Lf TB port",
"LF TB port",
"lf TB Port",
"Lf TB Port",
"LF TB Port",

"lf port tb",
"lf port to tb",
"lf port TB",
"lf port to TB",
"LF port tb",
"LF port to tb",
"LF port TB",
"LF port to TB",


"wtb org",
"Wtb org",
"WTB org",
"wtb Org",
"Wtb Org",
"WTB Org",
"wtb ORG",
"Wtb ORG",
"WTB ORG",

"wtb port",
"Wtb port",
"WTB port",
"wtb Port",
"Wtb Port",
"WTB Port",
"wtb PORT",
"Wtb PORT",
"WTB PORT",

"wtb port org",
"wtb port to org",
"wtb port to Org",
"WTB port to org",
"WTB port to Org",
"Wtb port org",
"WTB port org",
"wtb port Org",
"Wtb port Org",
"WTB port Org",
"wtb port ORG",
"Wtb port ORG",
"WTB port ORG",
"wtb Port org",
"Wtb Port org",
"WTB Port org",
"wtb Port Org",
"Wtb Port Org",
"WTB Port Org",
"wtb Port ORG",
"Wtb Port ORG",
"WTB Port ORG",
"wtb PORT org",
"Wtb PORT org",
"WTB PORT org",
"wtb PORT Org",
"Wtb PORT Org",
"WTB PORT Org",
"wtb PORT ORG",
"Wtb PORT ORG",
"WTB PORT ORG",

"wtb port tb",
"Wtb port tb",
"WTB port tb",
"wtb port Tb",
"Wtb port Tb",
"WTB port Tb",
"wtb port TB",
"Wtb port TB",
"WTB port TB",
"wtb Port TB",
"Wtb Port tb",
"WTB Port tb",
"wtb Port Tb",
"Wtb Port Tb",
"WTB Port Tb",
"wtb Port TB",
"Wtb Port TB",
"WTB Port TB",
"wtb PORT tb",
"Wtb PORT tb",
"WTB PORT tb",
"wtb PORT Tb",
"Wtb PORT Tb",
"WTB PORT Tb",
"wtb PORT TB",
"Wtb PORT TB",
"WTB PORT TB",


"wtb tb port",
"wtb port to tb",
"wtb port to TB",
"WTB port to tb",
"WTB port to TB",
"Wtb tb port",
"WTB tb port",
"wtb tb Port",
"Wtb tb Port",
"WTB tb Port",
"wtb tb PORT",
"Wtb tb PORT",
"WTB tb PORT",
"wtb Tb port",
"Wtb Tb port",
"WTB Tb port",
"wtb Tb Port",
"Wtb Tb Port",
"WTB Tb Port",
"wtb Tb PORT",
"Wtb Tb PORT",
"WTB Tb PORT",
"wtb TB port",
"Wtb TB port",
"WTB TB port",
"wtb TB Port",
"Wtb TB Port",
"WTB TB Port",
"wtb TB PORT",
"Wtb TB PORT",
"WTB TB PORT",

"wtb tb",
"Wtb tb",
"WTB tb",
"wtb TB",
"Wtb TB",
"WTB TB",
"wtb Tb",
"Wtb Tb",
"WTB Tb",

"wtb UC port",
"wtb port to uc",
"wtb port to UC",
"WTB port to uc",
"WTB port to UC",
"Wtb UC port",
"WTB UC port",
"wtb UC Port",
"Wtb UC Port",
"WTB UC Port",
"wtb UC PORT",
"Wtb UC PORT",
"WTB UC PORT",
"wtb Uc port",
"Wtb Uc port",
"WTB Uc port",
"wtb Uc Port",
"Wtb Uc Port",
"WTB Uc Port",
"wtb Uc PORT",
"Wtb Uc PORT",
"WTB Uc PORT",
"wtb uc port",
"Wtb uc port",
"WTB uc port",
"wtb uc Port",
"Wtb uc Port",
"WTB uc Port",
"wtb uc PORT",
"Wtb uc PORT",
"WTB uc PORT",

"wtb UC",
"Wtb UC",
"WTB UC",
"wtb uc",
"Wtb uc",
"WTB uc",
"wtb Uc",
"Wtb Uc",
"WTB Uc",
}

local ipairs = ipairs
local strfind = string.find

MAGEINVITER_ENABLED = true

for i, trigger in ipairs(WHOLE_MSG_TRIGGERS) do
	WHOLE_MSG_TRIGGERS[i] = "^" .. trigger .. "$"
end

local function isMatch(msg)
	for _, trigger in ipairs(PARTIAL_MSG_TRIGGERS) do
		if strfind(msg, trigger) then
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
	if isMatch(msg) then
		InviteUnit(author)
	end

	if isFullMatch(msg) then
		InviteUnit(author)
	end

end

ChatFrame_AddMessageEventFilter("CHAT_MSG_WHISPER", filter)
ChatFrame_AddMessageEventFilter("CHAT_MSG_SAY", filter)
ChatFrame_AddMessageEventFilter("CHAT_MSG_YELL", filter)

SLASH_MAGEINVITER1 = "/mageinviter"

SlashCmdList.MAGEINVITER = function(input)
	if MAGEINVITER_ENABLED then
		MAGEINVITER_ENABLED = false
		ChatFrame_RemoveMessageEventFilter("CHAT_MSG_WHISPER", filter)
		ChatFrame_RemoveMessageEventFilter("CHAT_MSG_SAY", filter)
		ChatFrame_RemoveMessageEventFilter("CHAT_MSG_YELL", filter)
		print("MageInviter: Disabled")
	else
		MAGEINVITER_ENABLED = true
		ChatFrame_AddMessageEventFilter("CHAT_MSG_WHISPER", filter)
		ChatFrame_AddMessageEventFilter("CHAT_MSG_SAY", filter)
		ChatFrame_AddMessageEventFilter("CHAT_MSG_YELL", filter)
		print("MageInviter: Enabled")
	end
end