#ifndef ADEL_EVENTQUEUE_HPP
#define ADEL_EVENTQUEUE_HPP

#include <queue>
#include <mutex>
#include <condition_variable>

namespace adel::internal
{
    /**
     * @class EventQueue
     * 
     * @brief A thread-safe queue for pushing and popping events.
     */
    template <typename EVENT>
    class EventQueue
    {
    public:

        using QueueOfEvents = std::queue<EVENT>;

        /**
         * @brief Constructs an EventQueue.
         */
        EventQueue() = default;

        /**
         * @brief Destroys an EventQueue.
         */
        ~EventQueue() = default;

        /**
         * @brief Pushes an event to the event queue.
         * 
         * @param event Event.
         */
        void pushEvent(EVENT newEvent)
        {
            std::lock_guard<std::mutex> lock(_mutex); // Wait for access to the queue
            _queue.push(newEvent);
            _condition.notify_one();
        }

        /**
         * @brief Pops an event from the event queue and returns it.
         * 
         * @return Event.
         */
        EVENT popEvent()
        {
            std::unique_lock<std::mutex> lock(_mutex);
            if(_queue.empty())
            {
                // Sleep until another thread notifies that a new event is pushed
                _condition.wait(lock, [this]{ return !_queue.empty(); });
            }

            // Return the first event in the queue and pop it
            EVENT event = std::move(_queue.front());
            _queue.pop();
            return event;
        }

    private:

        /**
         * @brief Queue of events.
         */
        QueueOfEvents _queue;

        /**
         * @brief Mutex for protecting access to the event queue.
         */
        std::mutex _mutex;

        /**
         * @brief Condition variable for signaling when new events are available.
         */
        std::condition_variable _condition;
    }; // class EventQueue
} // namespace adel::internal

#endif // ADEL_EVENTQUEUE_HPP