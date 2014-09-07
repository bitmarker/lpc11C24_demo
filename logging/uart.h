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

#ifndef __UART_H_
#define __UART_H_

#include "general.h"
#include "chip.h"

#define Uart_Idle() Uart_IdleCall()

#define UART_SRB_SIZE 128 /* Send */
#define UART_RRB_SIZE 32 /* Receive */

/* 
 * Call Uart_Idle from outside.
 * Uncomment the function call in the macro in header file!
 */
void Uart_IdleCall(void);

result_t Uart_Init(void);

result_t Uart_Deinit(void);

version_t Uart_Version(void);

result_t Uart_Setup(uint32_t baudrate);

result_t Uart_Send(const void *data, int bytes);
result_t Uart_Read(void *data, int bytes, int *read_bytes);

#endif /* Uart */
