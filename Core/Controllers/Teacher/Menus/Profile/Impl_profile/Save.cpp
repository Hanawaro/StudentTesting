#include "../Profile.hpp"

void Profile::set_save_login(void) {
    std::fstream save("Source/authorization");
    save.seekp(0, std::ios::beg);
    save.write(Security::Cipher::get_chipher(new_real_login).c_str(), 255);
    save.close();
}

void Profile::set_save_password(void) {
    std::fstream save("Source/authorization");
    save.seekp(255, std::ios::beg);
    save.write(Security::Cipher::get_chipher(Security::Hash::get_hash_with_sult(real_new_pass)).c_str(), 255);
    save.close();
}
