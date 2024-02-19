#include "included/scene_builder.hpp"

namespace scene_builder{

    bool initializing_scene = false;

    void initialize_scene(const char *scene_name, const char *origin_scene, const char *dir){
        if (!initializing_scene){
            initializing_scene = true;

            if (origin_scene == "main_menu"){
                state::on_menu = false;
                if (scene_name == "newspaper"){
                    main_menu::unload_main_menu(true, true);
                    newspaper::load_newspaper_scene();
                    state::on_newspaper = true;
                }
                if (scene_name == "continue"){
                    main_menu::unload_main_menu(true, true);
                    continue_night::load_continue_scene();
                    state::on_continue = true;

                }
                if (scene_name == "custom_night"){
                    main_menu::unload_main_menu(false, true);
                    custom_night::create_custom_night_scene();
                    custom_night::load_custom_night_scene();
                    state::on_custom_night = true;
                }

                initializing_scene = false;
            }
            if (origin_scene == "custom_night"){
                state::on_custom_night = false;
                if (scene_name == "main_menu"){
                    custom_night::unload_custom_night_scene(false);
                    main_menu::load_main_menu();
                    state::on_menu = true;
                }
                if (scene_name == "continue"){
                    custom_night::unload_custom_night_scene(true);
                    continue_night::load_continue_scene();
                    state::on_continue = true;
                }

                initializing_scene = false;
            }
        }
    }

    namespace disclaimer{
        void load_disclaimer(){
            i_loader::background::disclaimer::load_disclaimer();
        }
        void run_disclaimer_scene(){
            i_renderer::background::disclaimer::render_disclaimer();
        }
        void exit_disclaimer(){
            i_loader::background::disclaimer::unload_disclaimer();
        }
    }
    namespace main_menu{

        bool loaded_files = false;
        bool created_scene = false;

        int cursor_position = 0;

        int cursor_timer = 5;
        int cursor_limit = 1;

        int button_delay = 3;

        void load_main_menu(){
            if (!loaded_files){
                i_loader::background::menu::load_menu();
                i_loader::effects::static_effect::load_static_effect();
                music::load_music_file::load_music_file("menu/music", 0, OSL_FMT_NONE);
                loaded_files = true;
            }
        }

        void unload_main_menu(bool must_unload_music, bool must_unload_static){
            if (loaded_files){
                if (must_unload_music){
                    music::load_music_file::stop_music_file();
                    music::load_music_file::unload_music_file();
                }
                if (must_unload_static){
                    i_loader::effects::static_effect::unload_static_effect();
                }
                i_loader::background::menu::clear_menu();
                loaded_files = false;
            }
        }

        void create_main_menu_scene(){
            music::load_music_file::check_for_playing(true, 0, true);
        }

        void run_cursor(){

            if (save_system::mode_one_unlocked == 1 && save_system::mode_two_unlocked == 0){
                if (cursor_position < 1){
                    cursor_limit = 2;
                }
            } 
            else if (save_system::mode_one_unlocked == 1 && save_system::mode_two_unlocked == 1){
                if (cursor_position < 2){
                    cursor_limit = 3;
                }
            }
            else{
                cursor_limit = 1;
            }

            if (cursor_timer <= 0){
                if (input::ctrlData.Buttons & PSP_CTRL_UP){
                    if (cursor_position > 0){
                        cursor_position -= 1;
                    }
                }
                if (input::ctrlData.Buttons & PSP_CTRL_DOWN){
                    cursor_position += 1;
                }
                cursor_timer = 2;
            }
            else{
                cursor_timer -= 1;
            }

            if (cursor_position > cursor_limit){
                cursor_position = cursor_limit;
            }
        }

        void select(){
            if (button_delay <= 0){
                if (input::ctrlData.Buttons & PSP_CTRL_CROSS){
                    if (cursor_position == 0){
                        if (save_system::saved_night == 1){
                            initialize_scene("newspaper", "main_menu", "forward");
                        }
                        else{
                            initialize_scene("continue", "main_menu", "forward");
                        }
                    }
                    if (cursor_position == 1){
                        initialize_scene("newspaper", "main_menu", "forward");
                    }
                    if (cursor_position == 2){
                        initialize_scene("continue", "main_menu", "forward");
                    }
                    if (cursor_position == 3){
                        initialize_scene("custom_night", "main_menu", "forward");
                    }
                }

                button_delay = 3;
            }
            else{
                button_delay -= 1;
            }
            
        }

        void run_main_menu_scene(){
            i_renderer::background::menu::render_menu_background();
            i_renderer::background::menu::animate_menu_background();
            i_renderer::background::menu::render_logo();
            i_renderer::background::menu::render_copyright();

            i_renderer::background::menu::render_buttons(cursor_position);
            i_renderer::background::menu::render_cursor(cursor_position);

            i_renderer::background::menu::render_stars();

            i_renderer::effects::static_effect::render_static_effect();
            i_renderer::effects::static_effect::animate_static_effect();

            run_cursor();
            select();
        }
    }
    namespace newspaper{

        bool loaded_files = false;
        bool created_scene = false;

        void load_newspaper_scene(){
            if (!loaded_files){
                i_loader::background::newspaper::load_newspaper();
                loaded_files = true;
            }
        }
        void unload_newspaper_scene(){
            if (loaded_files){
                i_loader::background::newspaper::unload_newspaper();
                loaded_files = false;
            }
        }
        void run_newspaper_scene(){
            i_renderer::background::newspaper::render_newspaper();
        }
    }
    namespace continue_night{

        bool loaded_files = false;
        bool created_scene = false;

        void load_continue_scene(){
            if (!loaded_files){
                i_loader::background::continue_game::load_night_information();
                loaded_files = true;
            }
        }
        void unload_continue_scene(){
            if (loaded_files){
                i_loader::background::continue_game::unload_night_information();
                loaded_files = false;
            }
        }
        void run_continue_scene(){
            i_renderer::background::continue_game::render_night_info();
        }
    }
    namespace custom_night{

        bool loaded_files = false;

        int position = 0;

        int button_delay = 3;

        void load_custom_night_scene(){
            if (!loaded_files){
                i_loader::background::custom_night::load_custom_night();
                loaded_files = true;
            }
        }
        void unload_custom_night_scene(bool must_unload_music){
            if (loaded_files){
                if (must_unload_music){
                    music::load_music_file::stop_music_file();
                    music::load_music_file::unload_music_file();
                }
                i_loader::background::custom_night::clear_custom_night();
                loaded_files = false;
            }
        }
        void create_custom_night_scene(){
            i_renderer::background::custom_night::reticle_positions[0] = 60;
            i_renderer::background::custom_night::reticle_positions[1] = 160;
            i_renderer::background::custom_night::reticle_positions[2] = 260;
            i_renderer::background::custom_night::reticle_positions[3] = 360;
        }
        void run_custom_night_scene(){
            i_renderer::background::custom_night::render_heads();
            i_renderer::background::custom_night::render_reticle();
            i_renderer::background::custom_night::render_instructions();
            i_renderer::background::custom_night::render_title();
            i_renderer::background::custom_night::render_names();
            i_renderer::background::custom_night::render_arrows();
            i_renderer::background::custom_night::render_levels();
            i_renderer::background::custom_night::render_text();
            i_renderer::background::custom_night::render_actions();
            i_renderer::background::custom_night::render_golden_freddy();

            button_action();
            set_ai_level_display();
        }

        void set_ai_level_display(){
            if (animatronic::freddy::first_digit == 10){
                animatronic::freddy::first_digit = 0;
                animatronic::freddy::second_digit += 1;
            }
            else if (animatronic::freddy::first_digit < 0 && animatronic::freddy::second_digit > 0){
                animatronic::freddy::first_digit = 9;
                animatronic::freddy::second_digit -= 1;
            }
            
            if (animatronic::bonnie::first_digit == 10){
                animatronic::bonnie::first_digit = 0;
                animatronic::bonnie::second_digit += 1;
            }
            else if (animatronic::bonnie::first_digit < 0 && animatronic::bonnie::second_digit > 0){
                animatronic::bonnie::first_digit = 9;
                animatronic::bonnie::second_digit -= 1;
            }

            if (animatronic::chica::first_digit == 10){
                animatronic::chica::first_digit = 0;
                animatronic::chica::second_digit += 1;
            }
            else if (animatronic::chica::first_digit < 0 && animatronic::chica::second_digit > 0){
                animatronic::chica::first_digit = 9;
                animatronic::chica::second_digit -= 1;
            }

            if (animatronic::foxy::first_digit == 10){
                animatronic::foxy::first_digit = 0;
                animatronic::foxy::second_digit += 1;
            }
            else if (animatronic::foxy::first_digit < 0 && animatronic::foxy::second_digit > 0){
                animatronic::foxy::first_digit = 9;
                animatronic::foxy::second_digit -= 1;
            }
        }

        void button_action(){
            if (button_delay <= 0){
                if (input::ctrlData.Buttons & PSP_CTRL_CROSS){
                    initialize_scene("continue", "custom_night", "forward");
                    std::cout << "CROSS" << std::endl;
                }
                if (input::ctrlData.Buttons & PSP_CTRL_CIRCLE){
                    initialize_scene("main_menu", "custom_night", "return");
                    std::cout << "CIRCLE" << std::endl;
                }

                if (input::ctrlData.Buttons & PSP_CTRL_LTRIGGER){
                    if (i_renderer::background::custom_night::position > 0){
                        i_renderer::background::custom_night::position -= 1;
                        std::cout << "LTRIGGER" << std::endl;
                    }
                    
                }
                if (input::ctrlData.Buttons & PSP_CTRL_RTRIGGER){
                    if (i_renderer::background::custom_night::position < 3){
                        i_renderer::background::custom_night::position += 1;
                        std::cout << "RTRIGGER" << std::endl;
                    }
                }

                if (input::ctrlData.Buttons & PSP_CTRL_RIGHT){
                    if (i_renderer::background::custom_night::position == 0){
                        if (animatronic::freddy::ai_level < 20){
                            animatronic::freddy::ai_level += 1;
                            animatronic::freddy::first_digit += 1;
                        }
                    }
                    if (i_renderer::background::custom_night::position == 1){
                        if (animatronic::bonnie::ai_level < 20){
                            animatronic::bonnie::ai_level += 1;
                            animatronic::bonnie::first_digit += 1;
                        }
                    }
                    if (i_renderer::background::custom_night::position == 2){
                        if (animatronic::chica::ai_level < 20){
                            animatronic::chica::ai_level += 1;
                            animatronic::chica::first_digit += 1;
                        }
                    }
                    if (i_renderer::background::custom_night::position == 3){
                        if (animatronic::foxy::ai_level < 20){
                            animatronic::foxy::ai_level += 1;
                            animatronic::foxy::first_digit += 1;
                        }
                    }
                    
                }
                if (input::ctrlData.Buttons & PSP_CTRL_LEFT){
                    if (i_renderer::background::custom_night::position == 0){
                        if (animatronic::freddy::ai_level > 0){
                            animatronic::freddy::ai_level -= 1;
                            animatronic::freddy::first_digit -= 1;
                        }
                    }
                    if (i_renderer::background::custom_night::position == 1){
                        if (animatronic::bonnie::ai_level > 0){
                            animatronic::bonnie::ai_level -= 1;
                            animatronic::bonnie::first_digit -= 1;
                        }
                    }
                    if (i_renderer::background::custom_night::position == 2){
                        if (animatronic::chica::ai_level > 0){
                            animatronic::chica::ai_level -= 1;
                            animatronic::chica::first_digit -= 1;
                        }
                    }
                    if (i_renderer::background::custom_night::position == 3){
                        if (animatronic::foxy::ai_level > 0){
                            animatronic::foxy::ai_level -= 1;
                            animatronic::foxy::first_digit -= 1;
                        }
                    }
                }

                button_delay = 4;
            }
            else{
                button_delay -= 1;
            }
        }
    }
}