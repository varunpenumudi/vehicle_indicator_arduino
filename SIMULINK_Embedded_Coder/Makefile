compilefull: compileobject compilehex

compileobject: atmega_indicators_code.c
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o buildfiles/atmega_indicators_code.o atmega_indicators_code.c

compilehex:
	avr-gcc -o buildfiles/atmega_indicators_code.bin buildfiles/atmega_indicators_code.o
	avr-objcopy -O ihex -R .eeprom buildfiles/atmega_indicators_code.bin buildfiles/atmega_indicators_code.hex

upload:
	avrdude -c arduino -p m328p -P COM3 -b 115200 -U flash:w:buildfiles/atmega_indicators_code.hex