#include "db_test_first.hpp"

void db_test_first::add_test(Test& test) {
    std::ifstream db(m_Path, std::ios::binary);
    db.seekg(0, std::ios::end);
    auto size = db.tellg();
    
    if (size) {
        db.seekg(-(4*2+255+127*3), std::ios::end);
        db.read((char *)&(test.id), sizeof(uint32_t));
    } else {
        test.id = 0;
    }
    
    test.id++;
	db.close();
	std::ofstream add(m_Path, std::ios::binary | std::ios::in);
	
	add.seekp(0, std::ios::end);
	add.write((char *)&(test.id), sizeof(uint32_t));
	add.write(Security::Cipher::getChipher(test.question).c_str(), 255);
    for (size_t i = 0; i < 3; i++)
		add.write(Security::Cipher::getChipher(test.answer[i]).c_str(), 127);
	add.write((char *)&(test.right), sizeof(uint32_t));
    
	add.close();
}

void db_test_first::edit_test(const Test& test) {
    std::ifstream db(m_Path, std::ios::binary);
    
    uint32_t tmp;
    int limit = 0;
    bool notFound = true;
    if (db) {
        do {
            db.seekg(limit, std::ios::beg);
            db.read((char *)&tmp, sizeof(uint32_t));
            if (tmp == test.id) {
				db.close();
				std::ofstream add(m_Path, std::ios::binary | std::ios::in);
				add.seekp(limit);
				add.write((char *)&test.id, sizeof(uint32_t));
				add.write(Security::Cipher::getChipher(test.question).c_str(), 255);
                for (size_t i = 0; i < 3; i++)
					add.write(Security::Cipher::getChipher(test.answer[i]).c_str(), 127);
				add.write((char *)&test.right, sizeof(uint32_t));
				add.close();
				return;
            }
            if (db.eof())
                break;
            limit += 4*2+255+127*3;
        } while(notFound);
        db.close();
    }
    
    db.close();
}

void db_test_first::remove_test(const Test& test) {
    // replace
    std::ifstream db_tmp(m_Path, std::ios::binary);
    
    uint32_t id;
    char input_question[255];
    char input_answer[3][127];
    uint32_t right;
    
    int limit = 0;
    long long real_limit = 0;
    bool notFound = true;
    
    if (db_tmp) {
        do {
            db_tmp.seekg(limit, std::ios::beg);
            db_tmp.read((char *)&id, sizeof(uint32_t));
            if (id == test.id) {
                notFound = false;
            }
            if (db_tmp.eof())
                break;
            limit += 4*2+255+127*3;
        } while(notFound);
    }
    
    db_tmp.seekg(0, std::ios::end);
    real_limit = db_tmp.tellg();
    db_tmp.close();
    
    if (!notFound) {
        // rewrite
        std::ifstream db(m_Path, std::ios::binary);
        std::ofstream tmp(m_Path + ".tmp", std::ios::binary);
        
        limit = 0;
        db.seekg(limit, std::ios::beg);
        while (limit < real_limit) {
            db.read((char *)&id, sizeof(uint32_t));
            db.read(input_question, 255);
            for (size_t i = 0; i < 3; i++)
                db.read(input_answer[i], 127);
            db.read((char *)&right, sizeof(uint32_t));
            if (id == test.id) {
                limit += 4*2+255+127*3;
                continue;
            }
            tmp.write((char *)&id, sizeof(uint32_t));
            tmp.write(input_question, 255);
            for (size_t i = 0; i < 3; i++)
                tmp.write(input_answer[i], 127);
            tmp.write((char *)&right, sizeof(uint32_t));
            limit += 4*2+255+127*3;
        }
        
        db.close();
        tmp.close();
        
        remove(m_Path.c_str());
        rename((m_Path + ".tmp").c_str(), m_Path.c_str());
    }
}

void db_test_first::load_tests(std::vector<Test>& tests) {
    std::ifstream db(m_Path, std::ios::binary);
    db.seekg(0, std::ios::end);
    long long size = db.tellg() / (4*2+255+127*3);
    
    tests.clear();
    
    uint32_t id;
    char input_question[255];
    char input_answer[3][127];
    uint32_t right;
    
    db.seekg(0, std::ios::beg);
    
    for (int i = 0; i < size; i++) {
        Test tmp;
        db.read((char *)&id, sizeof(uint32_t));
        db.read(input_question, 255);
        for (size_t i = 0; i < 3; i++)
            db.read(input_answer[i], 127);
        db.read((char *)&right, sizeof(uint32_t));
        
        tmp.id = id;
        tmp.question = Security::Cipher::getUnChipher(input_question).c_str();
        for (size_t i = 0; i < 3; i++)
            tmp.answer[i] = Security::Cipher::getUnChipher(input_answer[i]).c_str();
        tmp.right = right;
        
        tests.push_back(tmp);
    }
    
    db.close();
}
