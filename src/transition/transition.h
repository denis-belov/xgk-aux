#include <cstdint>
#include <mutex>



namespace XGK
{
	struct TransitionStack;

	// alignas
	struct Transition
	{
		using callback_t = void (*) (const float&);

		// revise types
		std::mutex mutex;
		size_t time_gone;
		size_t duration;
		size_t index;
		size_t stack_id;
		float interpolation;
		uint8_t active;

		callback_t process_callback;
		callback_t end_callback;



		void cancel (void); // only cancels within stack execution, not for using manually
		void cancel2 (void);
		void start (const size_t&, void (*) (const float&), void (*) (const float&));
		void start2 (const size_t&, void (*) (const float&));
		void update (const size_t&);
	};
}
