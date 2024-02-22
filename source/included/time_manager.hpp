#include "global.hpp"

namespace time_manager{
    extern int time;

    extern int timer;
    extern int timer_b;
    extern int clock; //30fps = 1800 frames per minute.

    void initialize_time_system();
    void time_loop();
}