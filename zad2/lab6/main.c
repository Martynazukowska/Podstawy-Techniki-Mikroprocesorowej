
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


#define INIT_LED	DDRD |= (1<<PD2)  //output - wyjœcie bo nim sterujemy (DDRx gdzie x to nazwa postu)
#define LED_ON 		PORTD |= (1<<PD2)
#define LED_OFF 	PORTD &= ~(1<<PD2)

int counter=0;

ISR(TIMER0_OVF_vect)
{
	counter++;
	TCNT0 = 5;
	if(counter==125)
	{
		if(PIND & (1<<PD2))
			LED_OFF;
		else
		{
			LED_ON;
		}
		counter=0;
	} 
}


int main(void)
{
	INIT_LED;
	sei();
	TCCR0 |= (1<<CS02);	//preskaler na 256
	TCNT0 = 5;		//wartoœæ pocz¹tkowa licznika na 5 (liczymy o 5 do 255)
	TIMSK |= (1<<TOIE0);	//w³¹czenie przerwañ	
	while(1);

}
