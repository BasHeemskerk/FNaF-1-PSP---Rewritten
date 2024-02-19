#include "included/music.hpp"

namespace music{

    namespace load_music_file{

        OSL_SOUND* file;

        std::string root_music_folder = "romfs/music/";
        std::string file_types[1];

        void init_music_loader(){
            file_types[0] = ".wav";
        }

        void load_music_file(std::string file_location, int filetype, int stream_mode){
            
            if (file == NULL){
                std::string generated_string = root_music_folder + file_location + file_types[filetype];

                if (filetype == 0) { //WAV (only one supported)
                    file = oslLoadSoundFileWAV(generated_string.c_str(), stream_mode);
                }
            }
            
        }

        void play_music_file(int channel, bool loop){
            if (file != NULL){
                oslPlaySound(file, channel);

                if (loop){
                    oslSetSoundLoop(file, 1);
                    if (oslGetSoundChannel(file) == -1){
                        oslPlaySound(file, channel);
                    }
                }
            }
        }

        void stop_music_file(){
            oslStopSound(file);
        }

        void unload_music_file(){
            oslDeleteSound(file);
        }

        void check_for_playing(bool start_playing_now, int channel, bool loop){
            if (oslGetSoundChannel(file) == -1 && start_playing_now){
                play_music_file(channel, loop);
            }
        }
    }
}