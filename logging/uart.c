/*
 * @brief  Uart
 *
 * @note
 * Copyright (C) 2013-2014 Leonid Lezner
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "uart.h"

/*****************************************************************************
* Private types/enumerations/variables
****************************************************************************/

static struct
{
  RINGBUFF_T txring;
  RINGBUFF_T rxring;
  uint8_t rxbuff[UART_RRB_SIZE];
  uint8_t txbuff[UART_SRB_SIZE];
} Uart_Data;

/*****************************************************************************
* Public types/enumerations/variables
****************************************************************************/

/*****************************************************************************
* Private functions
****************************************************************************/


/*****************************************************************************
* Public functions
****************************************************************************/

result_t Uart_Init(void)
{
  /* Change the pin function to UART */
  Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_6, (IOCON_FUNC1 | IOCON_MODE_INACT)); /* RXD */
  Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_7, (IOCON_FUNC1 | IOCON_MODE_INACT)); /* TXD */
  
  Chip_UART_Init(LPC_USART);
  
  RingBuffer_Init(&(Uart_Data.rxring), Uart_Data.rxbuff, 1, UART_RRB_SIZE);
  RingBuffer_Init(&(Uart_Data.txring), Uart_Data.txbuff, 1, UART_SRB_SIZE);
  
  Chip_UART_IntEnable(LPC_USART, (UART_IER_RBRINT | UART_IER_RLSINT));
  NVIC_SetPriority(UART0_IRQn, 1);
  NVIC_EnableIRQ(UART0_IRQn);
  
  return NO_ERROR;
}

result_t Uart_Setup(uint32_t baudrate)
{
  Chip_UART_SetBaud(LPC_USART, baudrate);
  Chip_UART_ConfigData(LPC_USART, (UART_LCR_WLEN8 | UART_LCR_SBS_1BIT));
  Chip_UART_SetupFIFOS(LPC_USART, (UART_FCR_FIFO_EN | UART_FCR_TRG_LEV2));
  Chip_UART_TXEnable(LPC_USART);
  return NO_ERROR;
}

result_t Uart_Deinit(void)
{
  return NO_ERROR;
}

version_t Uart_Version(void)
{
  version_t v = {0, 0, 0};
  return v;
}

#define UART_IDLE_BUFF 2

void Uart_IdleCall(void)
{
  uint8_t buff[UART_IDLE_BUFF];
  int read_bytes;
  
  if(Uart_Read(buff, UART_IDLE_BUFF, &read_bytes) == NO_ERROR)
  {
    
  }
}

result_t Uart_Send(const void *data, int bytes)
{
  uint32_t res_len = Chip_UART_SendRB(LPC_USART, &(Uart_Data.txring), data, bytes);
  
  if(res_len > 0 && bytes > 0)
  {
    return NO_ERROR;
  }
  else
  {
    return IO_ERROR;
  }
}

result_t Uart_Read(void *data, int bytes, int *read_bytes)
{
  *read_bytes = Chip_UART_ReadRB(LPC_USART, &(Uart_Data.rxring), data, bytes);

  if(*read_bytes > 0)
  {
    return NO_ERROR;
  }
  else
  {
    return IO_ERROR;
  }
}

void UART_IRQHandler(void)
{
  Chip_UART_IRQRBHandler(LPC_USART, &(Uart_Data.rxring), &(Uart_Data.txring));
}