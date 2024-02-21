#include "global.hpp"
#include "save_system.hpp"

namespace chica_script{

    extern int position;

    void ai_init(int input_level);
    void debug(const char *msg);
    bool should_update_components();
    void ai_loop();
}