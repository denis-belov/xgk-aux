#include <iostream>

#include "transition-stack/transition-stack.h"
#include "transition.h"



using std::cout;
using std::endl;



using callback_t = void (*) (const float&);



namespace XGK
{
	void idle_function (const float&) {}



	void Transition::cancel (void)
	{
		TransitionStack* stack { TransitionStack::array[stack_id] };

		active = 0;

		stack->static_storage[stack->counter--] = stack->static_storage[--stack->length];
		stack->static_storage[stack->length] = nullptr;
	}

	void Transition::cancel2 (void)
	{
		if (active)
		{
			TransitionStack* stack { TransitionStack::array[stack_id] };

			active = 0;

			stack->static_storage[index] = stack->static_storage[--stack->length];
			stack->static_storage[stack->length] = nullptr;
		}
	}

	void Transition::start
	(
		const size_t& _duration,
		callback_t _process_callback,
		callback_t _end_callback
	)
	{
		if (active)
		{
			end_callback(interpolation);
		}
		else
		{
			active = 1;

			TransitionStack::push_s(this);
		}

		interpolation = 0.0f;
		duration = _duration;
		process_callback = _process_callback;
		end_callback = _end_callback;
		time_gone = 0;
	}

	void Transition::start2
	(
		const size_t& _duration,
		callback_t _process_callback
	)
	{
		if (!active)
		{
			active = 1;

			TransitionStack::push_s(this);
		}

		interpolation = 0.0f;
		duration = _duration;
		process_callback = _process_callback;
		end_callback = idle_function;
		time_gone = 0;
	}

	void Transition::update (const size_t& frame_time)
	{
		time_gone += frame_time;

		interpolation = ((float) time_gone) / ((float) duration);

		process_callback(interpolation);

		if (time_gone >= duration)
		{
			cancel();
		}

		// if (time_gone >= duration) {

		// 	cancel();

		// 	end_callback(interpolation);
		// }
		// else {

		// 	time_gone += frame_time;

		// 	process_callback(interpolation);
		// }
	}
}
