#include "global.hpp"

namespace i_loader{
    namespace background{

        namespace disclaimer{

            extern Image *disclaimer;

            void load_disclaimer();
            void unload_disclaimer();
        }

        namespace menu{

            extern Image *menu_background[4];
            extern Image *selection_text[4];
            extern Image *cursor;

            extern Image *logo;
            extern Image *star;
            extern Image *copyright_notice;

            void load_menu_background();
            void unload_menu_background();
            void load_logo();
            void unload_logo();
            void load_copyright();
            void unload_copyright();
            void load_text_and_cursor();
            void unload_text_and_cursor();
            void clear_menu();
            void load_menu();
        }

        namespace newspaper{
            extern Image *newspaper_file;

            void load_newspaper();
            void unload_newspaper();
        }

        namespace continue_game{
            extern Image *information;
            extern Image *clock;

            void load_night_information();
            void unload_night_information();
        }

        namespace custom_night{
            extern Image *icons[4];
            extern Image *reticle;
            extern Image *instructions[2];
            extern Image *title;
            extern Image *arrows[2];
            extern Image *level_description;
            extern Image *difficulty;
            extern Image *names[4];
            extern Image *create;
            extern Image *exit;
            extern Image *goldFreddy;

            void load_icons();
            void unload_icons();

            void load_reticle();
            void unload_reticle();

            void load_instructions();
            void unload_instructions();

            void load_title();
            void unload_title();

            void load_arrows();
            void unload_arrows();

            void load_text();
            void unload_text();

            void load_names();
            void unload_names();

            void load_actions();
            void unload_actions();

            void load_golden_freddy();
            void unload_golden_freddy();

            void load_custom_night();
            void clear_custom_night();
        }
    }
    namespace effects{
        namespace static_effect{
            extern Image *static_effect[4];

            void load_static_effect();
            void unload_static_effect();
        }
    }
}