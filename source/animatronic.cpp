#include "included/animatronic.hpp"

namespace animatronic{
    namespace freddy{
        int ai_level = 0;
        int first_digit = 0;
        int second_digit = 0;

        int thread_id;
        int psp_thread_status = 1;

        Image *memory_image;
        
        namespace path{
            int current_position;
            const char *path_array[4];
            const char *path_type[4];

            //the path is hardcoded into memory
            void init_path_array(){
                path_array[0] = "cam1b-freddy";
                path_type[0] = "cam1b";

                path_array[1] = "cam7-freddy";
                path_type[1] = "cam7";

                path_array[2] = "cam4a-freddy";
                path_type[2] = "cam4a";

                path_array[3] = "cam4b-freddy";
                path_type[3] = "cam4b";
            }

            int load_path_image(SceSize args, void* argp){
                memory_image = i_loader::camera_loader::load_target(path_array[current_position]);

                thread_id = sceKernelExitThread(psp_thread_status);
                return 0;
            }
            void create_load_thread(){
                thread_id = sceKernelCreateThread("load_thread_freddy", load_path_image, 0x11, 0xFA0, 0, NULL);
                sceKernelStartThread(thread_id, 0, NULL);
            }
            void clear_path_image(){
                freeImage(memory_image);
            }
            void reload_path_image(){
                clear_path_image();
                create_load_thread();
            }
        }
    }
    namespace bonnie{
        int ai_level = 0;
        int first_digit = 0;
        int second_digit = 0;

        int thread_id;
        int psp_thread_status = 1;

        Image *memory_image;
        
        namespace path{
            int current_position;
            const char *path_array[7];
            const char *path_type[7];

            //the path is hardcoded into memory
            void init_path_array(){
                path_array[0] = "cam1b-bonnie";
                path_type[0] = "cam1b";

                path_array[1] = "cam1b-bonnieclose";
                path_type[1] = "cam1b";

                path_array[2] = "cam2a-bonnie";
                path_type[2] = "cam2a";

                path_array[3] = "cam3-bonnie";
                path_type[3] = "cam3 ";

                path_array[4] = "cam2a-bonnie";
                path_type[4] = "cam2a";

                path_array[5] = "cam2b-bonnie";
                path_type[5] = "cam2b";

                path_array[6] = "cam5-bonnie";
                path_type[6] = "cam5";
            }

            int load_path_image(SceSize args, void* argp){
                memory_image = i_loader::camera_loader::load_target(path_array[current_position]);

                thread_id = sceKernelExitThread(psp_thread_status);
                return 0;
            }
            void create_load_thread(){
                thread_id = sceKernelCreateThread("load_thread_bonnie", load_path_image, 0x11, 0xFA0, 0, NULL);
                sceKernelStartThread(thread_id, 0, NULL);
            }
            void clear_path_image(){
                freeImage(memory_image);
            }
            void reload_path_image(){
                clear_path_image();
                create_load_thread();
            }
        }
    }
    namespace chica{
        int ai_level = 0;
        int first_digit = 0;
        int second_digit = 0;

        int thread_id;
        int psp_thread_status = 1;

        Image *memory_image;
        
        namespace path{
            int current_position;
            const char *path_array[7];
            const char *path_type[7];

            //the path is hardcoded into memory
            void init_path_array(){
                path_array[0] = "cam1b-chica";
                path_type[0] = "cam1b";

                path_array[1] = "cam1b-chicaclose";
                path_type[1] = "cam1b";

                path_array[2] = "cam4a-chica";
                path_type[2] = "cam4a";

                path_array[3] = "cam4a-chicaclose";
                path_type[3] = "cam4a";

                path_array[4] = "cam4b-chica";
                path_type[4] = "cam4b";

                path_array[5] = "cam7-chica";
                path_type[5] = "cam7";

                path_array[6] = "cam7-chicaclose";
                path_type[6] = "cam7";
            }

            int load_path_image(SceSize args, void* argp){
                memory_image = i_loader::camera_loader::load_target(path_array[current_position]);

                thread_id = sceKernelExitThread(psp_thread_status);
                return 0;
            }
            void create_load_thread(){
                thread_id = sceKernelCreateThread("load_thread_chica", load_path_image, 0x11, 0xFA0, 0, NULL);
                sceKernelStartThread(thread_id, 0, NULL);
            }
            void clear_path_image(){
                freeImage(memory_image);
            }
            void reload_path_image(){
                clear_path_image();
                create_load_thread();
            }
        }
    }
    namespace foxy{
        int ai_level = 0;
        int first_digit = 0;
        int second_digit = 0;

        int thread_id;
        int psp_thread_status = 1;

        Image *memory_image;
        
        namespace path{
            int current_position;
            const char *path_array[3];
            const char *path_type[3];

            //the path is hardcoded into memory
            void init_path_array(){
                path_array[0] = "cam1c-foxy1";
                path_type[0] = "cam1c";

                path_array[1] = "cam1c-foxy2";
                path_type[1] = "cam1c";

                path_array[2] = "cam1c-foxy3";
                path_type[2] = "cam1c";
            }

            int load_path_image(SceSize args, void* argp){
                memory_image = i_loader::camera_loader::load_target(path_array[current_position]);

                thread_id = sceKernelExitThread(psp_thread_status);
                return 0;
            }
            void create_load_thread(){
                thread_id = sceKernelCreateThread("load_thread_foxy", load_path_image, 0x11, 0xFA0, 0, NULL);
                sceKernelStartThread(thread_id, 0, NULL);
            }
            void clear_path_image(){
                freeImage(memory_image);
            }
            void reload_path_image(){
                clear_path_image();
                create_load_thread();
            }
        }
    }
}