#include "included/image_loader.hpp"

namespace i_loader{
    namespace background{

        int PspThreadStatus = 1;

        namespace disclaimer{

            Image *disclaimer;

            void load_disclaimer(){
                disclaimer = loadPng("romfs/gfx/disclaimer/disclaimer.png");
            }
            void unload_disclaimer(){
                if (disclaimer != NULL){
                    freeImage(disclaimer);
                }
            }
        }
        namespace menu{

            Image *menu_background[4];
            Image *selection_text[4];
            Image *cursor;

            Image *logo;
            Image *star;
            Image *copyright_notice;

            void load_menu_background(){
                menu_background[0] = loadPng("romfs/gfx/menu/frame_1.png");
                menu_background[1] = loadPng("romfs/gfx/menu/frame_2.png");
                menu_background[2] = loadPng("romfs/gfx/menu/frame_3.png");
                menu_background[3] = loadPng("romfs/gfx/menu/frame_4.png");
            }
            void unload_menu_background(){
                for (int i=0; i<3; i++){
                    if (menu_background[i] != NULL){
                        freeImage(menu_background[i]);
                    }
                }
            }

            void load_logo(){
                logo = loadPng("romfs/gfx/menu/logo.png");
            }
            void unload_logo(){
                if (logo != NULL){
                    freeImage(logo);
                }
            }

            void load_copyright(){
                copyright_notice = loadPng("romfs/gfx/menu/copyright.png");
            }
            void unload_copyright(){
                if (copyright_notice != NULL){
                    freeImage(copyright_notice);
                }
            }

            void load_star(){
                star = loadPng("romfs/gfx/menu/star.png");
            }
            void unload_star(){
                if (star != NULL){
                    freeImage(star);
                }
            }

            void load_text_and_cursor(){
                selection_text[0] = loadPng("romfs/gfx/menu/selection/continue.png");
                selection_text[1] = loadPng("romfs/gfx/menu/selection/newGame.png");
                selection_text[2] = loadPng("romfs/gfx/menu/selection/6thNight.png");
                selection_text[3] = loadPng("romfs/gfx/menu/selection/customNight.png");

                cursor = loadPng("romfs/gfx/menu/selection/arrow.png");
            }
            void unload_text_and_cursor(){

                for (int i=0; i<3; i++){
                    if (selection_text[i] != NULL){
                        freeImage(selection_text[i]);
                    }
                }

                if (cursor != NULL){
                    freeImage(cursor);
                }
            }

            void clear_menu(){
                unload_menu_background();
                unload_logo();
                unload_copyright();
                unload_star();
                unload_text_and_cursor();

            }

            void load_menu(){
                load_menu_background();
                load_logo();
                load_copyright();
                load_star();
                load_text_and_cursor();

            }
        }

        namespace newspaper{
            Image *newspaper_file;

            void load_newspaper(){
                newspaper_file = loadPng("romfs/gfx/newspaper/paper.png");
            }
            void unload_newspaper(){
                if (newspaper_file != NULL){
                    freeImage(newspaper_file);
                }
            }
        }

        namespace continue_game{
            Image *information;
            Image *clock;

            void load_night_information(){
                information = loadPng("romfs/gfx/nightinfo/info.png");
                clock = loadPng("romfs/gfx/nightinfo/clock.png");
            }
            void unload_night_information(){
                if (information != NULL){
                    freeImage(information);
                }
                if (clock != NULL){
                    freeImage(clock);
                }
            }
        }

        namespace custom_night{
            Image *icons[4];
            Image *reticle;
            Image *instructions[2];
            Image *title;
            Image *arrows[2];
            Image *level_description;
            Image *difficulty;
            Image *names[4];
            Image *create;
            Image *exit;
            Image *goldFreddy;

            void load_icons(){
                icons[0] = loadPng("romfs/gfx/customnight/icons/freddy.png");
                icons[1] = loadPng("romfs/gfx/customnight/icons/bonnie.png");
                icons[2] = loadPng("romfs/gfx/customnight/icons/chika.png");
                icons[3] = loadPng("romfs/gfx/customnight/icons/foxy.png");
            }
            void unload_icons(){
                for (int i=0; i<3; i++){
                    if (icons[i] != NULL){
                        freeImage(icons[i]);
                    }
                }
            }

            void load_reticle(){
                reticle = loadPng("romfs/gfx/customnight/icons/reticle.png");
            }
            void unload_reticle(){
                if (reticle != NULL){
                    freeImage(reticle);
                }
            }

            void load_instructions(){
                instructions[0] = loadPng("romfs/gfx/customnight/ui/L.png");
                instructions[1] = loadPng("romfs/gfx/customnight/ui/R.png");
            }
            void unload_instructions(){

                for (int i=0; i<1; i++){
                    if (instructions[i] != NULL){
                        freeImage(instructions[i]);
                    }
                }
            }

            void load_title(){
                title = loadPng("romfs/gfx/customnight/ui/title.png");
            }
            void unload_title(){
                if (title != NULL){
                    freeImage(title);
                }
            }

            void load_arrows(){
                arrows[0] = loadPng("romfs/gfx/customnight/ui/left.png");
                arrows[1] = loadPng("romfs/gfx/customnight/ui/right.png");
            }
            void unload_arrows(){
                for (int i=0; i<1; i++){
                    if (arrows[i] != NULL){
                        freeImage(arrows[i]);
                    }
                }
            }

            void load_text(){
                level_description = loadPng("romfs/gfx/customnight/ui/AI.png");
                difficulty = loadPng("romfs/gfx/customnight/ui/difficulty.png");
            }
            void unload_text(){

                if (level_description != NULL){
                    freeImage(level_description);
                }
                
                if (difficulty != NULL){
                    freeImage(difficulty);
                }
            }

            void load_names(){
                names[0] = loadPng("romfs/gfx/customnight/ui/freddy.png");
                names[1] = loadPng("romfs/gfx/customnight/ui/bonnie.png");
                names[2] = loadPng("romfs/gfx/customnight/ui/chika.png");
                names[3] = loadPng("romfs/gfx/customnight/ui/foxy.png");
            }
            void unload_names(){
                for (int i=0; i<3; i++){
                    if (names[i] != NULL){
                        freeImage(names[i]);
                    }
                }
            }

            void load_actions(){
                create = loadPng("romfs/gfx/customnight/ui/create.png");
                exit = loadPng("romfs/gfx/customnight/ui/exit.png");
            }
            void unload_actions(){

                if (create != NULL){
                    freeImage(create);
                }
                
                if (exit != NULL){
                    freeImage(exit);
                }
            }

            void load_golden_freddy(){
                goldFreddy = loadPng("romfs/gfx/customnight/ui/gold.png");
            }
            void unload_golden_freddy(){
                //i purposfully unload while rendering so boom, crash

                if (goldFreddy != NULL){
                    freeImage(goldFreddy);
                }
            }

            void load_custom_night(){
                load_icons();
                load_reticle();
                load_instructions();
                load_title();
                load_arrows();
                load_text();
                load_names();
                load_actions();
                load_golden_freddy();

            }
            void clear_custom_night(){
                unload_icons();
                unload_reticle();
                unload_instructions();
                unload_title();
                unload_arrows();
                unload_text();
                unload_names();
                unload_actions();
                unload_golden_freddy();

            }
        }
    }
    namespace effects{
        namespace static_effect{
            Image *static_effect[4];

            void load_static_effect(){
                static_effect[0] = loadPng("romfs/gfx/menu/static/image1_480x272.png");
                static_effect[1] = loadPng("romfs/gfx/menu/static/image2_480x272.png");
                static_effect[2] = loadPng("romfs/gfx/menu/static/image3_480x272.png");
                static_effect[3] = loadPng("romfs/gfx/menu/static/image4_480x272.png");
            }

            void unload_static_effect(){
                for (int i=0; i<3; i++){
                    if (static_effect[i] != NULL){
                        freeImage(static_effect[i]);
                    }
                }
            }
        }
    }
    namespace camera_loader{
        Image *load_target(std::string target){
            Image *target_image;
            target_image = loadPng(target.c_str());
            return target_image;
        }
    }
}