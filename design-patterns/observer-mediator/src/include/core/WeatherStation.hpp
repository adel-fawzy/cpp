#ifndef WEATHERSTATION_HPP
#define WEATHERSTATION_HPP

#include <ActiveObject.hpp>
#include <functional>
#include <unordered_map>

class WeatherStation : public ActiveObject
{
public:
    using TemperatureCallback = std::function<void(int)>;
    using TemperatureCallbacks = std::unordered_map<ActiveObject::ID, TemperatureCallback>;
    WeatherStation() = default;
    ~WeatherStation() = default;
    void run();
    void subscribeToTemperature(ActiveObject::ID id, TemperatureCallback callback);
    void unsubscribeFromTemperature(ActiveObject::ID id);
private:
    TemperatureCallbacks _temperatureCallbacks;
};

#endif // WEATHERSTATION_HPP