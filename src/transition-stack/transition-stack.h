#include <cstdint>
#include <vector>
#include <chrono>

namespace XGK {

	struct Transition;

	// alignas
	struct TransitionStack {

		static uint64_t index;
		static uint64_t size;
		static std::vector<TransitionStack*> vector;
		static TransitionStack** array;

		static void push_s (Transition*);



		uint64_t id;
		uint64_t length;
		uint64_t counter;
		uint64_t frame_time;

		std::chrono::time_point<std::chrono::system_clock> program_time;
		std::chrono::time_point<std::chrono::system_clock> last_program_time;

		std::vector<Transition*> dynamic_storage;
		Transition** static_storage;

		TransitionStack (const uint64_t);
		~TransitionStack (void);
		void update (void);
		void push (Transition*);
		void calculateFrametime (void);
	};
}
