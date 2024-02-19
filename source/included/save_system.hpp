#include "global.hpp"

namespace save_system{

    extern int saved_night;
    extern int star_amount;
    extern int mode_one_unlocked;
    extern int mode_two_unlocked;

    namespace write_to_file{
        void save_to_file(int save_file, std::string data);
        void create_new_file(int save_file, std::string data);
    }
    namespace read_from_file{
        void read_file();
        void read_data();
    }
    namespace encrypt_decrypt{
        std::string encrypt(std::string input_string, std::string key);
        std::string decrypt(std::string input_string, std::string key);
    }
    namespace initialize{
        void initialize_save_system();
        void debug();
    }
}