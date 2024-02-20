#include "global.hpp"
#include "image_loader.hpp"
#include "save_system.hpp"
#include "game_text.hpp"
#include "animatronic.hpp"
#include "thread_id.hpp"

namespace i_renderer{
    namespace background{

        namespace disclaimer{
            void render_disclaimer();
        }

        namespace menu{

            extern int button_position;

            void render_menu_background();
            int animate_menu_background();
            void render_logo();
            void render_copyright();
            void render_buttons(int cursor_position);
            void render_cursor(int cursor_position);
            void render_stars();
        }
        namespace newspaper{
            void render_newspaper();
        }
        namespace continue_game{
            void render_night_info();
        }
        namespace custom_night{

            extern int reticle_positions[4];
            extern int position;

            void render_heads();
            void render_reticle();
            void render_instructions();
            void render_title();
            void render_names();
            void render_arrows();
            void render_text();
            void render_levels();
            void render_actions();
            void render_golden_freddy();
        }
    }
    namespace effects{
        namespace static_effect{
            void render_static_effect();
            int animate_static_effect();
        }
    }
}