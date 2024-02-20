#include "included/camera.hpp"

namespace camera{

    //int ThreadIdA;
    //int PspThreadStatus = 1;

    namespace update{

        /*
        std::string target_main_directory = "romfs/gfx/office/camera/";
        std::string target_sub_directory = "main/";
        std::string target_file = "cam1a";
        std::string target_file_extentions = ".png";

        int load_thread(SceSize args, void* argp){

            std::string target;
            target = target_main_directory + target_sub_directory + target_file + target_file_extentions;

            i_loader::camera_loader::load_target(target);

            ThreadIdA = sceKernelExitThread(PspThreadStatus);

            return 0;
        }

        void initialize_load_thread(){
            ThreadIdA = sceKernelCreateThread("load_thread", load_thread, 0x11, 0xFA0, 0, NULL);
            sceKernelStartThread(ThreadIdA, 0, NULL);
        }
        */
    }
    namespace cycle_camera{
        int current_camera = 0; //we start on cam 1a
    }
}