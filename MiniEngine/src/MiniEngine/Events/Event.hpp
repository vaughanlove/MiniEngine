#pragma once

#include "MiniEngine/Core.hpp"

#include <string>
#include <functional>

namespace MiniEngine {
	/**
	 * All of the different types of events that we expect. Can be expanded as needed.
	 * This event abstraction is to reduce needing a massive HandleKeyInput() callback where
	 * all the different types of events need to checked in a switch or something, and then passed into 
	 * seperate logic to deal with how the render/window/model/etc needs to react.
	 */
	enum class EventType 
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus,
		WindowMoved, AppTick, AppUpdate, AppRender, KeyPressed, 
		KeyReleased, MouseButtonPressed, MouseButtonReleased, MouseMoved,
		MouseScrolled
	};

	/**
	 * Events can overlap and belong to multiple different categories. 
	 * 10001 Means there was a EventCategoryApplication and EventCategoryMouseButton.
	 */ 

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication	 = BIT(0),
		EventCategoryInput			 = BIT(1),
		EventCategoryKeyboard 		 = BIT(2),
		EventCategoryMouse			 = BIT(3),
		EventCategoryMouseButton	 = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
							virtual EventType GetEventType() const override { return GetStaticType(); }\
							virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class MINIENGINE_API Event 
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	protected:
		bool m_Handled = false;
	};

	/**
	 *
	 */
	class EventDispatcher 
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public: 
		EventDispatcher(Event& event)
			: m_Event(event)
		{

		}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType()) {
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			};
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}