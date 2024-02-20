#include "included/animatronic.hpp"

namespace bonnie_script{
    int delay = 389;
    int level = 0;

    void ai_init(int input_level){

        switch (save_system::saved_night){
            case 1:
                level = 0;
                debug("bonnie level = 0");
                break;
            case 2:
                level = 3;
                debug("bonnie level = 3");
                break;
            case 3:
                level = 0;
                debug("bonnie level = 0");
                break;
            case 4:
                level = 2;
                debug("bonnie level = 2");
                break;
            case 5:
                level = 5;
                debug("bonnie level = 5");
                break;
            case 6:
                level = 10;
                debug("bonnie level = 10");
                break;
            case 7:
                level = input_level;
                debug("bonnie level = custom");
                break;
        }
            
    }

    void debug(const char *msg){
        std::cout << msg << std::endl;
    }

    void ai_loop(){

    }
}