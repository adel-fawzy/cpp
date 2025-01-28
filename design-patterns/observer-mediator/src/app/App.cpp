#include "app/App.hpp"
#include "utils/Logger.hpp"
#include <memory>

namespace observer_mediator
{
    App::App() :
        _weatherStation(),
        _mobile(utils::Logger::getInstance()),
        _display(utils::Logger::getInstance())
    {
        // Connect inputs and outputs
        _weatherStation.subscribeToTemperature(getID(), [this](int temperature)
        {
            _mobile.setTemperature(temperature);
            _display.setTemperature(temperature);
        });
    }

    App::~App()
    {
        // Disconnect inputs and outputs
        _weatherStation.unsubscribeFromTemperature(getID());
    }

    void App::run()
    {
        auto e = [this]
        {
            _weatherStation.run();
        };
        addEvent(e);
    }
} // namespace observer_mediator