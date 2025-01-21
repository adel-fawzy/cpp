#ifndef ACTIVEOBJECT_HPP
#define ACTIVEOBJECT_HPP

#include <functional>
#include <memory>

class ActiveObject
{
public:
	using ID = unsigned int;

    ActiveObject();
	virtual ~ActiveObject();

	// Delete copy and move constructors/assignment operators
	ActiveObject(ActiveObject const& obj) = delete;
	ActiveObject(ActiveObject const&& obj) = delete;
	ActiveObject& operator=(ActiveObject& obj) = delete;
	ActiveObject& operator=(ActiveObject&& obj) = delete;

protected:
	void addEvent(std::function<void()> eventHandler);
	ID _id;

private:
	void run();
	class Impl;
	std::unique_ptr<Impl> _impl;
	static ID _globalId;
};

#endif