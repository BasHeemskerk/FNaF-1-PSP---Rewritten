#include "global.hpp"

namespace ambience{
    namespace load_ambience_file{

        extern OSL_SOUND* file;
        extern OSL_SOUND* ambience_files[2];

        extern std::string root_ambience_folder;
        extern std::string file_types[1];

        void init_ambience_loader();
        void load_seperate_ambience_file(std::string file_location, int filetype, int stream_mode);
        void load_into_array();
        void unload_memory_file();
        void unload_array();
        void play_ambience(int file, int channel, bool loop);
    }
}