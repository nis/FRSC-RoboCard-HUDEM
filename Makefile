#############################################################################
# RoboCard LED Test
# Copyright (c) 2010 Kjeld Jensen <kjeld@robocard.dk>
# 
# Copying and distribution of this file, with or without modification,
# are permitted in any medium without royalty provided the copyright
# notice and this notice are preserved. This file is offered as-is,
# without any warranty.
#############################################################################
# File: Makefile                                              
# Project: RoboCard LED Test                                        
# Platform: RoboCard v1.0 http://www.robocard.dk                                                
# Microcontroller: ATmega88PA                                                      
# Author: Kjeld Jensen <kjeld@robocard.dk>
# Created: 2010-08-09                                               
# Last modified: 2010-08-09                                          
#############################################################################

PROJECT=main
SOURCES=main.c led.c usart.c adc.c
MMCU=atmega328
CC=avr-gcc

CFLAGS= -mmcu=$(MMCU) -Wall -Os

default:
	@echo ""
	@echo "make clean......delete object & hex files"
	@echo "make hex........build the $(PROJECT).hex file"
	@echo "make flash......copy $(PROJECT).hex to RoboCard flash"
	@echo ""

hex: $(PROJECT).elf
	avr-objcopy -j .text -O ihex $(PROJECT).elf $(PROJECT).hex

$(PROJECT).elf: $(SOURCES)
	$(CC) $(CFLAGS) -I./ -o $(PROJECT).elf $(SOURCES)

flash: $(PROJECT).hex
	#avrdude -p atmega88p -c usbasp -U flash:w:$(PROJECT).hex
	avrdude -c usbasp -p m328p -U flash:w:main.hex:i

clean:
	rm -f $(PROJECT).elf $(PROJECT).hex
