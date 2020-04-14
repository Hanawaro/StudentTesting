#include "Hash.hpp"

#include <openssl/md5.h>

std::string Security::Hash::get_hash(std::string text) {
    unsigned char md5digest[MD5_DIGEST_LENGTH];
    MD5((unsigned char *)text.c_str(), text.size(), md5digest);
    
    return std::string((char *)md5digest);
}

std::string Security::Hash::get_hash_with_sult(std::string text) {
    std::string hash = get_hash(text);
    for (int i = 0; i < hash.size()/3; i++)
        hash += hash[i];
    
    return get_hash(hash);
}
