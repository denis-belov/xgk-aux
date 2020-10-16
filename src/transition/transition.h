#include <cstdint>

namespace XGK {

	struct TransitionStack;

	// alignas
	struct Transition {

		// revise types
		uint8_t active;
		uint64_t time_gone;
		float interpolation;
		uint64_t duration;
		uint64_t index;
		uint64_t stack_id;

		void (* process_callback) (const float);
		void (* end_callback) (const float);



		void cancel (void); // only cancels within stack execution, not for using manually
		void cancel2 (void);
		void start (uint64_t, void (*) (const float), void (*) (const float));
		void start2 (uint64_t, void (*) (const float));
		void update (const uint64_t);
	};
};
