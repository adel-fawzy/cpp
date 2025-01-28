#ifndef ADEL_ACTIVEOBJECT_HPP
#define ADEL_ACTIVEOBJECT_HPP

#include <functional>
#include <memory>

namespace adel
{
	/**
	 * @class ActiveObject
	 * 
	 * @brief Provides event queuing. 
	 * 
	 * This class is meant to be inherited publicly. Dervied classes will gain event queuing functionality. meaning that their interface functions
	 * will be asynchronous, so that they don't block other threads.
	 */
	class ActiveObject
	{
	public:

		/**
		 * @brief Type alias for the ID of ActiveObject.
		 */
		using ID = int;

		/**
		 * @brief Type alias for the event.
		 */
		using Event = std::function<void()>;

		/**
		 * @brief Constructs an ActiveObject.
		 */
		ActiveObject();

		/**
		 * @brief Destroys an ActiveObject.
		 */
		virtual ~ActiveObject();

		// Delete copy and move constructors/assignment operators
		ActiveObject(ActiveObject const& obj) = delete;
		ActiveObject(ActiveObject const&& obj) = delete;
		ActiveObject& operator=(ActiveObject& obj) = delete;
		ActiveObject& operator=(ActiveObject&& obj) = delete;

	protected:

		/**
		 * @brief Adds an event to the event queue.
		 */
		void addEvent(std::function<void()> eventHandler);

		/**
		 * @brief Returns the ID of the ActiveObject.
		 * 
		 * @return The unique ID of the ActiveObject.
		 */
		ID getID() const;

	private:

		/**
		 * @class Impl
		 * 
		 * @brief Private implementation details of ActiveObject.
		 */
		class Impl;

		/**
		 * @brief Unique pointer to the private implemention of ActiveObject.
		 */
		std::unique_ptr<Impl> _impl;
	}; // class ActiveObject
} // namespace adel

#endif // ADEL_ACTIVEOBJECT_HPP