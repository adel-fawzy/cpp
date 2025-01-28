#ifndef ADEL_ACTIVEOBJECT_HPP
#define ADEL_ACTIVEOBJECT_HPP

#include <functional>
#include <memory>

namespace adel
{
	class ActiveObject
	{
	public:
		using ID = int;

		ActiveObject();
		virtual ~ActiveObject();

		// Delete copy and move constructors/assignment operators
		ActiveObject(ActiveObject const& obj) = delete;
		ActiveObject(ActiveObject const&& obj) = delete;
		ActiveObject& operator=(ActiveObject& obj) = delete;
		ActiveObject& operator=(ActiveObject&& obj) = delete;

	protected:
		void addEvent(std::function<void()> eventHandler);
		ID getID() const;

	private:
		void run();
		class Impl;
		std::unique_ptr<Impl> _impl;
	};
}

#endif // ADEL_ACTIVEOBJECT_HPP