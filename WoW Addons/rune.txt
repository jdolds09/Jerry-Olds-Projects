local num_party_members = 0;
local player_list = {};
local runes = {};
local orbs = {};
local player_runes = 0;
local player_orbs = 0;
local frame = CreateFrame("Frame");
local frame2 = CreateFrame("Frame");
local runes_empty = true;
frame:RegisterEvent("GROUP_ROSTER_UPDATE");
frame2:RegisterEvent("CHAT_MSG_LOOT");


local function initRunes()
    for i=1,GetNumGroupMembers()-1 do
        runes[i] = 0;
    end
    player_runes = 0;

    for i=1,GetNumGroupMembers()-1 do
        orbs[i] = 0;
    end
    player_orbs = 0;
    runes_empty = false;
end

local function getPlayersInParty()
    if(UnitInParty("player") and not(UnitInRaid("player")) and GetNumGroupMembers() > 1) then
        for i=1,GetNumGroupMembers()-1 do
            if(UnitName("party"..i) ~= UnitName("player")) then
                if(player_list[i] == nil) then
                    table.insert(player_list,i,(UnitName("party"..i)));
                else
                    player_list[i] = nil
                    table.insert(player_list,i,(UnitName("party"..i)));
                end
            end
        end
        table.insert(player_list, (UnitName("player")));
    end
end

local function partyChange(self, event, ...)
    local in_party = false;

    if (not(UnitInRaid("player"))) then
        
        if (num_party_members == 0) then
            initRunes();
            getPlayersInParty();
        end

        if (num_party_members > GetNumGroupMembers()) then
            if (GetNumGroupMembers() < 2) then
                player_list = nil;
                num_party_members = 0;
            end

            for i=1,GetNumGroupMembers()-1 do
                in_party = false;
                for _,p in ipairs(player_list) do
                    if((UnitName("party"..i)) == p) then
                        in_party = true;
                    end

                    if(not(in_party)) then
                        table.remove(player_list, i);
                        table.remove(runes, i);
                        table.remove(orbs, i);
                    end
                end
            end
        end

        if ((num_party_members < GetNumGroupMembers()) and (num_party_members ~= 0)) then
            getPlayersInParty();
            table.insert(runes, 0);
            table.insert(orbs, 0);
        end

    end

    num_party_members = GetNumGroupMembers()
end

local function filter(self, event, msg, _, _, _, player)
    if(UnitInParty("player") and not(UnitInRaid("player"))) then
    
        local count = 0;
        local reset_runes = true;
        local zero_runes = 0;
        local same_runes = 0;
        getPlayersInParty();

        if (runes_empty) then
            initRunes();
        end

        local itemLink = string.match(msg,"|%x+|Hitem:.-|h.-|h|r")
        local itemString = string.match(itemLink, "item[%-?%d:]+")
        local item_name = GetItemInfo(itemString);

        if (string.match(item_name, "Dark Rune")) then
            if (UnitName("player") == player) then
                player_runes = player_runes + 1;
            else
                for i=1,GetNumGroupMembers()-1 do
                    if (player_list[i] == player) then
                        runes[i] = runes[i] + 1;
                    end
                end
            end
            if(GetNumGroupMembers() > 2) then
                for i=1,GetNumGroupMembers()-1 do
                    if(runes[i] == 0) then
                        zero_runes = zero_runes + 1;
                    end
                end

                if (player_runes == 0) then
                    zero_runes = zero_runes + 1;
                end

                for i=1,GetNumGroupMembers()-2 do
                    if((runes[i] == runes[i + 1]) and (runes[i] > 1)) then
                        same_runes = same_runes + 1
                    end
                end

                if (player_runes == runes[GetNumGroupMembers()-1] and player_runes > 1) then
                    same_runes = same_runes + 1
                end

                if((same_runes + zero_runes == GetNumGroupMembers()-1) and same_runes ~= 0) then
                    SendChatMessage("RESET", "PARTY");
                end
            end
        end

        if (string.match(item_name, "Righteous Orb")) then
            if (UnitName("player") == player) then
                player_orbs = player_orbs + 1;
            else
                for i=1,GetNumGroupMembers()-1 do
                    if (player_list[i] == player) then
                        orbs[i] = orbs[i] + 1;
                    end
                end
            end
            if(GetNumGroupMembers() > 2) then
                for i=1,GetNumGroupMembers()-1 do
                    if(orbs[i] == 0) then
                        zero_runes = zero_runes + 1;
                    end
                end

                if (player_orbs == 0) then
                    zero_runes = zero_runes + 1;
                end

                for i=1,GetNumGroupMembers()-2 do
                    if((orbs[i] == orbs[i + 1]) and (orbs[i] > 1)) then
                        same_runes = same_runes + 1
                    end
                end

                if (player_orbs == orbs[GetNumGroupMembers()-1] and player_orbs > 1) then
                    same_runes = same_runes + 1
                end

                if((same_runes + zero_runes == GetNumGroupMembers()-1) and same_runes ~= 0) then
                    SendChatMessage("RESET", "PARTY");
                end
            end
        end
    end
end

SLASH_DISPLAYORBS1 = "/orbs";
SLASH_DISPLAYRUNES1 = "/runes";
SLASH_GIVERUNE1 = "/giverune";
SLASH_ADDRUNE1 = "/addrune";
SLASH_SUBTRACTRUNE1 = "/subtractrune";
SLASH_GIVEORB1 = "/giveorb";
SLASH_ADDORB1 = "/addorb";
SLASH_SUBTRACTORB1 = "/subtractorb";
SLASH_RESET1 = "/resetrunes";

SlashCmdList.DISPLAYORBS = function(input)
    if(UnitInParty("player") and not(UnitInRaid("player"))) then
        getPlayersInParty();
        local player_name = UnitName("player");
        if(UnitInParty("player")) then
            SendChatMessage("ORBS", "PARTY");
            SendChatMessage("----------------------------------", "PARTY");
            for i=1,GetNumGroupMembers()-1 do
                SendChatMessage((UnitName("party" .. i)) .. ": " .. orbs[i], "PARTY");
            end
            SendChatMessage(UnitName("player") .. ": " .. player_orbs, "PARTY");
            SendChatMessage("----------------------------------", "PARTY");
        else
            DEFAULT_CHAT_FRAME:AddMessage ( "MUST BE IN PARTY TO USE RUNE TRACKER" , 1.0 , 0.84 , 0 );
        end
    else
        DEFAULT_CHAT_FRAME:AddMessage ( "MUST BE IN PARTY"  , 1.0 , 0.84 , 0 );
    end
end

SlashCmdList.DISPLAYRUNES = function(input)
    if(UnitInParty("player") and not(UnitInRaid("player"))) then
        getPlayersInParty();
        local player_name = UnitName("player");
        if(UnitInParty("player")) then 
            SendChatMessage("RUNES", "PARTY");
            SendChatMessage("----------------------------------", "PARTY");
            for i=1,GetNumGroupMembers()-1 do
                SendChatMessage((UnitName("party" .. i)) .. ": " .. runes[i], "PARTY");
            end
            SendChatMessage(UnitName("player") .. ": " .. player_runes, "PARTY");
            SendChatMessage("----------------------------------", "PARTY");
        else
            DEFAULT_CHAT_FRAME:AddMessage ( "MUST BE IN PARTY TO USE RUNE TRACKER" , 1.0 , 0.84 , 0 );
        end
    else
        DEFAULT_CHAT_FRAME:AddMessage ( "MUST BE IN PARTY"  , 1.0 , 0.84 , 0 );
    end
end

SlashCmdList.GIVERUNE = function(input)
    if (UnitInParty("player") and not(UnitInRaid("player"))) then

        getPlayersInParty();
        
        if(runes_empty) then
            initRunes();
        end

        if (UnitInParty("player")) then
            local giver;
            local receiver;
            local counter = 0;
            local arguments = { string.match(input, "^(%S*)%s*(.-)$") };

            for i,v in pairs(arguments) do
                if (v ~= nil and V ~= "") then
                    if (i == 1) then
                        giver = v;
                    else
                        receiver = v;
                    end
                end
            end

            giver = tonumber(giver);
            receiver = tonumber(receiver);

            if (giver == 5) then
                if(player_runes > 0) then
                    player_runes = player_runes - 1;

                    if (receiver == 5) then
                        player_runes = player_runes + 1;
            
                    elseif (receiver > 0 and receiver < 5) then
                        if (runes[giver] > -1) then
                            runes[receiver] = runes[receiver] + 1;
                        end
                        
                    else
                        DEFAULT_CHAT_FRAME:AddMessage ( "INVALID ARGUMENTS. PLEASE ENTER (1-5)."  , 1.0 , 0.84 , 0 );
                    end

                else
                    DEFAULT_CHAT_FRAME:AddMessage ( "MUST HAVE AT LEAST 1 RUNE DUMBASS" , 1.0 , 0.84 , 0 );
                end

            elseif (giver > 0 and giver < 5) then
                if(runes[giver] > 0) then
                    runes[giver] = runes[giver] - 1;

                    if (receiver == 5) then
                        if (runes[giver] > -1) then
                            player_runes = player_runes + 1;
                        end
            
                    elseif (receiver > 0 and receiver < 5) then
                        if (runes[giver] > -1) then
                            runes[receiver] = runes[receiver] + 1;
                        end
                        
                    else
                        DEFAULT_CHAT_FRAME:AddMessage ( "INVALID ARGUMENTS. PLEASE ENTER (1-5)."  , 1.0 , 0.84 , 0 );
                    end

                else
                    DEFAULT_CHAT_FRAME:AddMessage ( "MUST HAVE AT LEAST 1 RUNE DUMBASS" , 1.0 , 0.84 , 0 );
                end

            else
                DEFAULT_CHAT_FRAME:AddMessage ( "INVALID ARGUMENTS. PLEASE ENTER (1-5)." , 1.0 , 0.84 , 0 );
            end

        else
            DEFAULT_CHAT_FRAME:AddMessage ( "MUST BE IN PARTY TO USE RUNE TRACKER" , 1.0 , 0.84 , 0 );
        end
    else
        DEFAULT_CHAT_FRAME:AddMessage ( "MUST BE IN PARTY"  , 1.0 , 0.84 , 0 );
    end
end

SlashCmdList.ADDRUNE = function(input)
    if (UnitInParty("player") and not(UnitInRaid("player"))) then
        getPlayersInParty();

        local arguments = { string.match(input, "^(%S*)%s*(.-)$") };
        local receiver;
        local amount;

        if(runes_empty) then
            initRunes();
        end

        if (UnitInParty("player")) then

            for i,v in pairs(arguments) do
                if (v ~= nil and V ~= "") then
                    if (i == 1) then
                        receiver = v;
                    else
                        amount = v;
                    end
                end
            end

            receiver = tonumber(receiver);
            amount = tonumber(amount);

            if (receiver == 5) then
                player_runes = player_runes + amount;
        
            elseif (receiver > 0 and receiver < 5) then
                runes[receiver] = runes[receiver] + amount;
                    
            else
                DEFAULT_CHAT_FRAME:AddMessage ( "INVALID ARGUMENT. PLEASE ENTER (1-5)."  , 1.0 , 0.84 , 0 );
            end
        end
    else
        DEFAULT_CHAT_FRAME:AddMessage ( "MUST BE IN PARTY"  , 1.0 , 0.84 , 0 );
    end
end

SlashCmdList.SUBTRACTRUNE = function(input)
    if (UnitInParty("player") and not(UnitInRaid("player"))) then
        getPlayersInParty();

        local arguments = {string.match(input, "^(%S*)%s*(.-)$") };
        local receiver;
        local amount;

        if(runes_empty) then
            initRunes();
        end

        if (UnitInParty("player")) then

            for i,v in pairs(arguments) do
                if (v ~= nil and V ~= "") then
                    if (i == 1) then
                        receiver = v;
                    else
                        amount = v;
                    end
                end
            end

            receiver = tonumber(receiver);
            amount = tonumber(amount);

            if (receiver == 5) then
                player_orbs = player_orbs + amount;
        
            elseif (receiver > 0 and receiver < 5) then
                orbs[receiver] = orbs[receiver] + amount;
                    
            else
                DEFAULT_CHAT_FRAME:AddMessage ( "INVALID ARGUMENT. PLEASE ENTER (1-5)."  , 1.0 , 0.84 , 0 );
            end
        end
    else
        DEFAULT_CHAT_FRAME:AddMessage ( "MUST BE IN PARTY"  , 1.0 , 0.84 , 0 );
    end
end

SlashCmdList.ADDORB = function(input)
    if (UnitInParty("player") and not(UnitInRaid("player"))) then
        getPlayersInParty();

        if(runes_empty) then
            initRunes();
        end

        if (UnitInParty("player")) then

            input = tonumber(input);

            if (input == 5) then
                player_orbs = player_orbs + 1;
        
            elseif (input > 0 and input < 5) then
                orbs[input] = orbs[input] + 1;
                    
            else
                DEFAULT_CHAT_FRAME:AddMessage ( "INVALID ARGUMENT. PLEASE ENTER (1-5)."  , 1.0 , 0.84 , 0 );
            end
        end
    else
        DEFAULT_CHAT_FRAME:AddMessage ( "MUST BE IN PARTY"  , 1.0 , 0.84 , 0 );
    end
end

SlashCmdList.SUBTRACTORB = function(input)
    if (UnitInParty("player") and not(UnitInRaid("player"))) then
        getPlayersInParty();

        if(runes_empty) then
            initRunes();
        end

        if (UnitInParty("player")) then

            input = tonumber(input);

            if (input == 5) then
                player_orbs = player_orbs - 1;
        
            elseif (input > 0 and input < 5) then
                orbs[input] = orbs[input] - 1;
                    
            else
                DEFAULT_CHAT_FRAME:AddMessage ( "INVALID ARGUMENT. PLEASE ENTER (1-5)."  , 1.0 , 0.84 , 0 );
            end
        end
    else
        DEFAULT_CHAT_FRAME:AddMessage ( "MUST BE IN PARTY"  , 1.0 , 0.84 , 0 );
    end
end

SlashCmdList.GIVEORB = function(input)
    if (UnitInParty("player") and not(UnitInRaid("player"))) then
        getPlayersInParty();
        
        if(runes_empty) then
            initRunes();
        end

        if (UnitInParty("player")) then
            local giver;
            local receiver;
            local arguments = { string.match(input, "^(%S*)%s*(.-)$") };

            for i,v in pairs(arguments) do
                if (v ~= nil and V ~= "") then
                    if (i == 1) then
                        giver = v;
                    else
                        receiver = v;
                    end
                end
            end

            giver = tonumber(giver);
            receiver = tonumber(receiver);

            if (giver == 5) then
                if(player_orbs > 0) then
                    player_orbs = player_orbs - 1;

                    if (receiver == 5) then
                        player_orbs = player_orbs + 1;
            
                    elseif (receiver > 0 and receiver < 5) then
                        if (orbs[giver] > -1) then
                            orbs[receiver] = orbs[receiver] + 1;
                        end
                        
                    else
                        DEFAULT_CHAT_FRAME:AddMessage ( "INVALID ARGUMENTS. PLEASE ENTER (1-5)."  , 1.0 , 0.84 , 0 );
                    end

                else
                    DEFAULT_CHAT_FRAME:AddMessage ( "MUST HAVE AT LEAST 1 RUNE DUMBASS" , 1.0 , 0.84 , 0 );
                end

            elseif (giver > 0 and giver < 5) then
                if(orbs[giver] > 0) then
                    orbs[giver] = orbs[giver] - 1;

                    if (receiver == 5) then
                        if (orbs[giver] > -1) then
                            player_orbs = player_orbs + 1;
                        end
            
                    elseif (receiver > 0 and receiver < 5) then
                        if (orbs[giver] > -1) then
                            orbs[receiver] = orbs[receiver] + 1;
                        end
                        
                    else
                        DEFAULT_CHAT_FRAME:AddMessage ( "INVALID ARGUMENTS. PLEASE ENTER (1-5)."  , 1.0 , 0.84 , 0 );
                    end

                else
                    DEFAULT_CHAT_FRAME:AddMessage ( "MUST HAVE AT LEAST 1 RUNE DUMBASS" , 1.0 , 0.84 , 0 );
                end

            else
                DEFAULT_CHAT_FRAME:AddMessage ( "INVALID ARGUMENTS. PLEASE ENTER (1-5)." , 1.0 , 0.84 , 0 );
            end

        else
            DEFAULT_CHAT_FRAME:AddMessage ( "MUST BE IN PARTY TO USE RUNE TRACKER" , 1.0 , 0.84 , 0 );
        end
    else
        DEFAULT_CHAT_FRAME:AddMessage ( "MUST BE IN PARTY"  , 1.0 , 0.84 , 0 );
    end
end

SlashCmdList.RESET = function(input)
    if (UnitInParty("player") and not(UnitInRaid("player"))) then
        initRunes();
        DEFAULT_CHAT_FRAME:AddMessage ( "RUNES RESET" , 1.0 , 0.84 , 0 );
    else
        DEFAULT_CHAT_FRAME:AddMessage ( "MUST BE IN PARTY"  , 1.0 , 0.84 , 0 );
    end
end

frame:SetScript("OnEvent", partyChange);
frame2:SetScript("OnEvent", filter);