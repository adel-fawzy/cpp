#ifndef MOBILE_HPP
#define MOBILE_HPP

#include <adel/ActiveObject.hpp>
#include <utils/Logger.hpp>

class Mobile : public adel::ActiveObject
{
public:
    Mobile(Logger& logger);
    ~Mobile() = default;
    void setTemperature(int temperature);
private:
    Logger& _logger;
};

#endif // MOBILE_HPP