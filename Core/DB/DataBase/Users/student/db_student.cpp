#include "db_student.hpp"

static int32_t getMark(Mark mark) {
    int32_t tmp_mark = 0;
    int sum = 0;
    switch (mark) {
        case Mark::Empty:
            do {
                tmp_mark = rand()%1000;
                sum = tmp_mark%10 + tmp_mark/10 % 10 + tmp_mark/100;
            } while ( sum == 2 || sum == 3 || sum == 4 || sum == 5 );
            break;
        case Mark::Two:
            do {
                tmp_mark = rand()%1000;
                sum = tmp_mark%10 + tmp_mark/10 % 10 + tmp_mark/100;
            } while ( sum != 2 );
            break;
        case Mark::Three:
            do {
                tmp_mark = rand()%1000;
                sum = tmp_mark%10 + tmp_mark/10 % 10 + tmp_mark/100;
            } while ( sum != 3 );
            break;
        case Mark::Four:
            do {
                tmp_mark = rand()%1000;
                sum = tmp_mark%10 + tmp_mark/10 % 10 + tmp_mark/100;
            } while ( sum != 4 );
            break;
        case Mark::Five:
            do {
                tmp_mark = rand()%1000;
                sum = tmp_mark%10 + tmp_mark/10 % 10 + tmp_mark/100;
            } while ( sum != 5 );
            break;
    }
    return tmp_mark;
}

static Mark getMark(int32_t mark) {
    int sum = mark%10 + mark/10 % 10 + mark/100;
    switch (sum) {
        case 2:
            return Mark::Two;
        case 3:
             return Mark::Three;
        case 4:
             return Mark::Four;
        case 5:
             return Mark::Five;
        default:
            return Mark::Empty;
    }
}

static int32_t getAmount(int32_t amount) {
    int32_t tmp_amount = 0;
    int sum = 0;
    switch (amount) {
        case 0:
            do {
                tmp_amount = rand()%1000;
                sum = tmp_amount%10 + tmp_amount/10 % 10 + tmp_amount/100;
            } while ( sum == 1 || sum == 2 || sum == 3 );
            break;
        case 1:
            do {
                tmp_amount = rand()%1000;
                sum = tmp_amount%10 + tmp_amount/10 % 10 + tmp_amount/100;
            } while ( sum != 1 );
            break;
        case 2:
            do {
                tmp_amount = rand()%1000;
                sum = tmp_amount%10 + tmp_amount/10 % 10 + tmp_amount/100;
            } while ( sum != 2 );
            break;
        case 3:
            do {
                tmp_amount = rand()%1000;
                sum = tmp_amount%10 + tmp_amount/10 % 10 + tmp_amount/100;
            } while ( sum != 3 );
            break;
    }
    return tmp_amount;
}

static int32_t getBackAmount(int32_t amount) {
    int sum = amount%10 + amount/10 % 10 + amount/100;
    switch (sum) {
        case 1:
            return 1;
        case 2:
             return 2;
        case 3:
             return 3;
        default:
            return 0;
    }
}

void db_student::set_login(const std::string& key, const std::string& login) const {
    char tmp[255];
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
				write_login.seekp(limit, std::ios::beg);
				write_login.write(Security::Cipher::get_chipher(login.c_str()).c_str(), 255);
				write_login.close();
				return;
            }
            if (db.eof())
                break;
            limit += 8 * 4 + 255;
        } while(notFound);
        db.close();
    }
}

void db_student::set_first(const std::string& key, Mark first, int32_t amount) const {
    char tmp[255];
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
                int32_t tmp_mark = getMark(first);
                int32_t tmp_amount = getAmount(amount);
				write_login.seekp(limit + 255, std::ios::beg);
				write_login.write((char *)&tmp_mark, sizeof(int32_t));
				write_login.write((char *)&tmp_amount, sizeof(int32_t));
				write_login.close();
				return;
            }
            if (db.eof())
                break;
            limit += 8 * 4 + 255;
        } while(notFound);
        db.close();
    }
}

void db_student::set_second(const std::string& key, Mark second, int32_t amount) const {
    char tmp[255];
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
                int32_t tmp_mark = getMark(second);
                int32_t tmp_amount = getAmount(amount);
				write_login.seekp(limit + 255 + 2*4, std::ios::beg);
				write_login.write((char *)&tmp_mark, sizeof(int32_t));
				write_login.write((char *)&tmp_amount, sizeof(int32_t));
				write_login.close();
				return;
            }
            if (db.eof())
                break;
            limit += 8 * 4 + 255;
        } while(notFound);
        db.close();
    }
}

void db_student::set_third(const std::string& key, Mark third, int32_t amount) const {
    char tmp[255];
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
                int32_t tmp_mark = getMark(third);
                int32_t tmp_amount = getAmount(amount);
				write_login.seekp(limit + 255 + 4 * 4, std::ios::beg);
				write_login.write((char *)&tmp_mark, sizeof(int32_t));
				write_login.write((char *)&tmp_amount, sizeof(int32_t));
				write_login.close();
				return;
            }
            if (db.eof())
                break;
            limit += 8 * 4 + 255;
        } while(notFound);
        db.close();
    }
}

void db_student::set_total(const std::string& key, Mark total, int32_t amount) const {
    char tmp[255];
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
                int32_t tmp_mark = getMark(total);
                int32_t tmp_amount = getAmount(amount);
				write_login.seekp(limit + 255 + 6 * 4, std::ios::beg);
				write_login.write((char *)&tmp_mark, sizeof(int32_t));
				write_login.write((char *)&tmp_amount, sizeof(int32_t));
				write_login.close();
				return;
            }
            if (db.eof())
                break;
            limit += 8 * 4 + 255;
        } while(notFound);
        db.close();
    }
}
    
void db_student::add_student(const std::string& key, Mark first, int32_t amount_of_first, Mark second, int32_t amount_of_second, Mark third, int32_t amount_of_third, Mark total, int32_t amount_of_total) const {
    std::ofstream db(m_path, std::ios::binary | std::ios::in);
	db.seekp(0, std::ios::end);
    
    int32_t tmp_mark = 0;
    int32_t tmp_amount = 0;
    
    db.write(Security::Cipher::get_chipher( key ).c_str(), 255);
    
    tmp_mark = getMark(first);
    tmp_amount = getAmount(amount_of_first);
    db.write((char *)&tmp_mark, 4);
    db.write((char *)&tmp_amount, 4);
    
    tmp_mark = getMark(second);
    tmp_amount = getAmount(amount_of_second);
    db.write((char *)&tmp_mark, 4);
    db.write((char *)&tmp_amount, 4);
    
    tmp_mark = getMark(third);
    tmp_amount = getAmount(amount_of_third);
    db.write((char *)&tmp_mark, 4);
    db.write((char *)&tmp_amount, 4);
    
    tmp_mark = getMark(total);
    tmp_amount = getAmount(amount_of_total);
    db.write((char *)&tmp_mark, 4);
    db.write((char *)&tmp_amount, 4);

    db.close();
}

void db_student::remove_student(const std::string& key) {
    // replace
    std::ifstream db_tmp(m_path, std::ios::binary);
    
    char input_key[255];
    int32_t tmp_mark = 0;
    int32_t tmp_amount = 0;
    
    int limit = 0;
    long long real_limit = 0;
    bool notFound = true;
    
    if (db_tmp) {
        do {
            db_tmp.seekg(limit, std::ios::beg);
            db_tmp.read(input_key, 255);
            if (std::string(Security::Cipher::get_un_chipher(input_key).c_str()) == key) {
                notFound = false;
            }
            if (db_tmp.eof())
                break;
            limit += 8*4 + 255;
        } while(notFound);
    }
    
    db_tmp.seekg(0, std::ios::end);
    real_limit = db_tmp.tellg();
    db_tmp.close();
    
    if (!notFound) {
        // rewrite
        std::ifstream db(m_path, std::ios::binary);
        std::ofstream tmp(m_path + ".tmp", std::ios::binary);
        
        limit = 0;
        db.seekg(limit, std::ios::beg);
        while (limit < real_limit) {
            db.read(input_key, 255);
            
            if (std::string(Security::Cipher::get_un_chipher(input_key).c_str()) == key) {
                limit += 8*4 + 255;
                continue;
            }
            
            tmp.write(Security::Cipher::get_chipher(key).c_str(), 255);
            
            for (int i = 0; i < 4; i++) {
                db.read((char *)&tmp_mark, sizeof(int32_t));
                db.read((char *)&tmp_amount, sizeof(int32_t));
                tmp.write((char *)&tmp_mark, sizeof(int32_t));
                tmp.write((char *)&tmp_amount, sizeof(int32_t));
            }
            
            limit += 8*4 + 255;
        }
        
        db.close();
        tmp.close();
        
        remove(m_path.c_str());
        rename((m_path+ ".tmp").c_str(), m_path.c_str());
    }
}

class Student db_student::load_student(const std::string& key) const {
    class Student student;
    
    student.first = student.second = student.third = student.total = Mark::Empty;
    student.amount_of_first = student.amount_of_second = student.amount_of_third = student.amount_of_total = -1;

    char tmp[255];
    int limit = 0;
    std::ifstream db(m_path, std::ios::binary);
    bool notFound = true;
    if (db) {
        do {
            db.seekg(limit, std::ios::beg);
            db.read(tmp, 255);
	
            if (std::string(Security::Cipher::get_un_chipher(tmp).c_str()) == key) {
                int32_t tmp_mark = 0;
                int32_t tmp_amount = 0;
                
                db.read((char *)&tmp_mark, sizeof(int32_t));
                db.read((char *)&tmp_amount, sizeof(int32_t));
                student.first = getMark(tmp_mark);
                student.amount_of_first = getBackAmount(tmp_amount);
                
                db.read((char *)&tmp_mark, sizeof(int32_t));
                db.read((char *)&tmp_amount, sizeof(int32_t));
                student.second = getMark(tmp_mark);
                student.amount_of_second = getBackAmount(tmp_amount);
                
                db.read((char *)&tmp_mark, sizeof(int32_t));
                db.read((char *)&tmp_amount, sizeof(int32_t));
                student.third = getMark(tmp_mark);
                student.amount_of_third = getBackAmount(tmp_amount);
                
                db.read((char *)&tmp_mark, sizeof(int32_t));
                db.read((char *)&tmp_amount, sizeof(int32_t));
                student.total = getMark(tmp_mark);
                student.amount_of_total = getBackAmount(tmp_amount);
				db.close();
                return student;
            }
            if (db.eof())
                break;
            limit += 8*4 + 255;
        } while(notFound);
        db.close();
    }

    return student;
}
