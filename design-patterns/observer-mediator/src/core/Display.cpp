#include "core/Display.hpp"

#include <string>

namespace
{
    const std::string kModuleName{"Display"};
}

Display::Display(Logger& logger) :
    _logger(logger) {}

void Display::setTemperature(int temperature)
{
    auto e = [this, temperature]
    {
        std::string message = "New Temperature is " + std::to_string(temperature);
        _logger.log(kModuleName, message);
    };
    addEvent(e);
}