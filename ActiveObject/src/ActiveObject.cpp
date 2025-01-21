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
    ID getID() const;

private:
    void run();
    std::thread _thread;
	std::atomic<bool> _stop;
    static ID _globalId;
	ID _id;
};

unsigned int ActiveObject::Impl::_globalId{};

ActiveObject::Impl::Impl() :
    _thread(&Impl::run, this),
    _stop(false),
    _id(_globalId++) {}

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

ActiveObject::ID ActiveObject::Impl::getID() const
{
    return _id;
}

// ActiveObject
ActiveObject::ActiveObject() :
    _impl(std::make_unique<ActiveObject::Impl>()) {}

ActiveObject::~ActiveObject() = default;

void ActiveObject::addEvent(std::function<void()> eventHandler)
{
    _impl->addEvent(std::move(eventHandler)); // Use std::move for efficiency
}

ActiveObject::ID ActiveObject::getID() const
{
    return _impl->getID();
}