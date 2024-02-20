#include "global.hpp"
#include "image_loader.hpp"

namespace camera{

    extern int ThreadIdA;
    extern int PspThreadStatus;

    namespace update{

        extern std::string target_main_directory;
        extern std::string target_sub_directory;
        extern std::string target_file;
        extern std::string target_file_extentions;

        int load_thread(SceSize args, void* argp);
        void initialize_load_thread();
    }
    namespace cycle_camera{
        extern int current_camera; //we start on cam 1a
    }
}