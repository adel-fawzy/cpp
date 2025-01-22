#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <ActiveObject.hpp>
#include <mutex>

class Logger : public ActiveObject
{
private:
    Logger() = default; // Private constructor prevents direct instantiation
    ~Logger() = default; // Private destructor prevents deletion from outside

public:
    static Logger& getInstance();
    void log(std::string const moduleName, std::string const message);

    // Delete copy constructor and assignment operator to prevent copying
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

private:
    static std::mutex _mutex;
};

#endif // LOGGER_HPP