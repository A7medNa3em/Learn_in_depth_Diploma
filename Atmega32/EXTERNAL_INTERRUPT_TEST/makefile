SHELL = cmd

FCPU = 16000000
srcs = $(wildcard *.c)

application: application.hex

application.hex: $(srcs)
	avr-gcc -Wall -Os -std=c99 -D F_CPU=$(FCPU) -mmcu=atmega328p $(srcs) -o application.bin -Xlinker -Map=application.map
	avr-objcopy -j .text -j .data -O ihex application.bin application.hex
	avr-size -B application.bin

flash: application.hex
	avrdude -p m328p -c arduino -P com3 -b 115200 -U flash:w:application.hex:i -F
	
	
	
clean:
	del application.*