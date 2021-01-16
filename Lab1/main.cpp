#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <util/delay.h>
#include "GLOBAL.h"
int main(){
	sbi(PORTA,PA0);
	sbi(PORTA,PA1);
	DDRC=0xFF;
	bool led1=false,led2=false;
	while(true)
	{
		if(bit_is_clear(PINA,0))
		{
			if(led1==false)
			{
				sbi(PORTC,PC0);
				led1=true;
				_delay_ms(200);
			}
			else
			{
				cbi(PORTC, PC0);
				led1=false;
				_delay_ms(200);
			}
		}
		if (bit_is_clear(PINA,1))
		{
			if(led2==false)
			{
				sbi(PORTC,PC1);
				led2=true;
				_delay_ms(200);
			}
			else
			{
				cbi(PORTC,PC1);
				led2=false;
				_delay_ms(200);
			}
		}
	}
}
