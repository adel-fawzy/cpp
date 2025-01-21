#include <SecureComm.hpp>

int main()
{
    SecureComm x{};
    x.sendMessage("Showcasing the PIMPL design pattern in C++");
    return 0;
}