local frame = CreateFrame("Frame");
local frame2 = CreateFrame("Frame");
frame:RegisterEvent("PLAYER_ENTER_COMBAT");
frame2:RegisterEvent("UNIT_SPELLCAST_SENT");
local sunders = {};
local total_sunders = {};
local sunderers = {};
local exists = false;
local position = 0;
local temp_sunders = {};
local temp_total_sunders = {};
local temp_sunderers = {};
local temp;

local function detect()
    sunders = {};
end

local function add_sunder(self, event, name, spell_name, ...)
    if(spell_name == "Sunder Armor") then
        exists = false;

        for i, value in ipairs(sunderers) do
            if value == name then
                exists = true;
                position = i;
            end
        end

        if (exists == false) then
            table.insert(sunderers, name);
            table.insert(sunders, 1);
            table.insert(total_sunders, 1);
        
        else
            sunders[position] = sunders[position] + 1;
            total_sunders[position] = total_sunders[position] + 1;
        end
    end
end

SLASH_SUNDERS1 = "/sunders";
SLASH_TOTALSUNDERS1 = "/totalsunders";

SlashCmdList.SUNDERS = function(input)
    temp_sunders = sunders;
    temp_sunderers = sunderers;

    for i, value in ipairs(temp_sunders) do
        for j, value in ipairs(temp_sunderers - i - 1) do
            if(temp_sunders[j] < temp_sunders[j + 1]) then
                temp = temp_sunders[j];
                temp_sunders[j] = temp_sunders[j + 1];
                temp_sunders[j + 1] = temp;
                temp = temp_sunderers[j];
                temp_sunderers[j] = temp_sunderers[j + 1];
                temp_sunderers[j + 1] = temp;
            end
        end
    end

    SendChatMessage("SUNDERS:", "PARTY");
    for i, value in ipairs(temp_sunders) do
        SendChatMessage(i+1 .. ". " .. temp_sunderers[i] .. ": " .. temp_sunders[i]);
    end
end

SlashCmdList.TOTALSUNDERS = function(input)
    temp_total_sunders = total_sunders;
    temp_sunderers = sunderers;

    for i, value in ipairs(temp_total_sunders) do
        for j, value in ipairs(temp_sunderers - i - 1) do
            if(temp_total_sunders[j] < temp_total_sunders[j + 1]) then
                temp = temp_total_sunders[j];
                temp_total_sunders[j] = temp_total_sunders[j + 1];
                temp_total_sunders[j + 1] = temp;
                temp = temp_sunderers[j];
                temp_sunderers[j] = temp_sunderers[j + 1];
                temp_sunderers[j + 1] = temp;
            end
        end
    end

    SendChatMessage("TOTAL SUNDERS:", "PARTY");
    for i, value in ipairs(temp_total_sunders) do
        SendChatMessage(i+1 .. ". " .. temp_sunderers[i] .. ": " .. temp_total_sunders[i]);
    end
end

frame:SetScript("OnEvent", detect);
frame2:SetScript("OnEvent", add_sunder);