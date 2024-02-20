#include "included/animatronic.hpp"

namespace freddy_script{
    int delay = 650;
    int max_level = 0;
    int act_level = 0;

    void ai_init(int input_level){
        switch (save_system::saved_night){
            case 1:
                max_level = 0;
                act_level = max_level;
                debug("freddy level = 0");
                break;
            case 2:
                max_level = 0;
                act_level = max_level;
                debug("freddy level = 0");
                break;
            case 3:
                max_level = randomize_ai_level();
                act_level = max_level;
                debug("freddy level = random (0 - 3)");
                break;
            case 4:
                max_level = 1;
                act_level = max_level;
                debug("freddy level = 1");
                break;
            case 5:
                max_level = 3;
                act_level = max_level;
                debug("freddy level = 3");
                break;
            case 6:
                max_level = 4;
                act_level = max_level;
                debug("freddy level = 4");
                break;
            case 7:
                max_level = input_level;
                act_level = max_level;
                debug("freddy level = custom");
                break;
        }
    }

    void debug(const char *msg){
        std::cout << msg << std::endl;
    }

    int randomize_ai_level(){
        int rand_level;
        rand_level = rand() % 3;
        return rand_level;
    }

    void ai_loop(){
        
    }
}