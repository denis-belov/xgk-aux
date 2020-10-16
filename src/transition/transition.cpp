#include "transition-stack/transition-stack.h"
#include "transition.h"

#include <iostream>

using std::cout;
using std::endl;

namespace XGK {

	void idle_function (const float) {};



	void Transition::cancel (void) {

		TransitionStack* stack = TransitionStack::array[stack_id];

		active = 0;

		stack->static_storage[stack->counter--] = stack->static_storage[--stack->length];
		stack->static_storage[stack->length] = nullptr;
	};

	void Transition::cancel2 (void) {

		if (active) {

			TransitionStack* stack = TransitionStack::array[stack_id];

			active = 0;

			stack->static_storage[index] = stack->static_storage[--stack->length];
			stack->static_storage[stack->length] = nullptr;
		}
	};

	void Transition::start (

		uint64_t _duration,
		void (* _process_callback) (const float),
		void (* _end_callback) (const float)
	) {

		if (active) {

			end_callback(interpolation);
		}
		else {

			active = 1;

			TransitionStack::push_s(this);
		}

		interpolation = 0.0f;
		duration = _duration;
		process_callback = _process_callback;
		end_callback = _end_callback;
		time_gone = 0;
	};

	void Transition::start2 (

		uint64_t _duration,
		void (* _process_callback) (const float)
	) {

		if (active) {

			end_callback(interpolation);
		}
		else {

			active = 1;

			TransitionStack::push_s(this);
		}

		interpolation = 0.0f;
		duration = _duration;
		process_callback = _process_callback;
		end_callback = idle_function;
		time_gone = 0;
	};

	void Transition::update (const uint64_t frame_time) {

		// cout << frame_time << endl;

		interpolation = ((float) time_gone) / ((float) duration);

		if (time_gone >= duration) {

			cancel();

			end_callback(interpolation);
		}
		else {

			time_gone += frame_time;

			process_callback(interpolation);
		}
	};
};
