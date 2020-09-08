local main = CreateFrame("Frame", "AutoRollFrame");
local setting = 1;
main:RegisterEvent("START_LOOT_ROLL");

function main:START_LOOT_ROLL(rollID)
	local _, name, _, _, _, canNeed, canGreed, canDisenchant, reasonNeed, reasonGreed, reasonDisenchant = GetLootRollItemInfo(rollID);

    local items = {"Zulian Coin", "Razzashi Coin", "Hakkari Coin", "Sandfury Coin", "Skullsplitter Coin", 
                   "Bloodscalp Coin", "Gurubashi Coin", "Vilebranch Coin", "Witherbark Coin", "Red Hakkari Bijou", 
                   "Green Hakkari Bijou", "Blue Hakkari Bijou", "Purple Hakkari Bijou", "Bronze Hakkari Bijou", "Silver Hakkari Bijou", 
                   "Gold Hakkari Bijou", "Orange Hakkari Bijou", "Yellow Hakkari Bijou", "Bone Scarab", "Bronze Scarab", "Clay Scarab", 
                   "Crystal Scarab", "Gold Scarab", "Ivory Scarab", "Silver Scarab", "Stone Scarab"}

    if(canNeed) then
        for _,v in ipairs(items) do
            if (string.match(name,v)) then
                RollOnLoot(rollID, setting); -- setting == 1 NEED | setting == 2 GREED | setting == 0 PASS
            end
        end
	end
end

SLASH_NEED1 = "/need";
SLASH_GREED1 = "/greed";
SLASH_PASS1 = "/pass";

SlashCmdList.NEED = function(input)
    DEFAULT_CHAT_FRAME:AddMessage ( "NOW WILL AUTOMATICALLY NEED ON COINS AND BIJOUS"  , 1.0 , 0.84 , 0 );
    setting = 1;
end

SlashCmdList.GREED = function(input)
    DEFAULT_CHAT_FRAME:AddMessage ( "NOW WILL AUTOMATICALLY GREED ON COINS AND BIJOUS"  , 1.0 , 0.84 , 0 );
    setting = 2;
end

SlashCmdList.PASS = function(input)
    DEFAULT_CHAT_FRAME:AddMessage ( "NOW WILL AUTOMATICALLY PASS ON COINS AND BIJOUS"  , 1.0 , 0.84 , 0 );
    setting = 0;
end

main:SetScript("OnEvent", function(self,event,...) if(main[event])then main[event](self,...); end end);