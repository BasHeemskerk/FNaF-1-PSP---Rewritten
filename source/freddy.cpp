#include "included/animatronic_manager.hpp"

namespace freddy_script{
    int delay = 700;
    int delay_b;
    int max_level = 0;
    int act_level = 0;

    int position = 0;
    int previous_position;
    int maximum_position = 4;

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

        delay_b = delay;
    }

    void debug(const char *msg){
        std::cout << msg << std::endl;
    }

    int randomize_ai_level(){
        int rand_level;
        rand_level = rand() % 3;
        return rand_level;
    }

    int random_number(){
        int rand_number;
        rand_number = rand() % 20;
        rand_number += 1;
        return rand_number;
    }

    bool movement_opportunity(){
        if (random_number() < act_level){
            return true;
        }
        else{
            return false;
        }
    }

    bool below_maximum_position(){
        if (position < maximum_position){
            return true;
        }
        else{
            return false;
        }
    }

    void move_animatronic(){
        previous_position = position;
        position += 1;
    }

    bool should_update_components(){
        if (position != previous_position){
            previous_position = position;
            return true;
        }
        else{
            return false;
        }
    }

    void ai_loop(){
        if (delay <= 0){
            
            if (movement_opportunity() == true && below_maximum_position() == true){
                move_animatronic();
                debug("freddy moved!");
            }
            else{
                debug("freddy was not allowed to move!");
            }

            delay = delay_b;
        }
        else{
            delay -= 1;
        }

        switch (save_system::saved_night){
            case 3:
                max_level = randomize_ai_level();
                act_level = max_level;
                break;
        }
    }
}