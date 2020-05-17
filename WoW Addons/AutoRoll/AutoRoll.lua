--Author: Jerryatric
--Version: 1.0
--This addon will automatically Need or Greed roll on all coins and bijous in ZG

local main = CreateFrame("Frame", "AutoNeedZG");
local setting = 1
main:RegisterEvent("START_LOOT_ROLL");

function main:START_LOOT_ROLL(rollID)
	local _, name, _, _, _, canNeed, canGreed, canDisenchant, reasonNeed, reasonGreed, reasonDisenchant = GetLootRollItemInfo(rollID);

    local items = {"Zulian Coin", "Razzashi Coin", "Hakkari Coin", "Sandfury Coin", "Skullsplitter Coin", "Bloodscalp Coin", "Gurubashi Coin", "Vilebranch Coin", "Witherbark Coin", "Red Hakkari Bijou", "Green Hakkari Bijou", "Blue Hakkari Bijou", "Purple Hakkari Bijou", "Bronze Hakkari Bijou", "Silver Hakkari Bijou", "Gold Hakkari Bijou", "Orange Hakkari Bijou", "Yellow Hakkari Bijou"}

    if(canNeed) then
        for _,v in ipairs(items) do
            if (string.match(name,v) and setting == 1) then
                RollOnLoot(rollID, 1); -- need
            end

            if (string.match(name,v) and setting == 2) then
                RollOnLoot(rollID, 2); -- greed
            end
        end
	end
end

SLASH_NEED1 = "/need";
SLASH_GREED1 = "/greed";

SlashCmdList.NEED = function(input)
    DEFAULT_CHAT_FRAME:AddMessage ( "NOW WILL AUTOMATICALLY NEED ON COINS AND BIJOUS"  , 1.0 , 0.84 , 0 );
    setting = 1;
end

SlashCmdList.GREED = function(input)
    DEFAULT_CHAT_FRAME:AddMessage ( "NOW WILL AUTOMATICALLY GREED ON COINS AND BIJOUS"  , 1.0 , 0.84 , 0 );
    setting = 2;
end

main:SetScript("OnEvent", function(self,event,...) if(main[event])then main[event](self,...); end end);