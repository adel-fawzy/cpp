#ifndef ENCRYPTOR_HPP
#define ENCRYPTOR_HPP

#include <string>

class Encryptor
{
public:
    Encryptor() = default;
    ~Encryptor() = default;
    std::string encrypt(std::string message);
};

#endif // ENCRYPTOR_HPP