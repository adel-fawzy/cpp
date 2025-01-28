/**
 * @file Logger.hpp
 * @brief This file contains the declaration of the Logger class, a singleton
 *        responsible for logging messages from different modules. It uses
 *        an ActiveObject for asynchronous logging.
 */

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <adel/ActiveObject.hpp>
#include <mutex>

/**
 * @brief The Logger class provides a thread-safe singleton for logging messages
 * from different modules within the application.
 */
class Logger : public adel::ActiveObject
{
public:

    /**
     * @brief Gets the singleton instance of the Logger.
     * 
     * This function returns a reference to the single instance of the Logger class.
     * The instance is created if it doesn't already exist. This method is thread-safe.
     *
     * @return A reference to the Logger singleton instance.
     */
    static Logger& getInstance();

    /**
     * @brief Logs a message with the specified module name.
     * 
     * This function makes a log in the format: [moduleName] message
     * 
     * Note: Due to the asynchronous nature of event handling, the log message 
     * might not appear immediately.
     *
     * @param moduleName The name of the module logging the message.
     * @param message The message to be logged.
     */
    void log(std::string const& moduleName, std::string const& message);

    /**
     * @brief Copy constructor (deleted).
     *
     * This copy constructor is deleted to prevent copying of the Logger object,
     * enforcing the singleton pattern. Copying a singleton would violate its
     * single-instance nature.
     */
    Logger(const Logger&) = delete;

    /**
     * @brief Copy assignment operator (deleted).
     *
     * This copy assignment operator is deleted to prevent copying of the Logger
     * object, enforcing the singleton pattern. Copying a singleton would violate
     * its single-instance nature.
     */
    Logger& operator=(const Logger&) = delete;

private:

    /**
     * @brief Default constructor.
     *
     * This constructor is private to prevent direct instantiation of the Logger class.
     * The Logger class is designed to be a singleton, and instances should be obtained
     * through the `getInstance()` method.
     */
    Logger() = default;

    /**
     * @brief Default destructor.
     * 
     * This destructor is private to prevent deletion of the Logger singleton from outside 
     * the class. The singleton's lifetime is managed internally.
     */
    ~Logger() = default;

    static std::mutex _mutex;  ///< Mutex for thread-safe access to the singleton instance.
};

#endif // LOGGER_HPP