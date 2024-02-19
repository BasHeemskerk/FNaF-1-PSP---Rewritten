#include "included/disclaimer_basdev.hpp"

namespace disclaimer{
    std::string disclaimer[6];
    std::string website;

    void init_disclaimer(){

        pspDebugScreenSetTextColor(0x2333FF); //red

        website = "www.basdev.org";

        disclaimer[0] = "\n Hello and welcome to FNaF 1 PSP - V1.4.0. (rewritten)";
        disclaimer[1] = "\n\n This is a fan recreation of FNaF 1 for the PSP, written in C/C++.";
        disclaimer[2] = "\n\n\n FNaF 1 is owned and copyrighted by Scott Cawthon.";
        disclaimer[3] = "\n\n Recreated for the PSP by BasDEV - " + website + ".";
        disclaimer[4] = "\n\n\n Credits go out to all my fans and supporters.";
        disclaimer[5] = "\n\n\n Press x to continue to the game!";

        pspDebugScreenInit();
        for (int i=0; i<6; i++){
            pspDebugScreenPrintf(disclaimer[i].c_str());
        }
    }

    void exit_disclaimer(){
        pspDebugScreenClear();
    }
}