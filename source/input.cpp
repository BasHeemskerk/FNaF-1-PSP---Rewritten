#include "included/input.hpp"

namespace input{
    SceCtrlData ctrlData;

    int input_delay;
    int input_delay_backup;

    void debug(std::string debug_button){
        if (debug_button != ""){
            std::cout << debug_button << std::endl;
        }
    }

    void set_input_delay(int delay){
        input_delay = delay;
        input_delay_backup = delay;

        //maybe implement in the future
    }

    void input(){
        sceCtrlReadBufferPositive(&ctrlData, 1);
    }
}