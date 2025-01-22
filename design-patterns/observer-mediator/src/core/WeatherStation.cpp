#include "core/WeatherStation.hpp"

#include <list>
#include <algorithm>
#include <thread>

namespace
{
    const std::list<int> kTemperatureSensorReadings{32, 30, 33};
}

void WeatherStation::run()
{
    auto e = [this]
    {
        unsigned int counter{3};
        for(auto temperatureReading : kTemperatureSensorReadings)
        {
            for(auto callback : _temperatureCallbacks)
            {
                callback.second(temperatureReading);
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    };
    addEvent(e);
}

void WeatherStation::subscribeToTemperature(ActiveObject::ID id, TemperatureCallback callback)
{
    auto e = [this, id, callback]{
        _temperatureCallbacks[id] = callback;
    };
    addEvent(e);
}

void WeatherStation::unsubscribeFromTemperature(ActiveObject::ID id)
{
    auto e = [this, id]{
        auto it = _temperatureCallbacks.find(id);
        if(it != _temperatureCallbacks.end())
        {
            _temperatureCallbacks.erase(it);
        }
    };
    addEvent(e);
}