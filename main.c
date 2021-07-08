#include <avr/io.h>
#include <util/delay.h>

#define INIT_LED 	DDRA |= (1<<PA0)  //output - wyjœcie bo nim sterujemy (DDRx gdzie x to nazwa postu)
#define LED_ON 		PORTA |= (1<<PA0)
#define LED_OFF 	PORTA &= ~(1<<PA0)

#define INIT_SW  	DDRA &= ~(1<<PA2) // nie ma rezystora wiec pull-up
#define PULLUP_SW 	PORTA |= (1<<PA2)



int main(void)
{
	INIT_LED;
	INIT_SW;
	PULLUP_SW;
	
	while(1)
	{
		if(!(PINA & (1<<PA2))) //
		{
			LED_ON;
		}
		else
		{
			LED_OFF;
		}
	}
	return 0;

}