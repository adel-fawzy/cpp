#include "core/App.hpp"
#include <memory>
#include <utils/Logger.hpp>

App::App() :
    _weatherStation(),
    _mobile(Logger::getInstance()),
    _display(Logger::getInstance())
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