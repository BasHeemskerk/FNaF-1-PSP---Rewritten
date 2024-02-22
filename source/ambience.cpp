#include "included/ambience.hpp"

namespace ambience{
    namespace load_ambience_file{
        OSL_SOUND* file;
        OSL_SOUND* ambience_files[2];

        std::string root_ambience_folder = "romfs/ambience/office";
        std::string file_types[1];

        void init_ambience_loader(){
            file_types[0] = ".wav";
        }

        void load_seperate_ambience_file(std::string file_location, int filetype, int stream_mode){
            std::string generated_string = root_ambience_folder + file_location + file_types[filetype];

            if (filetype == 0){
                file = oslLoadSoundFileWAV(generated_string.c_str(), stream_mode);
            }
        }

        void load_into_array(){
            for (int i=0; i<2; i++){
                if (ambience_files[i] == NULL){
                    ambience_files[i] = file;
                    unload_memory_file();
                }
            }
        }

        void unload_memory_file(){
            oslDeleteSound(file);
        }

        void unload_array(){
            for (int i=0; i<2; i++){
                if (ambience_files[i] != NULL){
                    oslDeleteSound(ambience_files[i]);
                }
            }
        }


        void play_ambience(int file, int channel, bool loop){ //-1 means play all
            switch (file){
                case -1:
                    for (int i=0; i<2; i++){
                        if (ambience_files[i] != NULL){
                            oslPlaySound(ambience_files[i], channel + i);
                            if (loop){
                                oslSetSoundLoop(ambience_files[i] , 1);

                                if (oslGetSoundChannel(ambience_files[i]) == -1){
                                    oslPlaySound(ambience_files[i], channel + i);
                                }
                            }
                        }
                    }
                    break;
            }

            if (file > -1){
                if (ambience_files[file] != NULL){
                    oslPlaySound(ambience_files[file], channel);

                    if (loop){
                        oslSetSoundLoop(ambience_files[file], 1);

                        if (oslGetSoundChannel(ambience_files[file]) == -1){
                            oslPlaySound(ambience_files[file], channel);
                        }
                    }
                }
            }
        }





        /*
        void load_ambience_file(std::string file_location, int filetype, int stream_mode){
            std::string generated_string = root_music_folder + file_location + file_types[filetype];

            if (filetype == 0) { //WAV (only one supported)
                file = oslLoadSoundFileWAV(generated_string.c_str(), stream_mode);
            }

            for (int i=0; i<ambience_files.size() - 1; i++){
                if (ambience_files[i] == NULL){
                    ambience_files[i] = file;
                }
            }
        }

        void play_ambience_file(int channel, bool loop, int mem_number, bool all){
            if (file != NULL){

                if (all){
                    for (int i=0; i<ambience_files.size() -1; i++){
                        
                    }
                }
                else{

                }
                oslPlaySound(file, channel);

                if (loop){
                    oslSetSoundLoop(file, 1);
                    if (oslGetSoundChannel(file) == -1){
                        oslPlaySound(file, channel);
                    }
                }
            }
        }

        void stop_ambience_file(){
            oslStopSound(file);
        }

        void unload_ambience_file(){
            oslDeleteSound(file);
        }

        void check_for_playing(bool start_playing_now, int channel, bool loop){
            if (oslGetSoundChannel(file) == -1 && start_playing_now){
                play_ambience_file(channel, loop);
            }
        }
        */
    }
}