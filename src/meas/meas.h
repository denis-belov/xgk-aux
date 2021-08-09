#include <cstdint>



namespace XGK::AUX::MEAS
{
  void getFramerate (void);
  void getAverageFrametime (void);
  void getTime (void);
  void getTime2 (void);
  void calculateFrametime (uint64_t* frame_time);
}
