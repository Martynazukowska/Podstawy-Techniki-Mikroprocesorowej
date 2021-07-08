#include <avr/io.h>
#include <util/delay.h>

#define INIT_LED_PA0 DDRA |= (1<<PA0)  //output - wyjœcie bo nim sterujemy (DDRx gdzie x to nazwa postu)
#define LED_ON PORTA |= (1<<PA0)
#define LED_OFF PORTA &= ~(1<<PA0)

int main(void)
{
	INIT_LED_PA0;
	
	while(1)
	{
		LED_ON;
		_delay_ms(300);
		LED_OFF;
		_delay_ms(300);
	}
	return 0;

}
