#include "included/game_text.hpp"

namespace game_text{
    namespace global{
        Image *numbers_normal[10];
        Image *numbers_pixel[10];
        Image *percentage_symbol;

        void load_text(){
            numbers_normal[0] = loadPng("romfs/gfx/global/numbers/normal/0-2.png");
            numbers_normal[1] = loadPng("romfs/gfx/global/numbers/normal/1.png");
            numbers_normal[2] = loadPng("romfs/gfx/global/numbers/normal/2.png");
            numbers_normal[3] = loadPng("romfs/gfx/global/numbers/normal/3.png");
            numbers_normal[4] = loadPng("romfs/gfx/global/numbers/normal/4.png");
            numbers_normal[5] = loadPng("romfs/gfx/global/numbers/normal/5.png");
            numbers_normal[6] = loadPng("romfs/gfx/global/numbers/normal/6.png");
            numbers_normal[7] = loadPng("romfs/gfx/global/numbers/normal/7.png");
            numbers_normal[8] = loadPng("romfs/gfx/global/numbers/normal/8.png");
            numbers_normal[9] = loadPng("romfs/gfx/global/numbers/normal/9.png");

            numbers_pixel[0] = loadPng("romfs/gfx/global/numbers/pixel/0.png");
            numbers_pixel[1] = loadPng("romfs/gfx/global/numbers/pixel/1.png");
            numbers_pixel[2] = loadPng("romfs/gfx/global/numbers/pixel/2.png");
            numbers_pixel[3] = loadPng("romfs/gfx/global/numbers/pixel/3.png");
            numbers_pixel[4] = loadPng("romfs/gfx/global/numbers/pixel/4.png");
            numbers_pixel[5] = loadPng("romfs/gfx/global/numbers/pixel/5.png");
            numbers_pixel[6] = loadPng("romfs/gfx/global/numbers/pixel/6.png");
            numbers_pixel[7] = loadPng("romfs/gfx/global/numbers/pixel/7.png");
            numbers_pixel[8] = loadPng("romfs/gfx/global/numbers/pixel/8.png");
            numbers_pixel[9] = loadPng("romfs/gfx/global/numbers/pixel/9.png");

            percentage_symbol = loadPng("romfs/gfx/global/numbers/symbols/%.png");
        }
        void unload_text(){
            for (int i=0; i<10; i++){
                if (numbers_normal[i] != NULL){
                    freeImage(numbers_normal[i]);
                }
                if (numbers_pixel[i] != NULL){
                    freeImage(numbers_pixel[i]);
                }
            }

            if (percentage_symbol != NULL){
                freeImage(percentage_symbol);
            }
        }
    }
}