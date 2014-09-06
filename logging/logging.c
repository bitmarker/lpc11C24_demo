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
 
#include "logging.h"

/*****************************************************************************
* Private types/enumerations/variables
****************************************************************************/

static struct
{
  Logging_State state;
} Logging_Data;

/*****************************************************************************
* Public types/enumerations/variables
****************************************************************************/
   
/*****************************************************************************
* Private functions
****************************************************************************/

/*****************************************************************************
* Public functions
****************************************************************************/

result_t Logging_Init(void)
{
  Logging_Data.state = OK;
  
  return NO_ERROR;
}

Logging_State Logging_CurrentState(void)
{
  return Logging_Data.state;
}

result_t Logging_Ack(void)
{
  /* TODO: Empty the error buffer here */
  
  Logging_Data.state = OK;
  return NO_ERROR;
}

result_t Logging_Deinit(void)
{
  return NO_ERROR;
}

version_t Logging_Version(void)
{
  version_t v = {0, 0, 1};
  return v;
}

/* 
 * Call Logging_Idle from outside.
 * Uncomment the function call in the macro in header file!
 */
void Logging_Idle_Call(void)
{
  
}
