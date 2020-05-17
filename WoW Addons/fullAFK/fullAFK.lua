local main = CreateFrame("Frame", "FullAFK");
main:RegisterEvent("PLAYER_ENTERING_WORLD");
local following = false;
local player_name = nil;

local function follow_player()
    if(following) then
        FollowUnit(player_name);
    end
    C_Timer.After(5, follow_player);
end

local function afk()
    follow_player();
end

SLASH_LEECH1 = "/leech";
SLASH_STOPLEECH1 = "/stopleech";

SlashCmdList.LEECH = function(input)
    player_name = input;
    following = true;
    follow_player();
end

SlashCmdList.STOPLEECH = function()
    following = false;
    DEFAULT_CHAT_FRAME:AddMessage ( "YOU HAVE NOW STOPPED LEECHING :)"  , 1.0 , 0.84 , 0 );
end

main:SetScript("OnEvent", afk);