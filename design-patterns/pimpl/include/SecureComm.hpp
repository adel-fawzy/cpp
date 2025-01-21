#ifndef SECURECOMM_HPP
#define SECURECOMM_HPP

// Notice here that we did not force the client to include any files that it does not use (except only the memory header file)
// If we did not use the pimpl design patter, we would have been including here the Encryptor header file, which is a private class to the library
#include <memory>
#include <string> // Expected to be included by the client since they must pass an std::string to the interface function 'sendMessage'

class SecureComm
{
public:
    SecureComm();
    ~SecureComm();
    void sendMessage(std::string message);
private:
    class Impl;
    std::unique_ptr<Impl> _impl;
};

#endif // SecureComm