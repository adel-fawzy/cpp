#ifndef WEATHERSTATION_HPP
#define WEATHERSTATION_HPP

#include <adel/ActiveObject.hpp>
#include <functional>
#include <unordered_map>

class WeatherStation : public adel::ActiveObject
{
public:
    using TemperatureCallback = std::function<void(int)>;
    using TemperatureCallbacks = std::unordered_map<ID, TemperatureCallback>;
    WeatherStation() = default;
    ~WeatherStation() = default;
    void run();
    void subscribeToTemperature(ID id, TemperatureCallback callback);
    void unsubscribeFromTemperature(ID id);
private:
    TemperatureCallbacks _temperatureCallbacks;
};

#endif // WEATHERSTATION_HPP