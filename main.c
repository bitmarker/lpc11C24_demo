#include "chip.h"
#include "general.h"
#include "logging.h"
#include "mcp9808.h"
#include "uart.h"

/* System oscillator rate and clock rate on the CLKIN pin */
const uint32_t OscRateIn = 12000000;
const uint32_t ExtRateIn = 0;



int main()
{
  SystemCoreClockUpdate();
  
  Uart_Init();
  Logging_Init();
  MCP9808_Init();
  
  while(1)
  {
    Uart_Idle();
    Logging_Idle();
    MCP9808_Idle();
  }
}
