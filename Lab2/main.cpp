#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <util/delay.h>
#include "GLOBAL.h"
void PWM_init()
{
    /*set fast PWM mode with non-inverted output*/
    TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00);
    DDRB|=(1<<PB3);  /*set OC0 pin as output*/
}

void PWM_init1()
{
    /*set fast PWM mode with non-inverted output*/
    TCCR2 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00);
    DDRD|=(1<<PD7);  /*set OC0 pin as output*/
}
int main(){
	sbi(PORTA,PA0);
	sbi(PORTA,PA1);
	sbi(PORTA,PA2);
	sbi(PORTA,PA3);
	PWM_init();
	PWM_init1();
	int j1=0, j2=0;
	while(true)
	{
		if(bit_is_clear(PINA,1))
		{
			if(j1<249)
			{
				j1+=5;
			}
			_delay_ms(100);
		}
		if(bit_is_clear(PINA,0))
		{
			if(j1>6)
			{
				j1-=5;
			}
			_delay_ms(100);
		}
		if(bit_is_clear(PINA,2))
		{
			if(j2<249)
			{
				j2+=5;
			}
			_delay_ms(100);
		}
		if(bit_is_clear(PINA,3))
		{
			if(j2>6)
			{
				j2-=5;
			}
			_delay_ms(100);
		}
		OCR0=j1;
		OCR2=j2;
	}
}
