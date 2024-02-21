#include "included/animatronic_manager.hpp"

namespace foxy_script{
    int delay = 600;
    int delay_b;
    int level = 0;

    int position = 0;
    int previous_position;
    int maximum_position = 3;

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

        delay_b = delay;
    }

    void debug(const char *msg){
        std::cout << msg << std::endl;
    }

    int random_number(){
        int rand_number;
        rand_number = rand() % 20;
        rand_number += 1;
        return rand_number;
    }

    bool movement_opportunity(){
        if (random_number() < level){
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
                debug("foxy moved!");
            }
            else{
                debug("foxy was not allowed to move!");
            }

            delay = delay_b;
        }
        else{
            delay -= 1;
        }
    }
}