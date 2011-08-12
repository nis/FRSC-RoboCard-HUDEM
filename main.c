/******************************************************************************
 * The MIT License
 *
 * Copyright (c) 2011 Nis Sarup
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *****************************************************************************/

/*****************************    Defines    *******************************/

#define F_CPU 16000000

/***************************** Include files *******************************/

#include <avr/io.h>
#include "misc.h"
#include "led.h"
#include "usart.h"
#include "util/delay.h"
#include "avr/pgmspace.h"

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/

/*****************************   Functions   *******************************/

int main(void)
{
	led_init();
	usart_init();

	unsigned char c = 0;
	
	for (;;) /* go into an endless loop */
	{
		led_blink( (unsigned int)100);
		
		usart_tx_string_P(PSTR("Number: "));
		usart_tx((c + 0x30));
		usart_send_newline();
		
		if(c >= 9)
		{
			c = 0;
		} else {
			c++;
		}
		_delay_ms(1000);
	}
	return 0; /* just for the principle as we never get here */
}

/****************************** End Of Module *******************************/
