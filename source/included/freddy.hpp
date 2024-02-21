#include "global.hpp"
#include "save_system.hpp"

namespace freddy_script{

    extern int position;

    void ai_init(int input_level);
    void debug(const char *msg);
    int randomize_ai_level();
    bool should_update_components();
    void ai_loop();
}