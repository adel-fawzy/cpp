#ifndef EVENTQUEUE_HPP
#define EVENTQUEUE_HPP

#include <functional>
#include <queue>
#include <mutex>
#include <condition_variable>

class EventQueue
{
public:
    EventQueue() = default;

    ~EventQueue() = default;
       
    void pushEvent(std::function<void()>& newEvent);

    std::function<void()> popEvent();

private:
    std::queue<std::function<void()>> _queue;
    std::mutex _mutex;
    std::condition_variable _condition;
};

#endif