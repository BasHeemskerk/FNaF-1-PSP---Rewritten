#include "included/animatronic_manager.hpp"

namespace animatronic{

    bool reloading_any = false;

    std::string default_path = "romfs/gfx/office/camera/animatronic/";
    std::string file_extention = ".png";

    namespace freddy{
        int ai_level = 0;
        int first_digit = 0;
        int second_digit = 0;

        int thread_id;
        int psp_thread_status = 1;

        Image *memory_image;
        
        namespace path{
            int current_position;
            std::string path_array[4];
            std::string path_type[4];

            //the path is hardcoded into memory
            void init_path_array(){
                path_array[0] = "cam1b-freddy";
                path_type[0] = "cam1b/";

                path_array[1] = "cam7-freddy";
                path_type[1] = "cam7/";

                path_array[2] = "cam4a-freddy";
                path_type[2] = "cam4a/";

                path_array[3] = "cam4b-freddy";
                path_type[3] = "cam4b/";
            }

            int load_path_image(SceSize args, void* argp){
                std::string target_string = (default_path + path_type[current_position] + path_array[current_position] + file_extention);
                memory_image = i_loader::camera_loader::load_target(target_string.c_str());

                thread_id = sceKernelExitThread(psp_thread_status);
                return 0;
            }
            void create_load_thread(){
                thread_id = sceKernelCreateThread("load_thread", load_path_image, 0x11, 0xFA0, 0, NULL);
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
            std::string path_array[7];
            std::string path_type[7];

            //the path is hardcoded into memory
            void init_path_array(){
                path_array[0] = "cam1b-bonnie";
                path_type[0] = "cam1b/";

                path_array[1] = "cam1b-bonnieclose";
                path_type[1] = "cam1b/";

                path_array[2] = "cam2a-bonnie";
                path_type[2] = "cam2a/";

                path_array[3] = "cam3-bonnie";
                path_type[3] = "cam3/";

                path_array[4] = "cam2a-bonnie";
                path_type[4] = "cam2a/";

                path_array[5] = "cam2b-bonnie";
                path_type[5] = "cam2b/";

                path_array[6] = "cam5-bonnie";
                path_type[6] = "cam5/";
            }

            int load_path_image(SceSize args, void* argp){
                std::string target_string = (default_path + path_type[current_position] + path_array[current_position] + file_extention);
                memory_image = i_loader::camera_loader::load_target(target_string.c_str());

                thread_id = sceKernelExitThread(psp_thread_status);
                return 0;
            }
            void create_load_thread(){
                thread_id = sceKernelCreateThread("load_thread", load_path_image, 0x11, 0xFA0, 0, NULL);
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
            std::string path_array[7];
            std::string path_type[7];

            //the path is hardcoded into memory
            void init_path_array(){
                path_array[0] = "cam1b-chica";
                path_type[0] = "cam1b/";

                path_array[1] = "cam1b-chicaclose";
                path_type[1] = "cam1b/";

                path_array[2] = "cam4a-chica";
                path_type[2] = "cam4a/";

                path_array[3] = "cam4a-chicaclose";
                path_type[3] = "cam4a/";

                path_array[4] = "cam4b-chica";
                path_type[4] = "cam4b/";

                path_array[5] = "cam7-chica";
                path_type[5] = "cam7/";

                path_array[6] = "cam7-chicaclose";
                path_type[6] = "cam7/";
            }

            int load_path_image(SceSize args, void* argp){
                std::string target_string = (default_path + path_type[current_position] + path_array[current_position] + file_extention);
                memory_image = i_loader::camera_loader::load_target(target_string.c_str());

                thread_id = sceKernelExitThread(psp_thread_status);
                return 0;
            }
            void create_load_thread(){
                thread_id = sceKernelCreateThread("load_thread", load_path_image, 0x11, 0xFA0, 0, NULL);
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
            std::string path_array[3];
            std::string path_type[3];

            //the path is hardcoded into memory
            void init_path_array(){
                path_array[0] = "cam1c-foxy1";
                path_type[0] = "cam1c/";

                path_array[1] = "cam1c-foxy2";
                path_type[1] = "cam1c/";

                path_array[2] = "cam1c-foxy3";
                path_type[2] = "cam1c/";
            }

            int load_path_image(SceSize args, void* argp){
                std::string target_string = (default_path + path_type[current_position] + path_array[current_position] + file_extention);
                memory_image = i_loader::camera_loader::load_target(target_string.c_str());

                thread_id = sceKernelExitThread(psp_thread_status);
                return 0;
            }
            void create_load_thread(){
                thread_id = sceKernelCreateThread("load_thread", load_path_image, 0x11, 0xFA0, 0, NULL);
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

    void initialize_ai_level_system(int freddy_level, int bonnie_level, int chica_level, int foxy_level){

        freddy::path::init_path_array();
        bonnie::path::init_path_array();
        chica::path::init_path_array();
        foxy::path::init_path_array();

        if (save_system::saved_night != 7){
            freddy_script::ai_init(0);
            bonnie_script::ai_init(0);
            chica_script::ai_init(0);
            foxy_script::ai_init(0);
        }
        else{
            freddy_script::ai_init(freddy_level);
            bonnie_script::ai_init(bonnie_level);
            chica_script::ai_init(chica_level);
            foxy_script::ai_init(foxy_level);
        }
    }

    void run_ai_system(){
        freddy_script::ai_loop();
        bonnie_script::ai_loop();
        chica_script::ai_loop();
        foxy_script::ai_loop();

        if (freddy_script::should_update_components() == true && reloading_any == false){
            reloading_any = true;
            freddy::path::current_position = freddy_script::position;
            freddy::path::reload_path_image();

            if (freddy::memory_image != NULL){
                reloading_any = false;
            }
        }
        if (bonnie_script::should_update_components() == true && reloading_any == false){
            bonnie::path::current_position = bonnie_script::position;
            bonnie::path::reload_path_image();

            if (bonnie::memory_image != NULL){
                reloading_any = false;
            }
        }
        if (chica_script::should_update_components() == true && reloading_any == false){
            chica::path::current_position = chica_script::position;
            chica::path::reload_path_image();

            if (chica::memory_image != NULL){
                reloading_any = false;
            }
        }
        if (foxy_script::should_update_components() == true && reloading_any == false){
            foxy::path::current_position = foxy_script::position;
            foxy::path::reload_path_image();

            if (foxy::memory_image != NULL){
                reloading_any = false;
            }
        }
    }
}