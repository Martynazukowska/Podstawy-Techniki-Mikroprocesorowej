#include <avr/io.h>
#include <util/delay.h>

#define INIT_LED 	DDRC |= (1<<PC5)  //output - wyjœcie bo nim sterujemy (DDRx gdzie x to nazwa postu)
#define LED_ON 		PORTC |= (1<<PC5)
#define LED_OFF 	PORTC &= ~(1<<PC5)

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

#define INIT_1 	DDRC |= (1<<PC3)  //output - wyjœcie bo nim sterujemy (DDRx gdzie x to nazwa postu)
#define ON_1 		PORTC |= (1<<PC3)
#define OFF_1 	PORTC &= ~(1<<PC3)

#define INIT_2 	DDRC |= (1<<PC2)  //output - wyjœcie bo nim sterujemy (DDRx gdzie x to nazwa postu)
#define ON_2 		PORTC |= (1<<PC2)
#define OFF_2 	PORTC &= ~(1<<PC2)

#define INIT_3 	DDRC |= (1<<PC1)  //output - wyjœcie bo nim sterujemy (DDRx gdzie x to nazwa postu)
#define ON_3 		PORTC |= (1<<PC1)
#define OFF_3 	PORTC &= ~(1<<PC1)

#define INIT_4 	DDRC |= (1<<PC0)  //output - wyjœcie bo nim sterujemy (DDRx gdzie x to nazwa postu)
#define ON_4 		PORTC |= (1<<PC0)
#define OFF_4 	PORTC &= ~(1<<PC0)


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


int pomiar(void)
{
	ADCSRA |= (1<<ADSC); //start konwersji 
	while(ADCSRA & (1<<ADSC)); //WHILE NA ZERACH KONCZY ZADANIE 
	return ADC;
}

int main()
{
	INIT_LED;
	INIT_LED1;
	INIT_LED2;
	INIT_LED3;
	INIT_LED4;
	INIT_LED5;
	INIT_LED6;
	INIT_LED7;
	INIT_1;
	INIT_2;
	INIT_3;
	INIT_4;
	
	
	ADMUX |= (1<<REFS0); //ustawienie napiecia ref na napiecie zasilania
	ADMUX |= ((1<<MUX0)| (1<<MUX1) | (1<<MUX2)); //wybor kana³u, w tym wypadku kana³ 7 (00111)
	
	ADCSRA |= (1<<ADEN); // uruchomienie przetwornika ADC
	ADCSRA |= ((1<<ADPS0) | (1<<ADPS1)); //Ustawienie preskalera na 8 (011) - ustaw czestotliwoœæ na 8 
	
	while(1)
	{
		int zm=pomiar();
		if(zm<512)
		{
			LED_ON;
		}
		else
		{
			LED_OFF;
		}
		
		int a=zm/1000;
		
		int b=(zm-a*1000)/100;
		int c=(zm-a*1000-b*100)/10;
		int d=zm-a*1000-b*100-c*10;	
		
		ON_1;
		wyswietlacz(a);
		_delay_ms(10);
		OFF_1;
		ON_2;
		wyswietlacz(b);
		_delay_ms(10);
		OFF_2;
		ON_3;
		wyswietlacz(c);
		_delay_ms(10);
		OFF_3;
		ON_4;
		wyswietlacz(d);
		_delay_ms(10);
		OFF_4;
	}
		
	return 0;
	
	

}