#ifndef OBSERVER_MEDIATOR_APP_HPP
#define OBSERVER_MEDIATOR_APP_HPP

#include <adel/ActiveObject.hpp>
#include "core/WeatherStation.hpp"
#include "core/Mobile.hpp"
#include "core/Display.hpp"

namespace observer_mediator
{
    /**
     * @class App.
     * 
     * @brief Main class for observer-mediator.
     * 
     * The class acts as a mediator class between the WeatherStation, Mobile and Display.
     * The class is an ActiveObject. Therefore, it handles its events using an event queue.
     */
    class App : public adel::ActiveObject
    {
    public:
    
        /**
         * @brief Constructs an App.
         */
        App();

        /**
         * @brief Destroys an app.
         */
        ~App();

        /**
         * @brief Runs the application logic.
         */
        void run();
    
    private:

        /**
         * @brief WeatherStation object.
         * 
         * Simulates reading from a temperature sensor and outputs the result.
         */
        core::WeatherStation _weatherStation;

        /**
         * @brief Mobile object.
         * 
         * Logs temperature data on the mobile.
         */
        core::Mobile _mobile;

        /**
         * @brief Display object.
         * 
         * Logs temperature data on the display.
         */
        core::Display _display;
    }; // class App
} // namespace observer_mediator

#endif // OBSERVER_MEDIATOR_APP_HPP