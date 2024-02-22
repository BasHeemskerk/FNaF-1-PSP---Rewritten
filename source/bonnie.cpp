#include "included/animatronic_manager.hpp"

namespace bonnie_script{
    int delay = 400;
    int delay_b;
    int level = 0;

    int position = 0;
    int previous_position;
    int maximum_position = 6;

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

    void increment_difficulty(){
        
    }

    void ai_loop(){
        if (delay <= 0){
            
            if (movement_opportunity() == true && below_maximum_position() == true){
                move_animatronic();
                debug("bonnie moved!");
            }
            else{
                debug("bonnie was not allowed to move!");
            }

            delay = delay_b;
        }
        else{
            delay -= 1;
        }
    }
}