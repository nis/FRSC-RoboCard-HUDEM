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

#define F_CPU 16000000 // Clock Speed
#define BAUD 38400
#define MYUBRR ((F_CPU/16/BAUD)-1)
#define TX_PIN 1
#define RX 0

/***************************** Include files *******************************/

#include "avr/io.h"
#include "usart.h"
#include "misc.h"
#include "util/delay.h"
#include <avr/pgmspace.h>

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/

/*****************************   Functions   *******************************/

void usart_init(void)
/*****************************************************************************
*   Function : See module specification (.h-file).
*****************************************************************************/
{
	// Set pin to output
	SBIT(PORTD, TX_PIN); 

	// Enable transmit
	usart_enable_tx();

	// Asynchronous USART, no Parity, one stop bit, Character Size 8 bit
	UCSR0C |= (1<<UCSZ01)|(1<<UCSZ00);
	
	// Set BAUD rate
	UBRR0H = (unsigned char)((MYUBRR)>>8);
	UBRR0L = (unsigned char)MYUBRR;
}

void usart_enable_tx ( void ) {
	SBIT(UCSR0B, TXEN0);
}

void usart_tx ( unsigned char data ) {
	// Wait for empty buffer
	while ( !( UCSR0A & (1<<UDRE0)) );
	
	// Send the data
	UDR0 = data;
}

void usart_tx_string( const char *s ) 
{ 
    while (*s) 
      usart_tx(*s++);
}

void usart_tx_string_P( const char *s ) 
{ 
    while (pgm_read_byte(s) != 0x00)
	     usart_tx(pgm_read_byte(s++));
}



void usart_send_newline( void )
{
	usart_tx('\r');
	usart_tx('\n');
}

/****************************** End Of Module *******************************/