#include "included/animatronic.hpp"

namespace foxy_script{
    int delay = 460;
    int level = 0;

    void ai_init(int input_level){
        switch (save_system::saved_night){
            case 1:
                level = 0;
                debug("foxy level = 0");
                break;
            case 2:
                level = 1;
                debug("foxy level = 1");
                break;
            case 3:
                level = 2;
                debug("foxy level = 2");
                break;
            case 4:
                level = 6;
                debug("foxy level = 6");
                break;
            case 5:
                level = 5;
                debug("foxy level = 5");
                break;
            case 6:
                level = 6;
                debug("foxy level = 6");
                break;
            case 7:
                level = input_level;
                debug("foxy level = custom");
                break;
        }
    }

    void debug(const char *msg){
        std::cout << msg << std::endl;
    }

    void ai_loop(){
        
    }
}