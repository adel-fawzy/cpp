#ifndef APP_HPP
#define APP_HPP

#include <adel/ActiveObject.hpp>
#include "core/WeatherStation.hpp"
#include "core/Mobile.hpp"
#include "core/Display.hpp"

class App : public adel::ActiveObject
{
public:
    App();
    ~App();
    void run();
private:
    // Composition
    WeatherStation _weatherStation;
    Mobile _mobile;
    Display _display;
};

#endif // APP_HPP