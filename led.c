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

/***************************** Include files *******************************/

#include "led.h"
#include "misc.h"

/*****************************    Defines    *******************************/

#define LEDPORT 	PORTB
#define LEDPIN		DDB0

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/

/*****************************   Functions   *******************************/

void led_init ( void ) {
	SBIT(DDRB, LEDPIN); // enable PB0 (led pin) as output
	led_off();
}

void led_on ( void ) {
	CBIT(LEDPORT, LEDPIN); // set PB0 output to GND turning led on
}

void led_off ( void ) {
	SBIT(LEDPORT, LEDPIN); // set PB0 output to VCC turning led off
}

void led_toggle ( void ) {
	TBIT(LEDPORT, LEDPIN); // Toggle LED
}

void led_blink ( unsigned int speed ) {
	static unsigned int count = 0;
	
	count++; /* increace count by one */

	if(count == speed) /* if time to switch led state */
	{
		count=0; /* reset count */
		led_toggle();
	}
}

/****************************** End Of Module *******************************/