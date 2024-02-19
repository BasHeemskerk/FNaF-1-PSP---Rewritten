#include "global.hpp"

namespace game_text{
    namespace global{
        extern Image *numbers_normal[10];
        extern Image *numbers_pixel[10];
        extern Image *percentage_symbol;

        void load_text();
        void unload_text();
    }
}