#include <ActiveObject.hpp>

#include <EventQueue.hpp>
#include <thread>
#include <atomic>

class ActiveObject::Impl : private EventQueue
{
public:

    Impl();
	~Impl();
    void addEvent(std::function<void()> eventHandler);

private:
    void run();
    std::thread _thread;
	std::atomic<bool> _stop;
};

ActiveObject::Impl::Impl() :
    _thread(&Impl::run, this),
    _stop(false) {}

ActiveObject::Impl::~Impl()
{
    addEvent([this]{
        _stop.store(true);
    });
    _thread.join();
}

void ActiveObject::Impl::run()
{
    while(!_stop.load())
    {
        EventQueue::popEvent()(); // Pop the event and execute it
    }
}

void ActiveObject::Impl::addEvent(std::function<void()> eventHandler)
{
    EventQueue::pushEvent(eventHandler);
}

// ActiveObject
unsigned int ActiveObject::_globalId{};

ActiveObject::ActiveObject() :
    _impl(std::make_unique<ActiveObject::Impl>()),
    _id(_globalId++) {}

ActiveObject::~ActiveObject() = default;

void ActiveObject::addEvent(std::function<void()> eventHandler)
{
    _impl->addEvent(std::move(eventHandler)); // Use std::move for efficiency
}