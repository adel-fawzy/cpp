#include <EventQueue.hpp>

void EventQueue::pushEvent(std::function<void()>& newEvent)
{
    std::lock_guard<std::mutex> lock(_mutex); // Wait for access to the queue
    _queue.push(newEvent);
    _condition.notify_one();
}

std::function<void()> EventQueue::popEvent()
{
    std::unique_lock<std::mutex> lock(_mutex);
    if(_queue.empty())
    {
            // Sleep until another thread notifies that a new event is pushed
            _condition.wait(lock, [this]{ return !_queue.empty(); });
    }

    // Return the first event in the queue and pop it
    std::function<void()> event = std::move(_queue.front());
    _queue.pop();
    return event;
}