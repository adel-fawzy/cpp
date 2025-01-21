#include <SecureComm.hpp>
#include <Encryptor.hpp> // This is a private class to the library. It would have been exposed to the client if we did not use the pimpl design pattern
#include <iostream>

// SecureComm::Impl
class SecureComm::Impl : private Encryptor
{
public:
    Impl() = default;
    ~Impl() = default;
    void sendMessage(std::string& message);
};

void SecureComm::Impl::sendMessage(std::string& message)
{
    std::cout << Encryptor::encrypt(message) + " - signature" << std::endl;
}

// SecureComm
SecureComm::SecureComm() :
    _impl(std::make_unique<SecureComm::Impl>()) {}

SecureComm::~SecureComm() = default;

void SecureComm::sendMessage(std::string message)
{
    _impl->sendMessage(message);
}