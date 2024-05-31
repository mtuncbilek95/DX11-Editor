#pragma once

#include <Runtime/Core/Core.h>
#include <functional>

namespace Editor
{
	// Lambda controller
	template<typename _Type>
	using EDelegate = std::function<void(const _Type&)>;

	/**
	 * @class EventBase
	 * @brief Base class for every event driven structure
	 */
	template<typename _Type>
	class EventBase
	{
		using TEventType = _Type;
	public:
		EventBase() = default;
		EventBase(TEventType Type, const String& EventName) : mEventType(Type), mEventName(EventName) {}
		virtual ~EventBase() = default;

		inline const TEventType& GetType() const noexcept { return mEventType; }
		inline const String& GetEventName() const noexcept { return mEventName; }

		template<typename _AnotherType>
		_AnotherType ToType() { return static_cast<_AnotherType>(mEventType); }
	private:
		TEventType mEventType;
		String mEventName;
	};

	template<typename _Type>
	class EventDispatcher final
	{
		using TEventType = _Type;
	public:
		EventDispatcher() = default;
		~EventDispatcher() = default;

		void AddListener(const EDelegate<TEventType>& NewEvent) { mEvents.push_back(NewEvent); }
		void Dispatch(const TEventType& Type)
		{
			for (const auto& event : mEvents)
				event(Type);
		}

	private:
		DArray<EDelegate<TEventType>> mEvents;
	};
}

