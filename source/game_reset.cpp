#include "included/game_reset.hpp"

namespace game_reset{
    void reset_all_game_variables(){

        //reset animatronic positions to 0
        animatronic::freddy::path::current_position = 0;
        animatronic::bonnie::path::current_position = 0;
        animatronic::chica::path::current_position = 0;
        animatronic::foxy::path::current_position = 0;

        //reset image loader variables

        //reset office stuff

        //reset power manager

        //reset time manager
        time_manager::time = 0;
        time_manager::timer = 0;
        time_manager::initialize_time_system();

        //reset thread id's
        thread_id::thread_a = 0;
        thread_id::thread_b = 0;
        thread_id::thread_c = 0;
        thread_id::thread_d = 0;
        thread_id::thread_e = 0;
        thread_id::thread_f = 0;
        thread_id::thread_g = 0;
        thread_id::thread_h = 0;
        thread_id::thread_i = 0;
        thread_id::thread_j = 0;
        thread_id::thread_k = 0;
        thread_id::thread_l = 0;
        thread_id::thread_m = 0;
        thread_id::thread_n = 0;
        thread_id::thread_o = 0;
        thread_id::thread_p = 0;
        thread_id::thread_q = 0;
        thread_id::thread_r = 0;
        thread_id::thread_s = 0;
        thread_id::thread_t = 0;
        thread_id::thread_u = 0;
        thread_id::thread_v = 0;
        thread_id::thread_w = 0;
        thread_id::thread_x = 0;
        thread_id::thread_y = 0;
        thread_id::thread_z = 0;
    }
}