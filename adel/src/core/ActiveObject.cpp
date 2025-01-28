#include "ActiveObject.hpp"

#include "core/EventQueue.hpp"
#include <thread>
#include <atomic>

namespace adel
{
    class ActiveObject::Impl : private internal::EventQueue
    {
    public:
        Impl() :
            _thread(&Impl::run, this),
            _stop(false),
            _id(++_globalId) {}

        ~Impl()
        {
            addEvent([this]{
                _stop.store(true);
            });
            _thread.join();
        }

        void addEvent(std::function<void()> eventHandler)
        {
            EventQueue::pushEvent(eventHandler);
        }

        ActiveObject::ID getID() const
        {
            return _id;
        }

    private:
        void run()
        {
            while(!_stop.load())
            {
                EventQueue::popEvent()(); // Pop the event and execute it
            }
        }
        std::thread _thread;
        std::atomic<bool> _stop;
        static std::atomic<ActiveObject::ID> _globalId;
        ActiveObject::ID _id;
    };

    std::atomic<ActiveObject::ID> ActiveObject::Impl::_globalId{-1};

    ActiveObject::ActiveObject() :
        _impl(std::make_unique<Impl>()) {}

    ActiveObject::~ActiveObject() = default;

    void ActiveObject::addEvent(std::function<void()> eventHandler)
    {
        _impl->addEvent(std::move(eventHandler)); // Use std::move for efficiency
    }

    ActiveObject::ID ActiveObject::getID() const
    {
        return _impl->getID();
    }
} // namespace adel