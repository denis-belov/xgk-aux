#include <transition/transition.h>
#include "transition-stack.h"

#include <iostream>

using std::cout;
using std::endl;

namespace XGK {

	uint64_t TransitionStack::index = 0;
	uint64_t TransitionStack::size = 0;
	std::vector<TransitionStack*> TransitionStack::vector;
	TransitionStack** TransitionStack::array = nullptr;

	// Pushes transition into stacks sequentually. Useful with multithreading.
	void TransitionStack::push_s (Transition* transition) {

		if (TransitionStack::index < TransitionStack::size - 1) {

			++TransitionStack::index;
		}
		else {

			TransitionStack::index = 0;
		}

		TransitionStack::array[TransitionStack::index]->push(transition);
	};



	TransitionStack::TransitionStack (const uint64_t size) {

		id = TransitionStack::size++;

		cout << id << endl;

		length = 0;
		counter = 0;
		frame_time = 0;

		program_time = std::chrono::system_clock::now();
		last_program_time = std::chrono::system_clock::now();

		dynamic_storage.resize(size);
		static_storage = dynamic_storage.data();

		TransitionStack::vector.push_back(this);
		TransitionStack::array = TransitionStack::vector.data();
	};


	void TransitionStack::update (void) {

		for (counter = 0; static_storage[counter]; counter++) {

			static_storage[counter]->update(frame_time);
		}
	};

	void TransitionStack::push (Transition* transition) {

		transition->index = length;
		transition->stack_id = id;

		static_storage[length] = transition;

		++length;
	};

	void TransitionStack::calculateFrametime (void) {

		program_time = std::chrono::system_clock::now();
		frame_time = std::chrono::duration_cast<std::chrono::nanoseconds>(program_time - last_program_time).count();
		last_program_time = program_time;
	};
};
