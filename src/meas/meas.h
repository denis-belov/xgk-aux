#include <cstdint>



namespace XGK::AUX::MEAS
{
  void printFramerate (void);
  void printAverageFrametime (void);
   // rename
  void getTime (void);
   // rename
  void getTime2 (void);
  void calculateFrametime (uint64_t* frame_time);
}
