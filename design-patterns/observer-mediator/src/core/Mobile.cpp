#include "core/Mobile.hpp"

#include <string>

namespace
{
    const std::string kModuleName{"Mobile"};
}

namespace observer_mediator::core
{
    Mobile::Mobile(utils::Logger& logger) :
        _logger(logger) {}

    void Mobile::setTemperature(int temperature)
    {
        auto e = [this, temperature]
        {
            std::string message = "New Temperature is " + std::to_string(temperature);
            _logger.log(kModuleName, message);
        };
        addEvent(e);
    }
} // namespace observer_mediator