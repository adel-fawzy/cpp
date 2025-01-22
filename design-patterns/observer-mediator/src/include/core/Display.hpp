#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <ActiveObject.hpp>
#include <utils/Logger.hpp>

class Display : public ActiveObject
{
public:
    Display(Logger& logger);
    ~Display() = default;
    void setTemperature(int temperature);
private:
    Logger& _logger;
};

#endif // DISPLAY_HPP