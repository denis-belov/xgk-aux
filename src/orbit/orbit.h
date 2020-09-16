// do the same for gcc, emscripten

#if _WIN32 || _WIN64
  #if _WIN64
    #define MEM_ADDR_LENGTH 8
  #else
    #define MEM_ADDR_LENGTH 4
  #endif
#endif



#include <cstdint>



namespace XGK {

  struct Object;
  struct Time;
  struct Transition;



  // pack ?
  struct Orbit {

    alignas(16) float view_mat[16];

    alignas(16) float proj_mat[16];

    alignas(MEM_ADDR_LENGTH) Object* object;

    alignas(MEM_ADDR_LENGTH) Transition* transition;

    alignas(4) float speed_x;

    alignas(4) float speed_y;

    alignas(16) float prev_quat[4];
  };



  #ifndef XGK_NO_INLINE

    namespace ORBIT {

      inline void init (Orbit*, Object*, Transition*);
      inline void rotate (Orbit*);
      // inline void test (Orbit*, const float);
      inline void move (Orbit*, Time*, const float, const float, void (*) (const float, void*));
      inline void update (Orbit*);
    };
  #endif
};
