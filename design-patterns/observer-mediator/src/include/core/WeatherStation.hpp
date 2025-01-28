#ifndef OBSERVER_MEDIATOR_WEATHERSTATION_HPP
#define OBSERVER_MEDIATOR_WEATHERSTATION_HPP

#include <adel/ActiveObject.hpp>
#include <functional>
#include <unordered_map>

namespace observer_mediator::core
{
    /**
     * @class WeatherStation.
     * 
     * @brief Simulates reading temperature data from a sensor and sends this data as its output.
     */
    class WeatherStation : public adel::ActiveObject
    {
    public:

        /**
         * @brief Type alias for TemperatureCallback.
         */
        using TemperatureCallback = std::function<void(int)>;

        /**
         * @brief Type alias for TemperatureCallbacks.
         */
        using TemperatureCallbacks = std::unordered_map<ID, TemperatureCallback>;

        /**
         * @brief Constructs a WeatherStation.
         */
        WeatherStation() = default;

        /**
         * @brief Destroys a WeatherStation.
         */
        ~WeatherStation() = default;

        /**
         * @brief Runs the simulated temperature readings and sends it as output.
         */
        void run();

        /**
         * @brief Records a subscriber to the temperature output.
         * 
         * @param id Unique ID of the ActiveObject subscriber
         * @param callback Callback of the observer. Called whenever there is a new temperature output.
         */
        void subscribeToTemperature(ID id, TemperatureCallback callback);

        /**
         * @brief Unsubsribers a temperature subscriber.
         * 
         * @param id Unique ID of the ActiveObject subscriber.
         */
        void unsubscribeFromTemperature(ID id);

    private:

        /**
         * @brief List of callbacks to call when there is a new temperature output.
         */
        TemperatureCallbacks _temperatureCallbacks;
    }; // class WeatherStation
} // namespace observer_mediator::core

#endif // OBSERVER_MEDIATOR_WEATHERSTATION_HPP