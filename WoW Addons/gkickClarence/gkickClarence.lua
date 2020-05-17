local frame = CreateFrame("Frame");
frame:RegisterEvent("CHAT_MSG_LOOT");

local function filter(self, event, msg)

    local items = {"Nemesis Bracers", "Nemesis Belt", "Nemesis Boots", "Nemesis Gloves", "Nemesis Spaulders", "Nemesis Robes"}

    local itemLink = string.match(msg,"|%x+|Hitem:.-|h.-|h|r")
    local itemString = string.match(itemLink, "item[%-?%d:]+")
    local item_name = GetItemInfo(itemString);

    for _,v in ipairs(items) do
        if (string.match(item_name,v)) then
            GuildUninvite("Clarencexd");
        end
    end

end

frame:SetScript("OnEvent", filter);