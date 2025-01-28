#ifndef OBSERVER_MEDIATOR_MOBILE_HPP
#define OBSERVER_MEDIATOR_MOBILE_HPP

#include <adel/ActiveObject.hpp>
#include "utils/Logger.hpp"

namespace observer_mediator::core
{
    /**
     * @class Mobile
     * 
     * @brief Logs temperature data on the mobie.
     */
    class Mobile : public adel::ActiveObject
    {
    public:

        /**
         * @brief Constructs a Mobile.
         */
        Mobile(utils::Logger& logger);

        /**
         * @brief Destroys a Mobile.
         */
        ~Mobile() = default;

        /**
         * @brief Sets the temperature.
         */
        void setTemperature(int temperature);

    private:

        /**
         * @brief Logger object.
         */
        utils::Logger& _logger;
    }; // class Mobile
} // namespace observer_mediator::core

#endif // OBSERVER_MEDIATOR_MOBILE_HPP