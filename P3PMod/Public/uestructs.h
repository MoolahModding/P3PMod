#pragma once

using namespace RC;

namespace P3P
{
    struct FURL
    {
        // Protocol, i.e. "unreal" or "http".
        Unreal::FString Protocol = Unreal::FString(STR("unreal"));

        // Optional hostname, i.e. "204.157.115.40" or "unreal.epicgames.com", blank if local.
        Unreal::FString Host = Unreal::FString(STR(""));

        // Optional host port.
        Unreal::int32 Port = 27015;
    
        Unreal::int32 Valid = 1;

        // Map name, i.e. "SkyCity", default is "Entry".
        Unreal::FString Map;

        // Optional place to download Map if client does not possess it
        Unreal::FString RedirectURL;

        // Options.
        Unreal::TArray<Unreal::FString> Op;

        // Portal to enter through, default is "".
        Unreal::FString Portal = Unreal::FString(STR(""));

        FURL( const Unreal::TCHAR* Filename=nullptr )
        {
            Map = Unreal::FString(Filename);
        }
        
    };

    struct InitListenParms
    {
        Unreal::UWorld* World;
        FURL WorldFURL;
        bool bReuseAddressandPort = false;
        Unreal::FString InitError = Unreal::FString(STR("Error"));
    };
}