#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


#define INIT_LED1 	DDRA |= (1<<PA0)  //output - wyjœcie bo nim sterujemy (DDRx gdzie x to nazwa postu)
#define LED_ON1 		PORTA |= (1<<PA0)
#define LED_OFF1 	PORTA &= ~(1<<PA0)

#define INIT_SW1  	DDRC &= ~(1<<PC3) // nie ma rezystora wiec pull-up
#define PULLUP_SW1 	PORTC |= (1<<PC3)

#define INIT_LED2 	DDRA |= (1<<PA1)  //output - wyjœcie bo nim sterujemy (DDRx gdzie x to nazwa postu)
#define LED_ON2 		PORTA |= (1<<PA1)
#define LED_OFF2 	PORTA &= ~(1<<PA1)

#define INIT_SW2  	DDRD &= ~(1<<PD7) // nie ma rezystora wiec pull-up
#define PULLUP_SW2 	PORTD |= (1<<PD7)

#define INIT_LED3 	DDRA |= (1<<PA2)  //output - wyjœcie bo nim sterujemy (DDRx gdzie x to nazwa postu)
#define LED_ON3 		PORTA |= (1<<PA2)
#define LED_OFF3 	PORTA &= ~(1<<PA2)

#define INIT_LED4 	DDRA |= (1<<PA3)  //output - wyjœcie bo nim sterujemy (DDRx gdzie x to nazwa postu)
#define LED_ON4 		PORTA |= (1<<PA3)
#define LED_OFF4 	PORTA &= ~(1<<PA3)

#define INIT_LED5 	DDRA |= (1<<PA4)  //output - wyjœcie bo nim sterujemy (DDRx gdzie x to nazwa postu)
#define LED_ON5 		PORTA |= (1<<PA4)
#define LED_OFF5 	PORTA &= ~(1<<PA4)

#define INIT_LED6 	DDRA |= (1<<PA5)  //output - wyjœcie bo nim sterujemy (DDRx gdzie x to nazwa postu)
#define LED_ON6 		PORTA |= (1<<PA5)
#define LED_OFF6 	PORTA &= ~(1<<PA5)

#define INIT_LED7 	DDRA |= (1<<PA6)  //output - wyjœcie bo nim sterujemy (DDRx gdzie x to nazwa postu)
#define LED_ON7 		PORTA |= (1<<PA6)
#define LED_OFF7 	PORTA &= ~(1<<PA6)

int a=5;

void wyswietlacz(int cyfra) {
  //Instrukcja switch ustawia odpowiednie stany na wyjsciach
  //w zaleznosci od podanej cyfry
  switch (cyfra) {
    case 0:
			LED_ON1;
			LED_ON2;
			LED_ON3;
			LED_ON4;
			LED_ON5;
			LED_ON6;
			LED_OFF7;
    break; 
    
    case 1:
			LED_OFF1;
			LED_ON2;
			LED_ON3;
			LED_OFF4;
			LED_OFF5;
			LED_OFF6;
			LED_OFF7;
    break; 
    
    case 2:
			LED_ON1;
			LED_ON2;
			LED_OFF3;
			LED_ON4;
			LED_ON5;
			LED_OFF6;
			LED_ON7;
    break; 
    
    case 3:
			LED_ON1;
			LED_ON2;
			LED_ON3;
			LED_ON4;
			LED_OFF5;
			LED_OFF6;
			LED_ON7;
    break; 
    
    case 4:
			LED_OFF1;
			LED_ON2;
			LED_ON3;
			LED_OFF4;
			LED_OFF5;
			LED_ON6;
			LED_ON7;
			
    break; 
    
    case 5:
			LED_ON1;
			LED_OFF2;
			LED_ON3;
			LED_ON4;
			LED_OFF5;
			LED_ON6;
			LED_ON7;
			
    break; 
    
    case 6:
			LED_ON1;
			LED_OFF2;
			LED_ON3;
			LED_ON4;
			LED_ON5;
			LED_ON6;
			LED_ON7;
    break;
   
    case 7:
			LED_ON1;
			LED_ON2;
			LED_ON3;
			LED_OFF4;
			LED_OFF5;
			LED_OFF6;
			LED_OFF7;
    break;
    
    case 8:
			LED_ON1;
			LED_ON2;
			LED_ON3;
			LED_ON4;
			LED_ON5;
			LED_ON6;
			LED_ON7;
    break;
    
    case 9:
			LED_ON1;
			LED_ON2;
			LED_ON3;
			LED_ON4;
			LED_OFF5;
			LED_ON6;
			LED_ON7;
    break;
  }
}


ISR(INT0_vect)

{
	if(a==0)
	{
		a=a;
	}
	else
	{
		a--;
	}
}

ISR(INT1_vect)

{
	if(a==9)
	{
		a=a;
	}
	else
	{
		a++;
	}
}

int main()
{
	INIT_LED1;
	INIT_LED2;
	INIT_LED3;
	INIT_LED4;
	INIT_LED5;
	INIT_LED6;
	INIT_LED7;
	
	sei(); //SREG
	
	MCUCR |= (1<<ISC01); //zbocze opadaj¹ce - wyzwolenie przerwania
	GICR |= (1<<INT0); //aktywacja przerwania
	
	MCUCR |= (1<<ISC11); //zbocze opadaj¹ce - wyzwolenie przerwania
	GICR |= (1<<INT1); //aktywacja przerwania
	
	while(1)
	{
		wyswietlacz(a);
	}
	return 0;
}