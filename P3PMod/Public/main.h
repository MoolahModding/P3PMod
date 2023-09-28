#pragma once
#include <Mod/CppUserModBase.hpp>
#include <Unreal/World.hpp>


/**
* P3PMod: UE4SS c++ mod class defintion
*/
class P3PMod : public RC::CppUserModBase {
public:
    
    P3PMod();
    
    ~P3PMod() override {
    }

    static bool StartListen(Unreal::UWorld* world);
};



#define MOD_EXPORT __declspec(dllexport) 
extern "C" {
    MOD_EXPORT RC::CppUserModBase* start_mod(){ return new RC::P3PMod(); }
    MOD_EXPORT void uninstall_mod(RC::CppUserModBase* mod) { delete mod; }
}