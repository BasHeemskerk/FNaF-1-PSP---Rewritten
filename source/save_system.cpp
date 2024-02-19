#include "included/save_system.hpp"

namespace save_system{

    int saved_night = 1;
    int star_amount = 0;
    int mode_one_unlocked = 0;
    int mode_two_unlocked = 0;

    std::string night;
    std::string stars;
    std::string mode_one;
    std::string mode_two;

    std::string night_encrypted;
    std::string night_decrypted;

    std::string stars_encrypted;
    std::string stars_decrypted;

    std::string mode_one_encrypted;
    std::string mode_one_decrypted;

    std::string mode_two_encrypted;
    std::string mode_two_decrypted;

    const char *night_file = "saves/night.fnafportable";
    const char *star_file = "saves/stars.fnafportable";
    const char *mode_one_file = "saves/mode_one.fnafportable";
    const char *mode_two_file = "saves/mode_two.fnafportable";

    const char *encryption_key = "fpsp_xor";

    bool files_exist = false;

    namespace write_to_file{
        void save_to_file(int save_file, std::string data){

            std::remove(night_file);
            std::remove(star_file);
            std::remove(mode_one_file);
            std::remove(mode_two_file);

            if (save_file == 1){ //night file
                std::fstream night_data_file(night_file);
                night_data_file << encrypt_decrypt::encrypt(data, encryption_key);
            }
            if (save_file == 2){ //star file
                std::fstream stars_data_file(star_file);
                stars_data_file << encrypt_decrypt::encrypt(data, encryption_key);
            }
            if (save_file == 3){ //night 6 (mode one) file
                std::fstream mode_one_data_file(mode_one_file);
                mode_one_data_file << encrypt_decrypt::encrypt(data, encryption_key);
            }
            if (save_file == 4){ //custom night (mode two) file
                std::fstream mode_two_data_file(mode_two_file);
                mode_two_data_file << encrypt_decrypt::encrypt(data, encryption_key);
            }
        }

        void create_new_file(int save_file, std::string data){
            if (save_file == 1){ //night file
                std::ofstream night_data_file(night_file);
                night_data_file << encrypt_decrypt::encrypt(data, encryption_key);
            }
            if (save_file == 2){ //star file
                std::ofstream stars_data_file(star_file);
                stars_data_file << encrypt_decrypt::encrypt(data, encryption_key);
            }
            if (save_file == 3){ //night 6 (mode one) file
                std::ofstream mode_one_data_file(mode_one_file);
                mode_one_data_file << encrypt_decrypt::encrypt(data, encryption_key);
            }
            if (save_file == 4){ //custom night (mode two) file
                std::ofstream mode_two_data_file(mode_two_file);
                mode_two_data_file << encrypt_decrypt::encrypt(data, encryption_key);
            }


        }
    }
    namespace read_from_file{
        void read_file(){
           std::fstream night_data_file(night_file);
           std::fstream stars_data_file(star_file);
           std::fstream mode_one_data_file(mode_one_file);
           std::fstream mode_two_data_file(mode_two_file);

           if (!night_data_file || !stars_data_file || !mode_one_data_file || !mode_two_data_file){
                files_exist = false;

                std::remove(night_file);
                std::remove(star_file);
                std::remove(mode_one_file);
                std::remove(mode_two_file);

                write_to_file::create_new_file(1, "night = 1");
                write_to_file::create_new_file(2, "stars = 0");
                write_to_file::create_new_file(3, "mode unlocked = 1");
                write_to_file::create_new_file(4, "mode unlocked = 1");

                files_exist = true;
            }
            else{
                files_exist = true;
            }

            if (files_exist){
                if (saved_night != 7){
                    read_data();
                }

                initialize::debug();
            }
            
        }

        void read_data(){

            std::fstream night_data_file(night_file);
            std::fstream stars_data_file(star_file);
            std::fstream mode_one_data_file(mode_one_file);
            std::fstream mode_two_data_file(mode_two_file);

            std::getline(night_data_file, night);
            std::getline(stars_data_file, stars);
            std::getline(mode_one_data_file, mode_one);
            std::getline(mode_two_data_file, mode_two);

            night_encrypted = night;
            stars_encrypted = stars;
            mode_one_encrypted = mode_one;
            mode_two_encrypted = mode_two;

            night_decrypted = encrypt_decrypt::decrypt(night_encrypted, encryption_key);
            stars_decrypted = encrypt_decrypt::decrypt(stars_encrypted, encryption_key);
            mode_one_decrypted = encrypt_decrypt::decrypt(mode_one_encrypted, encryption_key);
            mode_two_decrypted = encrypt_decrypt::decrypt(mode_two_encrypted, encryption_key);

            if (night_decrypted == "night = 1"){
                saved_night = 1;
            }
            if (night_decrypted == "night = 2"){
                saved_night = 2;
            }
            if (night_decrypted == "night = 3"){
                saved_night = 3;
            }
            if (night_decrypted == "night = 4"){
                saved_night = 4;
            }
            if (night_decrypted == "night = 5"){
                saved_night = 5;
            }

            if (stars_decrypted == "stars = 0"){
                star_amount = 0;
            }
            if (stars_decrypted == "stars = 1"){
                star_amount = 1;
            }
            if (stars_decrypted == "stars = 2"){
                star_amount = 2;
            }
            if (stars_decrypted == "stars = 3"){
                star_amount = 3;
            }
            
            if (mode_one_decrypted == "mode unlocked = 0"){
                mode_one_unlocked = 0;
            }
            if (mode_one_decrypted == "mode unlocked = 1"){
                mode_one_unlocked = 1;
            }

            if (mode_two_decrypted == "mode unlocked = 0"){
                mode_two_unlocked = 0;
            }
            if (mode_two_decrypted == "mode unlocked = 1"){
                mode_two_unlocked = 1;
            }
        }
    }
    namespace encrypt_decrypt{
        std::string encrypt(std::string input_string, std::string key){
            
            std::string tmp(key);
            while (key.size() < input_string.size())
                key += tmp;
            
            for (std::string::size_type i = 0; i < input_string.size(); ++i)
                input_string[i] ^= key[i];

            return input_string;
        }
        std::string decrypt(std::string input_string, std::string key){

            return encrypt(input_string, key);

        }
    }
    namespace initialize{
        void initialize_save_system(){
            read_from_file::read_file();
        }

        void debug(){
            std::cout << "night data encrypted | " + night_encrypted << std::endl;
            std::cout << "night data decrypted | " + night_decrypted << std::endl;

            std::cout << "star data encrypted | " + stars_encrypted << std::endl;
            std::cout << "star data decrypted | " + stars_decrypted << std::endl;
            
            std::cout << "mode one data encrypted | " + mode_one_encrypted << std::endl;
            std::cout << "mode one data decrypted | " + mode_one_decrypted << std::endl;
            
            std::cout << "mode two data encrypted | " + mode_two_encrypted << std::endl;
            std::cout << "mode two data decrypted | " + mode_two_decrypted << std::endl;
        }
    }
}