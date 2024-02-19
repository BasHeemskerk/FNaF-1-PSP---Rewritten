#include "global.hpp"

namespace music{

    namespace load_music_file{
        void init_music_loader();
        void load_music_file(std::string file_location, int filetype, int stream_mode);
        void play_music_file(int channel, bool loop);
        void stop_music_file();
        void unload_music_file();
        void check_for_playing(bool start_playing_now, int channel, bool loop);
    }
}