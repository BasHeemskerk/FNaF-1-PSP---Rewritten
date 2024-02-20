#include "included/animatronic.hpp"

namespace chica_script{
    int delay = 432;
    int level = 0;

    void ai_init(int input_level){
        switch (save_system::saved_night){
            case 1:
                level = 0;
                debug("chica level = 0");
                break;
            case 2:
                level = 5;
                debug("chica level = 5");
                break;
            case 3:
                level = 4;
                debug("chica level = 4");
                break;
            case 4:
                level = 4;
                debug("chica level = 4");
                break;
            case 5:
                level = 7;
                debug("chica level = 7");
                break;
            case 6:
                level = 12;
                debug("chica level = 12");
                break;
            case 7:
                level = input_level;
                debug("chica level = custom");
                break;
        }
    }

    void debug(const char *msg){
        std::cout << msg << std::endl;
    }

    void ai_loop(){
        
    }
}