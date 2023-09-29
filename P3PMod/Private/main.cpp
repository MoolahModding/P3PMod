#include "main.h"
#include "uestructs.h"
#include <UnrealDef.hpp>
#include <World.hpp>
#include <DynamicOutput/Output.hpp>

using namespace RC;

namespace P3P
{
    P3PMod::P3PMod()
    {
        ModVersion = STR("0.1");
        ModName = STR("P3PMod");
        ModAuthors = STR("Narknon");
        ModDescription = STR("");
        Output::send<LogLevel::Warning>(STR("[P3PMod]: Init.\n"));
    }

    bool P3PMod::StartListen(Unreal::UWorld* World)
    {
    
        FURL WorldFURL{World->GetFullName().c_str()};
        UObject* NetDriver = *World->GetValuePtrByPropertyName<UObject*>(STR("NetDriver"));
        if (NetDriver)
        {
            Output::send<LogLevel::Error>(STR("NetDriver already exists, unable to start listen server.\n"));
            return false;
        }
        else
        {
            WorldFURL.Op = {FString(STR("listen"))};
            UObject* GameEngine = UObjectGlobals::FindFirstOf(STR("GameEngine"));
            UClass* NetDriverClass = UObjectGlobals::StaticFindObject<UClass*>(nullptr, nullptr, STR("/Script/AccelByteNetworkUtilities.IpNetDriverAccelByte"));
            NetDriver = UObjectGlobals::StaticConstructObject({NetDriverClass, GameEngine});
            if (NetDriver == nullptr)
            {
                Output::send<LogLevel::Error>(STR("Failed to create NetDriver, unable to start listen server.\n"));
                return false;
            }

            InitListenParms InitParams = {World, WorldFURL, false, FString(STR("InitError"))};
            UFunction* InitListen = NetDriver->GetFunctionByNameInChain(STR("InitListen"));
            NetDriver->ProcessEvent(InitListen, &InitParams);
            return true;
        }

        return false;
    }
}




    




