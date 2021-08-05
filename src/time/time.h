#include <cstdint>
#include <vector>



// TODO frame_time int for better performance

namespace XGK {

  // pack ?
  struct Transition {

    uint8_t active;
    float time_gone;
    float interpolation;
    float duration;
    uint64_t stack_index;
    void* additional;

    void (* process_callback) (const float, void*);
    void (* end_callback) (const float, void*);
  };



  // pack ?
  struct Time {

    std::vector<Transition*> stack_VECTOR;
    Transition** stack_RANGE;

    float last_frame_time;
    float frame_time;
    uint64_t stack_length;
    uint64_t stack_counter;

    Transition** stack;
  };



  #ifndef XGK_NO_INLINE

    namespace TIME {

      // inline float getWallTime (void);
      inline void init (Time*, const uint64_t);
      inline void cancelTransition (Time*, Transition*);
      inline void cancelTransition2 (Time*, Transition*);
      inline void setTransition (Time*, Transition*, const float, void (*) (const float, void*), void (*) (const float, void*));
      inline void setTransition2 (Time*, Transition*, const float, void (*) (const float, void*));
      inline void updateTransition (Time*, Transition*);
      inline void updateTransitions (Time*);
      inline void getFrameTime (Time*);
    };
  #endif
}
