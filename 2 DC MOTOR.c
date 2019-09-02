#include <avr/io.h>

#define F_CPU 1000000

#include <util/delay.h>

               
int main(void){

	DDRD = 0xFF;

	_delay_ms(50);//giving delay of 50ms

	DDRC = 0;//Taking portC as input.               

	int x=512;//0 point value on x-axis

	int y = 512;// 0 point value on y

	int x_1 =0;

	int y_1 =0;
	
	ADMUX |=(1<<REFS0);//setting the reference of ADC

	ADCSRA |=(1<<ADEN) |(1<ADPS2)|(1<ADPS1) |(1<<ADPS0);  //enabling the ADC,, setting prescalar 128

	               

	               while(1)

	               {

		               switch (ADMUX)//changing between channels by switch statement

		               {

			               case 0x40://When ADMUX==0x40

			               {

				               ADCSRA |=(1<<ADSC);//start ADC conversion

				               while ( !(ADCSRA & (1<<ADIF)));//wait till ADC conversion

				               x_1 = ADC;//moving value

				               ADC=0;//reset ADC register

				               ADMUX=0x41;//changing channel

				               break;

			               }

			               case 0x41:

			               {

				               ADCSRA |=(1<<ADSC);// start ADC conversion

				               while ( !(ADCSRA & (1<<ADIF)));// wait till ADC conversion

				               y_1 = ADC;// moving value

				               ADC=0;// reset ADC register

				               ADMUX=0x40;// changing channel

				               break;

			               }

		               }

		               

		               if (x_1<(x-50))

		               {

			               PORTD |=(1<<PIND5);

			               _delay_ms(5);

			               PORTD=0;

		               }

		               

		               

		               if (x_1>(x+50))

		               {

			               PORTD |=(1<<PIND4);

			               _delay_ms(5);

			               PORTD=0;

		               }

		               

		               

		               if (y_1<(y-50))

		               {

			               PORTD |=(1<<PIND6);

			               _delay_ms(5);

			               PORTD=0;

		               }

		               if (y_1>(y+50))

		               {

			               PORTD |=(1<<PIND7);

			               _delay_ms(5);

			               PORTD=0;

		               }

	               } }