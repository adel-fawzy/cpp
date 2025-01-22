#ifndef MOBILE_HPP
#define MOBILE_HPP

#include <ActiveObject.hpp>
#include <utils/Logger.hpp>

class Mobile : public ActiveObject
{
public:
    Mobile(Logger& logger);
    ~Mobile() = default;
    void setTemperature(int temperature);
private:
    Logger& _logger;
};

#endif // MOBILE_HPP