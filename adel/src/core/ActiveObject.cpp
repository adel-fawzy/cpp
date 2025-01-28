#include "ActiveObject.hpp"

#include "core/EventQueue.hpp"
#include <thread>
#include <atomic>

namespace adel
{
    /**
     * @class ActiveObject::Impl
     * 
     * @brief Private implementation of ActiveObject.
     * 
     * This class, upon contruction, runs a thread which handles a queue of events. The destructor when called, pushes an event to the queue
     * so that the thread stops execution. Upon pushing an event to the queue, the destructor joins (waits) the thread.
     */
    class ActiveObject::Impl : private internal::EventQueue<Event>
    {
    public:

        /**
         * @brief ActiveObject::Impl default constructor.
         * 
         * Starts a new thread which executes events from the event queue.
         */
        Impl() :
            _thread(&Impl::run, this),
            _stop(false),
            _id(++_globalId) {}

        /**
         * @brief ActiveObject::Impl destructor.
         * 
         * Pushes a new event to the queue so that the thread exits. Joins (waits for) the thread after pushing the new event.
         */
        ~Impl()
        {
            addEvent([this]{
                _stop.store(true);
            });
            _thread.join();
        }

        /**
         * @brief Adds an event to the event queue to be handled.
         * 
         * @param eventHandler The function to be executed to handle the event.
         */
        void addEvent(std::function<void()> eventHandler)
        {
            pushEvent(eventHandler);
        }

        /**
         * @brief Returns the unique ID of the ActiveObject.
         * 
         * @return Unique ID of the ActiveObject.
         */
        ID getID() const
        {
            return _id;
        }

    private:

        /**
         * @brief Runs the event loop
         * 
         * This method is called in a new thread which executes the events in the event queue
         */
        void run()
        {
            while(!_stop.load())
            {
                popEvent()(); // Pop the event and execute it. Sleeps until a new event comes.
            }
        }

        /**
         * @brief Manages the thread that runs the event loop.
         */
        std::thread _thread;

        /**
         * @brief Signals that the event loop shall stop execution.
         */
        std::atomic<bool> _stop;

        /**
         * @brief Static atomic variable that generates unique IDs for ActiveObjects.
         */
        static std::atomic<ID> _globalId;

        /**
         * @brief The unique ID of the ActiveObject.
         */
        ID _id;
    };

    std::atomic<ActiveObject::ID> ActiveObject::Impl::_globalId{-1};

    /**
     * @brief Constrcuts an ActiveObject.
     */
    ActiveObject::ActiveObject() :
        _impl(std::make_unique<Impl>()) {}

    /**
     * @brief Destroys an ActiveObject.
     */
    ActiveObject::~ActiveObject() = default;

    /**
     * @brief Adds an event handler to the event queue of the ActiveObject.
     * 
     * Calls the equivalent function in the Impl class (PIMPL idiom).
     * 
     * @param eventHandler The function to be executed to handle the event.
     */
    void ActiveObject::addEvent(std::function<void()> eventHandler)
    {
        _impl->addEvent(std::move(eventHandler)); // Use std::move for efficiency
    }

    /**
     * @brief Returns the ID of the ActiveObject.
     * 
     * Calls the equivalent function in the Impl class (PIMPL idiom).
     * 
     * @return The unique ID of the ActiveObject.
     */
    ActiveObject::ID ActiveObject::getID() const
    {
        return _impl->getID();
    }
} // namespace adel