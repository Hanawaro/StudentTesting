#include "db_user.hpp"

bool db_user::get_login(const std::string& key) const {
    char tmp[255];
    int limit = 0;
    std::ifstream db(m_path, std::ios::binary);
    bool notFound = true;
    if (db) {
        do {
            db.seekg(limit, std::ios::beg);
            db.read(tmp, 255);
			std::string del = std::string(Security::Cipher::get_un_chipher(tmp).c_str());
            if (std::string(Security::Cipher::get_un_chipher(tmp).c_str()) == key) {
                notFound = false;
            }
            if (db.eof())
                break;
            limit += 255*4 + 4;
        } while(notFound);
        db.close();
    }
    return !notFound;
}

bool db_user::get_status(const std::string& key) const {
    uint32_t result;
    char tmp[255] = { '\0' };
    int limit = 0;
    std::ifstream db(m_path, std::ios::binary);
    bool notFound = true;
    if (db) {
        do {
            db.seekg(limit, std::ios::beg);
            db.read(tmp, 255);
            if (std::string(Security::Cipher::get_un_chipher(tmp).c_str()) == key) {
                db.seekg(limit + 255);
                db.read((char *)&result, sizeof result);
                db.close();
                if (result == 404)
                    return true;
                else
                    return false;
            }
            if (db.eof())
                break;
            limit += 255*4 + 4;
        } while(notFound);
        db.close();
    }
    return false;
}

std::string db_user::get_name(const std::string& key) const {
    std::string result = "";
    char tmp[255] = { '\0' };
    int limit = 0;
    std::ifstream db(m_path, std::ios::binary);
    bool notFound = true;
    if (db) {
        do {
            db.seekg(limit, std::ios::beg);
            db.read(tmp, 255);
			//std::string deletee = std::string(Security::Cipher::get_un_chipher(tmp).c_str());
            if (std::string(Security::Cipher::get_un_chipher(tmp).c_str())== key) {
                db.seekg(limit + 2*255 + 4);
                char tmp[255];
                db.read(tmp, 255);
                for (int i = 0; i < 255; i++)
                    result += tmp[i];
                db.close();
                return result;
            }
            if (db.eof())
                break;
            limit += 255*4 + 4;
        } while(notFound);
        db.close();
    }
    return result;
}

std::string db_user::get_second_name(const std::string& key) const {
    std::string result = "";
    char tmp[255] = { '\0' };
    int limit = 0;
    std::ifstream db(m_path, std::ios::binary);
    bool notFound = true;
    if (db) {
        do {
            db.seekg(limit, std::ios::beg);
            db.read(tmp, 255);
            if (std::string(Security::Cipher::get_un_chipher(tmp).c_str()) == key) {
                db.seekg(limit + 3*255 + 4);
                char tmp[255];
                db.read(tmp, 255);
                for (int i = 0; i < 255; i++)
                    result += tmp[i];
                db.close();
                return result;
            }
            if (db.eof())
                break;
            limit += 255*4 + 4;
        } while(notFound);
        db.close();
    }
    return result;
}

std::string db_user::get_password_hash(const std::string& key) const {
    std::string result = "";
    char tmp[255] = { '\0' };
    int limit = 0;
    std::ifstream db(m_path, std::ios::binary);
    bool notFound = true;
    if (db) {
        do {
            db.seekg(limit, std::ios::beg);
            db.read(tmp, 255);
            if (std::string(Security::Cipher::get_un_chipher(tmp).c_str())== key) {
                db.seekg(limit + 255 + 4, std::ios::beg);
                char hash[255];
                db.read(hash, 255);
                db.close();
                return Security::Cipher::get_un_chipher(hash).c_str();
            }
            if (db.eof())
                break;
            limit += 255*4 + 4;
        } while(notFound);
        db.close();
    }
    return result;
}

bool db_user::compare_password_hash(const std::string& key, const std::string& hash) const {
    if (hash == get_password_hash(key))
        return true;
    return false;
}

void db_user::set_login(const std::string& key, const std::string& login) const {
    char tmp[255] = { '\0' };
    int limit = 0;
    std::ifstream db(m_path, std::ios::binary);
    bool notFound = true;
    if (db) {
        do {
            db.seekg(limit, std::ios::beg);
            db.read(tmp, 255);
            if (std::string(Security::Cipher::get_un_chipher(tmp).c_str()) == key) {
				db.close();
				std::ofstream write_login(m_path, std::ios::binary | std::ios::in);
				write_login.seekp(limit, std::ios::beg);
				write_login.write(Security::Cipher::get_chipher(login.c_str()).c_str(), 255);
				write_login.close();
				return;
            }
            if (db.eof())
                break;
            limit += 255*4 + 4;
        } while(notFound);
        db.close();
    }
}

void db_user::set_name(const std::string& key, const std::string& name) const {
    char tmp[255] = { '\0' };
    int limit = 0;
    std::ifstream db(m_path, std::ios::binary);
    bool notFound = true;
    if (db) {
        do {
            db.seekg(limit, std::ios::beg);
            db.read(tmp, 255);
            if (std::string(Security::Cipher::get_un_chipher(tmp).c_str()) == key) {
				db.close();
				std::ofstream write_login(m_path, std::ios::binary | std::ios::in);
				write_login.seekp(limit, std::ios::beg);
				write_login.seekp(limit + 2*255 + 4, std::ios::beg);
				write_login.write(Security::Cipher::get_chipher(name.c_str()).c_str(), 255);
				write_login.close();
				return;
            }
            if (db.eof())
                break;
            limit += 255*4 + 4;
        } while(notFound);
        db.close();
    }
}

void db_user::set_second_name(const std::string& key, const std::string& secondName) const {
    char tmp[255] = { '\0' };
    int limit = 0;
    std::ifstream db(m_path, std::ios::binary);
    bool notFound = true;
    if (db) {
        do {
            db.seekg(limit, std::ios::beg);
            db.read(tmp, 255);
            if (std::string(Security::Cipher::get_un_chipher(tmp).c_str()) == key) {
				db.close();
				std::ofstream write_login(m_path, std::ios::binary | std::ios::in);
				write_login.seekp(limit, std::ios::beg);
				write_login.seekp(limit + 3*255 + 4, std::ios::beg);
				write_login.write(Security::Cipher::get_chipher(secondName.c_str()).c_str(), 255);
				write_login.close();
				return;
            }
            if (db.eof())
                break;
            limit += 255*4 + 4;
        } while(notFound);
        db.close();
    }
}

void db_user::set_password(const std::string& key, const std::string& password) const {
    char tmp[255] = { '\0' };
    int limit = 0;
    std::ifstream db(m_path, std::ios::binary);
    bool notFound = true;
    if (db) {
        do {
            db.seekg(limit, std::ios::beg);
            db.read(tmp, 255);
            if (std::string(Security::Cipher::get_un_chipher(tmp).c_str()) == key) {
				db.close();
				std::ofstream write_login(m_path, std::ios::binary | std::ios::in);
				write_login.seekp(limit, std::ios::beg);
				write_login.seekp(limit + 255 + 4, std::ios::beg);
				write_login.write(Security::Cipher::get_chipher(Security::Hash::get_hash_with_sult(password).c_str()).c_str(), 255);
				write_login.close();
				return;
            }
            if (db.eof())
                break;
            limit += 255*4 + 4;
        } while(notFound);
        db.close();
    }
}

void db_user::add_user(const std::string& login, uint32_t status, const std::string& name, const std::string& secondName, const std::string& password) const {
    std::ofstream db(m_path, std::ios::binary | std::ios::in);
    db.seekp(0, std::ios::end);
    
    uint32_t index = status;
    
    db.write(Security::Cipher::get_chipher(login).c_str(), 255);
    db.write((char *)&index, 4);
    db.write(Security::Cipher::get_chipher(Security::Hash::get_hash_with_sult(password)).c_str(), 255);
    db.write(Security::Cipher::get_chipher(name).c_str(), 255);
    db.write(Security::Cipher::get_chipher(secondName).c_str(), 255);
    
	db.close();

    if (status != 404)
        m_db_student.add_student(login, Mark::Empty, 3, Mark::Empty, 3, Mark::Empty, 3, Mark::Empty, 1);

}

void db_user::remove_user(const std::string& key) {
    // replace
    std::ifstream db_tmp(m_path, std::ios::binary);
    
    char input_login[255];
    char input_name[255];
    char input_second_name[255];
    char input_password[255];
    uint32_t status;
    int limit = 0;
    long long real_limit = 0;
    bool notFound = true;
    
    if (db_tmp) {
        do {
            db_tmp.seekg(limit, std::ios::beg);
            db_tmp.read(input_login, 255);
            if (std::string(Security::Cipher::get_un_chipher(input_login).c_str()) == key) {
                notFound = false;
            }
            if (db_tmp.eof())
                break;
            limit += 255*4 + 4;
        } while(notFound);
    }
    
    db_tmp.seekg(0, std::ios::end);
    real_limit = db_tmp.tellg();
    db_tmp.close();
    
    if (!notFound) {
        // sudents db
        m_db_student.remove_student(key);
        // rewrite
        std::ifstream db(m_path, std::ios::binary);
        std::ofstream tmp(m_path + ".tmp", std::ios::binary);
        
        limit = 0;
        db.seekg(limit, std::ios::beg);
        while (limit < real_limit) {
            db.read(input_login, 255);
            db.read((char *)&status, sizeof(uint32_t));
            db.read(input_password, 255);
            db.read(input_name, 255);
            db.read(input_second_name, 255);
            if (std::string(Security::Cipher::get_un_chipher(input_login).c_str()) == key) {
                limit += 255*4 + 4;
                continue;
            }
            tmp.write(input_login, 255);
            tmp.write((char *)&status, sizeof(uint32_t));
            tmp.write(input_password, 255);
            tmp.write(input_name, 255);
            tmp.write(input_second_name, 255);
            limit += 255*4 + 4;
        }
        
        db.close();
        tmp.close();
        
        remove(m_path.c_str());
        rename((m_path + ".tmp").c_str(), m_path.c_str());
    }
}

User db_user::load_user(int index) const {
    std::ifstream db(m_path, std::ios::binary);
    
    db.seekg(index * (255*4 + 4), std::ios::beg);
    
    char login[255];
    char name[255];
    char second_name[255];
    uint32_t status;
    
    User user;
    
    db.read(login, 255);
    db.read((char *)&status, sizeof(uint32_t));
    db.seekg(255, std::ios::cur);
    db.read(name, 255);
    db.read(second_name, 255);
    
    db.close();
    
    user.login = Security::Cipher::get_un_chipher(login).c_str();
    if (status == 404)
        user.status = Status::Teacher;
    else
        user.status = Status::Student;
    user.name = Security::Cipher::get_un_chipher(name).c_str();
    user.second_name = Security::Cipher::get_un_chipher(second_name).c_str();
    
    return user;
}

User db_user::load_user(const std::string& key) const {
    
    std::string login;
    std::string name;
    std::string second_name;
    uint32_t status = 0;
    
    char tmp[255];
    int limit = 0;
    std::ifstream db(m_path, std::ios::binary);
    bool notFound = true;
    if (db) {
        do {
            db.seekg(limit, std::ios::beg);
            db.read(tmp, 255);
            if (std::string(Security::Cipher::get_un_chipher(tmp).c_str()) == key) {
                login = tmp;
                db.read((char *)&status, sizeof(uint32_t));
                db.seekg(255, std::ios::cur);
                db.read(tmp, 255);
                name = tmp;
                db.read(tmp, 255);
                second_name = tmp;
            }
            if (db.eof())
                break;
            limit += 255*4 + 4;
        } while(notFound);
        db.close();
    }
    
    User user;
    
    user.login = Security::Cipher::get_un_chipher(login).c_str();
    if (status == 404)
        user.status = Status::Teacher;
    else
        user.status = Status::Student;
    user.name = Security::Cipher::get_un_chipher(name).c_str();
    user.second_name = Security::Cipher::get_un_chipher(second_name).c_str();
    
    return user;
}

void db_user::load_users(std::vector<User>& users) {
    std::ifstream db(m_path, std::ios::binary);
    db.seekg(0, std::ios::end);
    long long size = (int) db.tellg() / (255*4 + 4);
    db.close();
    
    users.clear();
    
    for (int i = 0; i < size; i++) {
        User tmp = load_user(i);
        if (tmp.status == Status::Student) {
            users.push_back(tmp);
        }
    }
}

void db_user::load_users(std::vector<info_student>& users) {
    std::ifstream db(m_path, std::ios::binary);
    db.seekg(0, std::ios::end);
    long long size = (int) db.tellg() / (255*4 + 4);
    db.close();
    
    users.clear();
    
    for (int i = 0; i < size; i++) {
        User tmp = load_user(i);
        if (tmp.status == Status::Student) {
            users.push_back( {tmp, m_db_student.load_student(tmp.login)} );
        }
    }
}
