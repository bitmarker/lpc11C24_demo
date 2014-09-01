#include "chip.h"

/* System oscillator rate and clock rate on the CLKIN pin */
const uint32_t OscRateIn = 12000000;
const uint32_t ExtRateIn = 0;

int main()
{
  SystemCoreClockUpdate();
  
  
  
  return 0;
}
