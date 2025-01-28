#ifndef OBSERVER_MEDIATOR_DISPLAY_HPP
#define OBSERVER_MEDIATOR_DISPLAY_HPP

#include <adel/ActiveObject.hpp>
#include "utils/Logger.hpp"

namespace observer_mediator::core
{
    /**
     * @class Display.
     * 
     * @brief Logs temperature data on the display.
     */
    class Display : public adel::ActiveObject
    {
    public:

        /**
         * @brief Constructs a Display object.
         */
        Display(utils::Logger& logger);

        /**
         * @brief Destroys a Display object.
         */
        ~Display() = default;

        /**
         * @brief Sets the temperature.
         */
        void setTemperature(int temperature);

    private:

        /**
         * @brief Logger object.
         */
        utils::Logger& _logger;
    }; // class Display
} // namespace observer_mediator::core

#endif // OBSERVER_MEDIATOR_DISPLAY_HPP