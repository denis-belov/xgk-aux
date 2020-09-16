#include <cmath>
#include <cstdint>
// #include <Windows.h>
#include <chrono>
// #include "time.h"

// #include <iostream>

// uint64_t qwe = 0.0f;


// TODO frame_time int for better performance

// make cross-platform
// inline float getWallTime (void) {

//   LARGE_INTEGER time;
//   LARGE_INTEGER freq;

//   if (!QueryPerformanceFrequency(&freq)) {

//     return 0;
//   }

//   if (!QueryPerformanceCounter(&time)) {

//     return 0;
//   }

//   return (float) time.QuadPart / freq.QuadPart;
// };



namespace XGK {

  void idle_function (const float, void*) {};



  namespace TIME {

    void init (Time* time, const uint64_t stack_max_size) {

      time->last_frame_time = std::chrono::high_resolution_clock::now();
      time->frame_time = 0.0f;
      time->stack_length = 0;
      time->stack_counter = 0;

      time->stack_VECTOR.resize(stack_max_size);
      time->stack_RANGE = time->stack_VECTOR.data();
    };



    // only cancels within stack execution, not for using manually
    void cancelTransition (Time* time, Transition* transition) {

      // if (transition->active) {

        transition->active = 0;

        time->stack_RANGE[time->stack_counter--] = time->stack_RANGE[--time->stack_length];
        time->stack_RANGE[time->stack_length] = nullptr;
      // }

      // printf("\33[2J");
      // std::cout << "update transition count: " << qwe << std::endl;
      // qwe = 0;
    };



    void cancelTransition2 (Time* time, Transition* transition) {

      if (transition->active) {

        transition->active = 0;

        time->stack_RANGE[transition->stack_index] = time->stack_RANGE[--time->stack_length];
        time->stack_RANGE[time->stack_length] = nullptr;
      }
    };



    void setTransition (
      Time* time,
      Transition* transition,
      const float duration,
      void (* process_callback) (const float, void*),
      void (* end_callback) (const float, void*)
    ) {

      cancelTransition2(time, transition);

      transition->interpolation = 0.0f;
      transition->duration = duration;
      transition->process_callback = process_callback;
      transition->end_callback = end_callback;
      transition->time_gone = 0.0f;
      transition->active = 1;
      transition->stack_index = time->stack_length;

      time->stack_RANGE[time->stack_length++] = transition;
    };



    void setTransition2 (

      Time* time,
      Transition* transition,
      const float duration,
      void (* process_callback) (const float, void*)
    ) {

      cancelTransition2(time, transition);

      transition->interpolation = 0.0f;
      transition->duration = duration;
      transition->process_callback = process_callback;
      transition->end_callback = idle_function;
      transition->time_gone = 0.0f;
      transition->active = 1;
      transition->stack_index = time->stack_length;

      time->stack_RANGE[time->stack_length++] = transition;
    };



    void updateTransition (Time* time, Transition* transition) {

      transition->interpolation = transition->time_gone / transition->duration;

      // qwe++;

      if (transition->interpolation >= 1.0) {

        cancelTransition(time, transition);

        transition->end_callback(transition->interpolation, transition->additional);
      }
      else {

        transition->time_gone += time->frame_time;

        transition->process_callback(transition->interpolation, transition->additional);
      }
    };



    void updateTransitions (Time* time) {

      for (time->stack_counter = 0; time->stack_RANGE[time->stack_counter]; time->stack_counter++) {

        updateTransition(time, time->stack_RANGE[time->stack_counter]);
      }
    };



    void getFrameTime (Time* time) {

      float program_time = std::chrono::high_resolution_clock::now();

      // time->frame_time = program_time - time->last_frame_time;
      time->frame_time = std::chrono::duration_cast<std::chrono::microseconds>(program_time - time->last_frame_time).count();
      time->last_frame_time = program_time;
    };
  };
};
