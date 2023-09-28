#include "main.h"

#include <UnrealDef.hpp>
#include <World.hpp>
#include <DynamicOutput/Output.hpp>

using namespace RC;

P3PMod::P3PMod()
{
    ModVersion = STR("0.1");
    ModName = STR("P3PMod");
    ModAuthors = STR("Narknon");
    ModDescription = STR("");
    Output::send<LogLevel::Warning>(STR("[P3PMod]: Init.\n"));
}

bool P3PMod::StartListen(Unreal::UWorld* world)
{
    UObject* NetDriver = *world->GetValuePtrByPropertyName<UObject*>(STR("NetDriver"));
    if (NetDriver)
    {
        Output::send<LogLevel::Error>(STR("NetDriver already exists, unable to start listen server.\n"));
        return false;
    }
    else
    {
        UObject* GameEngine = UObjectGlobals::FindFirstOf(STR("GameEngine"));
        UClass* NetDriverClass = UObjectGlobals::StaticFindObject<UClass*>(nullptr, nullptr, STR("/Script/AccelByteNetworkUtilities.IpNetDriverAccelByte"));
        NetDriver = UObjectGlobals::StaticConstructObject({NetDriverClass, GameEngine});
        
    }
    

    
    
}



    




