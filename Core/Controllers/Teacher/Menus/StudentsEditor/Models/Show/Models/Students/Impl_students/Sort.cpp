#include "../Students.hpp"

void Students::set_sort_up(void) {
    if (!all_users.size()) {
        empty = true;
        return;
    }
    
    std::vector<std::string> tmp;
    for (int i = 0; i < all_users.size(); i++)
        tmp.push_back(all_users[i].user.second_name);
    std::sort(tmp.begin(), tmp.end());
    
    sort_up_users.clear();
    
    for (int i = 0; i < tmp.size(); i++) {
        for (int j = 0; j < all_users.size(); j++) {
            if (all_users[j].user.second_name == tmp[i]) {
                if (all_users[j].user.first_name.size() > MAXIMAL_SYMBOLS) {
                    std::string tmp_name = all_users[j].user.first_name;
                    all_users[j].user.first_name = "";
                    for (size_t i = 0; i < MAXIMAL_SYMBOLS; i++) {
                        all_users[j].user.first_name += tmp_name[i];
                    }
                    all_users[j].user.first_name[all_users[j].user.first_name.size() - 1] = '.';
                }
                if (all_users[j].user.second_name.size() > MAXIMAL_SYMBOLS) {
                    std::string tmp_name = all_users[j].user.second_name;
                    all_users[j].user.second_name = "";
                    for (size_t i = 0; i < MAXIMAL_SYMBOLS; i++) {
                        all_users[j].user.second_name += tmp_name[i];
                    }
                    all_users[j].user.second_name[all_users[j].user.second_name.size() - 1] = '.';
                }
                sort_up_users.push_back(all_users[j]);
                all_users.erase(all_users.begin() + j);
                break;
            }
        }
    }
}

void Students::set_sort_down(void) {
    sort_down_users.clear();
    for (int i = (int) sort_up_users.size() - 1; i >= 0; i--) {
        sort_down_users.push_back(sort_up_users[i]);
    }
}
