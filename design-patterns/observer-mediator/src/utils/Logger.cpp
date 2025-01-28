#include "utils/Logger.hpp"

#include <iostream>

std::mutex Logger::_mutex;

Logger& Logger::getInstance()
{
    std::lock_guard<std::mutex> lock(_mutex); // Thread-safe initialization
    static Logger _instance;
    return _instance; // Instance created on first call
}

void Logger::log(std::string const& moduleName, std::string const& message)
{
    auto e = [this, moduleName, message]
    {
        std::cout << "[" << moduleName << "] " << message << std::endl;
    };
    addEvent(e);
}