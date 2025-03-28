compilefull: compileobject compilehex

compileobject: atmega_indicators_code.c
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o atmega_indicators_code.o atmega_indicators_code.c

compilehex:
	avr-gcc -o atmega_indicators_code.bin atmega_indicators_code.o
	avr-objcopy -O ihex -R .eeprom atmega_indicators_code.bin atmega_indicators_code.hex

upload:
	avrdude -c arduino -p m328p -P COM3 -b 115200 -U flash:w:atmega_indicators_code.hex