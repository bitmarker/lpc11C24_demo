/*
 * @brief  Logging
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

#ifndef __LOGGING_H_
#define __LOGGING_H_

#include "general.h"


#define Logging_Idle() Logging_Idle_Call()

typedef enum
{
  OK = 0,
  HAS_WARNINGS,
  HAS_ERRORS
} Logging_State;

/* 
 * Call Logging_Idle from outside.
 * Uncomment the function call in the macro in header file!
 */
void Logging_Idle_Call(void);

result_t Logging_Init(void);

result_t Logging_Deinit(void);

version_t Logging_Version(void);

Logging_State Logging_CurrentState(void);

result_t Logging_Ack(void);

#endif /* Logging */
