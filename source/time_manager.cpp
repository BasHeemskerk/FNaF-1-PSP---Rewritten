#include "included/time_manager.hpp"

namespace time_manager{
    int time = 0;

    int timer = 0;
    int timer_b = 0;
    int clock = 5100; //30fps = 1800 frames per minute.

    void initialize_time_system(){
        timer_b = timer;
    }

    void time_loop(){
        if (timer <= 0){
            time += 1;
            timer = timer_b;
        }
        else{
            timer -= 1;
        }
    }
}