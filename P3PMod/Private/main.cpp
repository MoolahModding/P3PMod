#include <main.h>

#include <DynamicOutput/Output.hpp>


namespace RC
{
    P3PMod::P3PMod()
    {
        ModVersion = STR("0.1");
        ModName = STR("P3PMod");
        ModAuthors = STR("Narknon");
        ModDescription = STR("");
        Output::send<LogLevel::Warning>(STR("[P3PMod]: Init.\n"));
    }
    
    void P3PMod::StartListen()
    {
        
    }
    
}


    




