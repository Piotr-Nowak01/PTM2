#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <util/delay.h>
#include <math.h>
#include "GLOBAL.h"
int main()
{
    DDRD|=(1<<PD5);
    DDRD|=(1<<PD4);
	TCCR1A |= (1<<WGM10)|(1<<COM1A1)|(1<<COM1B1);
	TCCR1B |= (1<<WGM12)|(1<<CS10)|(1<<CS11);
	OCR1A=127;
	while(true)
		{
			;
		}
}
