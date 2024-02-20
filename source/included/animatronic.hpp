#include "global.hpp"
#include "image_loader.hpp"
#include "camera.hpp"
#include "freddy.hpp"
#include "bonnie.hpp"
#include "chica.hpp"
#include "foxy.hpp"

namespace animatronic{
    namespace freddy{
        extern int ai_level;
        extern int first_digit;
        extern int second_digit;

        extern Image *memory_image;

        namespace path{
            extern int current_position;
            extern const char *path_array[4];
            extern const char *path_type[4];

            void init_path_array();
            
            void create_load_thread();
            int load_path_image(SceSize args, void* argp);
            void clear_path_image();
            void reload_path_image();
        }
    }
    namespace bonnie{
        extern int ai_level;
        extern int first_digit;
        extern int second_digit;

        extern Image *memory_image;
        
        namespace path{
            extern int current_position;
            extern const char *path_array[7];
            extern const char *path_type[7];

            void init_path_array();
            
            void create_load_thread();
            int load_path_image(SceSize args, void* argp);
            void clear_path_image();
            void reload_path_image();
        }
    }
    namespace chica{
        extern int ai_level;
        extern int first_digit;
        extern int second_digit;

        extern Image *memory_image;
        
        namespace path{
            extern int current_position;
            extern const char *path_array[7];
            extern const char *path_type[7];

            void init_path_array();
            
            void create_load_thread();
            int load_path_image(SceSize args, void* argp);
            void clear_path_image();
            void reload_path_image();
        }
    }
    namespace foxy{
        extern int ai_level;
        extern int first_digit;
        extern int second_digit;

        extern Image *memory_image;
        
        namespace path{
            extern int current_position;
            extern const char *path_array[3];
            extern const char *path_type[3];

            void init_path_array();
            
            void create_load_thread();
            int load_path_image(SceSize args, void* argp);
            void clear_path_image();
            void reload_path_image();
        }
    }

    void initialize_ai_level_system(int freddy_level, int bonnie_level, int chica_level, int foxy_level);
}