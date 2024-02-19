#include "included/image_renderer.hpp"

namespace i_renderer{
    namespace background{

        namespace disclaimer{
            void render_disclaimer(){
                if (i_loader::background::disclaimer::disclaimer != NULL){
                    drawSpriteAlpha(0, 0, 480, 272, i_loader::background::disclaimer::disclaimer, 0, 0, 0);
                }
            }
        }

        namespace menu{

            int which_animation_frame = 0;
            int pause_time = 10;

            int button_position = 0;

            void render_menu_background(){
                int random_frame = animate_menu_background();
                if (i_loader::background::menu::menu_background[random_frame] != NULL){
                    drawSpriteAlpha(0, 0, 300, 272, i_loader::background::menu::menu_background[random_frame], 180, 0, 0);
                }
            }

            int animate_menu_background(){
                if (pause_time <= 0){
                    which_animation_frame = rand() % 4;

                    if (which_animation_frame > 3){
                        which_animation_frame = 0;
                    }
                    
                    pause_time = 10;
                }
                else{
                    pause_time -= 1;
                }

                return which_animation_frame;
            }

            void render_logo(){
                if (i_loader::background::menu::logo != NULL){
                    drawSpriteAlpha(0, 0, 165, 165, i_loader::background::menu::logo, 5, 5, 0);
                }
            }

            void render_copyright(){
                if (i_loader::background::menu::copyright_notice != NULL){
                    drawSpriteAlpha(0, 0, 287, 17, i_loader::background::menu::copyright_notice, 193, 255, 0);
                }
            }

            void render_stars(){
                if (i_loader::background::menu::star != NULL){
                    if (save_system::star_amount == 1){
                        drawSpriteAlpha(0, 0, 28, 27, i_loader::background::menu::star, 140, 5, 0);
                    }
                    if (save_system::star_amount == 2){
                        drawSpriteAlpha(0, 0, 28, 27, i_loader::background::menu::star, 140, 5, 0);
                        drawSpriteAlpha(0, 0, 28, 27, i_loader::background::menu::star, 170, 5, 0);
                    }
                    if (save_system::star_amount == 3){
                        drawSpriteAlpha(0, 0, 28, 27, i_loader::background::menu::star, 140, 5, 0);
                        drawSpriteAlpha(0, 0, 28, 27, i_loader::background::menu::star, 170, 5, 0);
                        drawSpriteAlpha(0, 0, 28, 27, i_loader::background::menu::star, 200, 5, 0);
                    }
                }
                
            }

            int pos_y[4];

            void render_buttons(int cursor_position){
                for (int i=0; i<3; i++){
                    if (i_loader::background::menu::selection_text[i] != NULL){
                        drawSpriteAlpha(0, 0, 205, 20, i_loader::background::menu::selection_text[0], 40, 180, 0);
                        drawSpriteAlpha(0, 0, 205, 20, i_loader::background::menu::selection_text[1], 40, 203, 0);

                        
                        if (save_system::mode_one_unlocked == 1){
                            drawSpriteAlpha(0, 0, 205, 20, i_loader::background::menu::selection_text[2], 40, 226, 0);
                        }
                        if (save_system::mode_two_unlocked == 1){
                            drawSpriteAlpha(0, 0, 205, 20, i_loader::background::menu::selection_text[3], 40, 249, 0);
                        }
                    }
                }
                for (int i=0; i<10; i++){
                    if (cursor_position == 0){
                        if (game_text::global::numbers_normal[i] != NULL){
                            drawSpriteAlpha(0, 0, 20, 20, game_text::global::numbers_normal[save_system::saved_night], 140, 177, 0);
                        }
                    }
                }
            }

            void render_cursor(int cursor_position){
                pos_y[0] = 182;
                pos_y[1] = 205;
                pos_y[2] = 228;
                pos_y[3] = 251;

                if (i_loader::background::menu::cursor != NULL){
                    drawSpriteAlpha(0, 0, 205, 20, i_loader::background::menu::cursor, 13, pos_y[cursor_position], 0);
                }
            }
        }
        namespace newspaper{
            void render_newspaper(){
                if (i_loader::background::newspaper::newspaper_file != NULL){
                    drawSpriteAlpha(0, 0, 480, 272, i_loader::background::newspaper::newspaper_file, 0, 0, 0);
                }
            }
        }
        namespace continue_game{
            void render_night_info(){
                if (i_loader::background::continue_game::information != NULL){
                    drawSpriteAlpha(0, 0, 75, 48, i_loader::background::continue_game::information, 200, 100, 0);
                }
                if (i_loader::background::continue_game::clock != NULL){
                    drawSpriteAlpha(0, 0, 40, 40, i_loader::background::continue_game::clock, 435, 227, 0);
                }
                if (game_text::global::numbers_pixel[save_system::saved_night] != NULL){
                    drawSpriteAlpha(0, 0, 20, 20, game_text::global::numbers_pixel[save_system::saved_night], 265, 128, 0);
                }
            }
        }
        namespace custom_night{
            void render_heads(){
                for (int i=0; i<3; i++){
                    if (i_loader::background::custom_night::icons[i] != NULL){
                        drawSpriteAlpha(0, 0, 60, 60, i_loader::background::custom_night::icons[0], 60, 80, 0);
                        drawSpriteAlpha(0, 0, 60, 60, i_loader::background::custom_night::icons[1], 160, 80, 0);
                        drawSpriteAlpha(0, 0, 60, 60, i_loader::background::custom_night::icons[2], 260, 80, 0);
                        drawSpriteAlpha(0, 0, 60, 60, i_loader::background::custom_night::icons[3], 360, 80, 0);
                    }
                }
            }

            int reticle_positions[4];
            int position;

            void render_reticle(){
                if (i_loader::background::custom_night::reticle != NULL){
                    drawSpriteAlpha(0, 0, 60, 60, i_loader::background::custom_night::reticle, reticle_positions[position], 80, 0);
                }
            }
            void render_instructions(){
                for (int i=0; i<1; i++){
                    if (i_loader::background::custom_night::instructions[i] != NULL){
                        drawSpriteAlpha(0, 0, 13, 20, i_loader::background::custom_night::instructions[0], 10, 10, 0);
                        drawSpriteAlpha(0, 0, 13, 20, i_loader::background::custom_night::instructions[1], 457, 10, 0);
                    }
                }
            }
            void render_title(){
                if (i_loader::background::custom_night::title != NULL){
                    drawSpriteAlpha(0, 0, 175, 24, i_loader::background::custom_night::title, 153, 25, 0);
                }
            }
            void render_names(){
                for (int i=0; i<3; i++){
                    if (i_loader::background::custom_night::names[i] != NULL){
                        drawSpriteAlpha(0, 0, 60, 17, i_loader::background::custom_night::names[0], 60, 64, 0);
                        drawSpriteAlpha(0, 0, 60, 17, i_loader::background::custom_night::names[1], 160, 63, 0);
                        drawSpriteAlpha(0, 0, 60, 17, i_loader::background::custom_night::names[2], 260, 63, 0);
                        drawSpriteAlpha(0, 0, 60, 17, i_loader::background::custom_night::names[3], 360, 64, 0);
                    }
                }
            }
            void render_arrows(){
                for (int i=0; i<1; i++){
                    if (i_loader::background::custom_night::arrows[i] != NULL){
                        //freddy
                        drawSpriteAlpha(0, 0, 13, 20, i_loader::background::custom_night::arrows[0], 60, 160, 0);
                        drawSpriteAlpha(0, 0, 13, 20, i_loader::background::custom_night::arrows[1], 108, 160, 0);

                        //bonnie
                        drawSpriteAlpha(0, 0, 13, 20, i_loader::background::custom_night::arrows[0], 160, 160, 0);
                        drawSpriteAlpha(0, 0, 13, 20, i_loader::background::custom_night::arrows[1], 208, 160, 0);

                        //chika
                        drawSpriteAlpha(0, 0, 13, 20, i_loader::background::custom_night::arrows[0], 260, 160, 0);
                        drawSpriteAlpha(0, 0, 13, 20, i_loader::background::custom_night::arrows[1], 308, 160, 0);

                        //foxy
                        drawSpriteAlpha(0, 0, 13, 20, i_loader::background::custom_night::arrows[0], 360, 160, 0);
                        drawSpriteAlpha(0, 0, 13, 20, i_loader::background::custom_night::arrows[1], 408, 160, 0);
                    }
                }
            }
            void render_text(){
                if (i_loader::background::custom_night::level_description != NULL){
                    drawSpriteAlpha(0, 0, 60, 10, i_loader::background::custom_night::level_description, 60, 145, 0);
                    drawSpriteAlpha(0, 0, 60, 10, i_loader::background::custom_night::level_description, 160, 145, 0);
                    drawSpriteAlpha(0, 0, 60, 10, i_loader::background::custom_night::level_description, 260, 145, 0);
                    drawSpriteAlpha(0, 0, 60, 10, i_loader::background::custom_night::level_description, 360, 145, 0);
                }
                
                if (i_loader::background::custom_night::difficulty != NULL){
                    drawSpriteAlpha(0, 0, 300, 11, i_loader::background::custom_night::difficulty, 60, 212, 0);
                }
            }
            void render_levels(){
                for (int i=0; i<10; i++){
                    if (game_text::global::numbers_normal[i] != NULL){
                        //freddy
                        drawSpriteAlpha(0, 0, 20, 20, game_text::global::numbers_normal[animatronic::freddy::first_digit], 88, 160, 0);
                        if (animatronic::freddy::ai_level > 9){
                            drawSpriteAlpha(0, 0, 20, 20, game_text::global::numbers_normal[animatronic::freddy::second_digit], 73, 160, 0);
                        }
                        //bonnie
                        drawSpriteAlpha(0, 0, 20, 20, game_text::global::numbers_normal[animatronic::bonnie::first_digit], 188, 160, 0);
                        if (animatronic::bonnie::ai_level > 9){
                            drawSpriteAlpha(0, 0, 20, 20, game_text::global::numbers_normal[animatronic::bonnie::second_digit], 173, 160, 0);
                        }
                        //chika
                        drawSpriteAlpha(0, 0, 20, 20, game_text::global::numbers_normal[animatronic::chica::first_digit], 288, 160, 0);
                        if (animatronic::chica::ai_level > 9){
                            drawSpriteAlpha(0, 0, 20, 20, game_text::global::numbers_normal[animatronic::chica::second_digit], 273, 160, 0);
                        }
                        //foxy
                        drawSpriteAlpha(0, 0, 20, 20, game_text::global::numbers_normal[animatronic::foxy::first_digit], 388, 160, 0);
                        if (animatronic::foxy::ai_level > 9){
                            drawSpriteAlpha(0, 0, 20, 20, game_text::global::numbers_normal[animatronic::foxy::second_digit], 373, 160, 0);
                        }
                    }
                }
            }
            void render_actions(){
                if (i_loader::background::custom_night::create != NULL){
                    drawSpriteAlpha(0, 0, 78, 18, i_loader::background::custom_night::create, 380, 242, 0);
                }
                if (i_loader::background::custom_night::exit != NULL){
                    drawSpriteAlpha(0, 0, 69, 18, i_loader::background::custom_night::exit, 10, 242, 0);
                }
            }
            void render_golden_freddy(){

            }
        }
    }

    namespace effects{
        namespace static_effect{
            int which_animation_frame = 0;
            int pause_time = 5;

            void render_static_effect(){
                int frame = animate_static_effect();
                if (i_loader::effects::static_effect::static_effect[frame] != NULL){
                    drawSpriteAlpha(0, 0, 480, 272, i_loader::effects::static_effect::static_effect[frame], 0, 0, 0);
                }
            }

            int animate_static_effect(){

                if (pause_time <= 0){
                    if (which_animation_frame < 3){
                        which_animation_frame += 1;

                    }
                    else{
                        which_animation_frame = 0;
                    }

                    pause_time = 5;
                }
                else{
                    pause_time -= 1;
                }

                return which_animation_frame;
            }
        }
    }
}