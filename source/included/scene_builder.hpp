#include "global.hpp"
#include "image_loader.hpp"
#include "image_renderer.hpp"
#include "music.hpp"
#include "audio_effects.hpp"
#include "input.hpp"
#include "save_system.hpp"
#include "game_text.hpp"
#include "state.hpp"
#include "animatronic_manager.hpp"

namespace scene_builder{

    void initialize_scene(const char *scene_name, const char *origin_scene, const char *dir);

    namespace disclaimer{
        void load_disclaimer();
        void run_disclaimer_scene();
        void exit_disclaimer();
    }
    namespace main_menu{
        void load_main_menu();
        void unload_main_menu(bool must_unload_music, bool must_unload_static);
        void create_main_menu_scene();
        void check_cursor_positon();
        void run_cursor();
        void select();
        void run_main_menu_scene();
    }
    namespace newspaper{
        void load_newspaper_scene();
        void unload_newspaper_scene();
        void run_newspaper_scene();
    }
    namespace continue_night{
        void load_continue_scene();
        void unload_continue_scene();
        void run_continue_scene();
    }
    namespace custom_night{
        void load_custom_night_scene();
        void unload_custom_night_scene(bool must_unload_music);
        void create_custom_night_scene();
        void run_custom_night_scene();

        void button_action();
        void set_ai_level_display();
    }
}