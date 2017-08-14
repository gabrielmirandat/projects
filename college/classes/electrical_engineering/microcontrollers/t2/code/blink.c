// Gabriel Martins de Miranda
// 130111350
// Segundo trabalho de Microcontroladores
// Codigo Morse

#include <msp430.h>
#include <string.h>

// constante representado um segundo
const unsigned long SECOND = 52000;
// palavra a ser representada em codigo morse
const char WORD[] = "Curtindo a Vida Adoidado";
// tamanho da palavra;
int word_lenght;
// char atual da palavra
volatile unsigned char c;
// contador de char da palavra
volatile unsigned int counter;

// funcoes usadas
void point();
void trace();
void space_symbol_morse();
void space_letter();
void space_word();
void machine();


int main(void) {
	WDTCTL = WDTPW | WDTHOLD;		// Stop watchdog timer
	P1DIR |= 0x01;					// Set P1.0 to output direction

	while(1)
	{
		machine();
		space_word();
	}

	return 0;
}

// aceso por um quarto de segundo
void point()
{
	volatile unsigned int i;	// volatile to prevent optimization
	P1OUT = 0x01;				// set P1.0

	i = SECOND/4;				// SW Delay
	do i--;
	while(i != 0);
}

// aceso por tres quartos de segundo
void trace()
{
	volatile unsigned int j;	// volatile to prevent optimization
	P1OUT = 0x01;				// set P1.0

	j = 3*SECOND/4;				// SW Delay
	do j--;
	while(j != 0);
}

// apagado por um quarto de segundo
void space_symbol_morse()
{
	volatile unsigned int k;	// volatile to prevent optimization
	P1OUT = 0x00;				// clear P1.0

	k = SECOND/4;				// SW Delay
	do k--;
	while(k != 0);
}

// apagado por tres quartos de segundo
void space_letter()
{
	volatile unsigned int l;	// volatile to prevent optimization
	P1OUT = 0x00;				// clear P1.0

	l = 3*SECOND/4;				// SW Delay
	do l--;
	while(l != 0);
}

// apagado por um segundo
// era pra ser sete quartos, mas sempre que usado 
// tambem eh usado a space_letter()
// ficando 4*SECOND/4 + 3*SECOND/4 = 7*SECOND/4
void space_word()
{
	volatile unsigned int m;	// volatile to prevent optimization
	P1OUT = 0x00;				// clear P1.0

	m = SECOND;					// SW Delay
	do m--;
	while(m != 0);
}

void machine()
{
	word_lenght = strlen(WORD);
	counter = 0;

	while(counter != word_lenght)
	{
		c = WORD[counter];

		switch(c)
		{
		  case 'A':
		  case 'a':
				  point();
		  	  	  space_symbol_morse();
		  	  	  trace();

		  	  	  break;
		  case 'B':
		  case 'b':
				  trace();
		  	  	  space_symbol_morse();
				  point();
				  space_symbol_morse();
				  point();
				  space_symbol_morse();
				  point();

				  break;
		  case 'C':
		  case 'c':
		  	  	  trace();
				  space_symbol_morse();
				  point();
				  space_symbol_morse();
				  trace();
				  space_symbol_morse();
				  point();

				  break;
		  case 'D':
		  case 'd':
		  	  	  trace();
				  space_symbol_morse();
				  point();
				  space_symbol_morse();
				  point();

				  break;
		  case 'E':
		  case 'e':
				  point();
		  case 'F':
		  case 'f':
		  	  	  point();
				  space_symbol_morse();
				  point();
				  space_symbol_morse();
				  trace();
				  space_symbol_morse();
				  point();

				  break;
		  case 'G':
		  case 'g':
				  trace();
				  space_symbol_morse();
				  trace();
				  space_symbol_morse();
				  point();

				  break;
		  case 'H':
		  case 'h':
				 point();
				 space_symbol_morse();
				 point();
				 space_symbol_morse();
				 point();
				 space_symbol_morse();
				 point();

				 break;
		  case 'I':
		  case 'i':
				 point();
				 space_symbol_morse();
				 point();

				 break;
		  case 'J':
		  case 'j':
				 point();
				 space_symbol_morse();
				 trace();
				 space_symbol_morse();
				 trace();
				 space_symbol_morse();
				 trace();

				 break;
		  case 'K':
		  case 'k':
				 trace();
				 space_symbol_morse();
				 point();
				 space_symbol_morse();
				 trace();

				 break;
		  case 'L':
		  case 'l':
				 point();
				 space_symbol_morse();
				 trace();
				 space_symbol_morse();
				 point();
				 space_symbol_morse();
				 point();

				 break;
		  case 'M':
		  case 'm':
				 trace();
				 space_symbol_morse();
				 trace();

				 break;
		  case 'N':
		  case 'n':
				 trace();
				 space_symbol_morse();
				 point();

				 break;
		  case 'O':
		  case 'o':
				 trace();
				 space_symbol_morse();
				 trace();
				 space_symbol_morse();
				 trace();

				 break;
		  case 'P':
		  case 'p':
				 point();
				 space_symbol_morse();
				 trace();
				 space_symbol_morse();
				 trace();
				 space_symbol_morse();
				 point();

				 break;
		  case 'Q':
		  case 'q':
				 trace();
				 space_symbol_morse();
				 trace();
				 space_symbol_morse();
				 point();
				 space_symbol_morse();
				 trace();

				 break;
		  case 'R':
		  case 'r':
				 point();
				 space_symbol_morse();
				 trace();
				 space_symbol_morse();
				 point();

				 break;
		  case 'S':
		  case 's':
				 point();
				 space_symbol_morse();
				 point();
				 space_symbol_morse();
				 point();

				 break;
		  case 'T':
		  case 't':
				 trace();

				 break;
		  case 'U':
		  case 'u':
				 point();
				 space_symbol_morse();
				 point();
				 space_symbol_morse();
				 trace();

				 break;
		  case 'V':
		  case 'v':
				 point();
				 space_symbol_morse();
				 point();
				 space_symbol_morse();
				 point();
				 space_symbol_morse();
				 trace();

				 break;
		  case 'W':
		  case 'w':
				 point();
				 space_symbol_morse();
				 trace();
				 space_symbol_morse();
				 trace();

				 break;
		  case 'X':
		  case 'x':
				 trace();
				 space_symbol_morse();
				 point();
				 space_symbol_morse();
				 point();
				 space_symbol_morse();
				 trace();

				 break;
		  case 'Y':
		  case 'y':
				 trace();
				 space_symbol_morse();
				 point();
				 space_symbol_morse();
				 trace();
				 space_symbol_morse();
				 trace();

				 break;
		  case 'Z':
		  case 'z':
				 trace();
				 space_symbol_morse();
				 trace();
				 space_symbol_morse();
				 point();
				 space_symbol_morse();
				 point();

				 break;
		  case ('1'):
				 point();
				 space_symbol_morse();
				 trace();
				 space_symbol_morse();
				 trace();
				 space_symbol_morse();
				 trace();
				 space_symbol_morse();
				 trace();

				 break;
		  case ('2'):
				 point();
				 space_symbol_morse();
				 point();
				 space_symbol_morse();
				 trace();
				 space_symbol_morse();
				 trace();
				 space_symbol_morse();
				 trace();

				 break;
		  case ('3'):
				 point();
				 space_symbol_morse();
				 point();
				 space_symbol_morse();
				 point();
				 space_symbol_morse();
				 trace();
				 space_symbol_morse();
				 trace();

				 break;
		  case ('4'):
				 point();
				 space_symbol_morse();
				 point();
				 space_symbol_morse();
				 point();
				 space_symbol_morse();
				 point();
				 space_symbol_morse();
				 trace();

				 break;
		  case ('5'):
				 point();
				 space_symbol_morse();
				 point();
				 space_symbol_morse();
				 point();
				 space_symbol_morse();
				 point();
				 space_symbol_morse();
				 point();

				 break;
		  case ('6'):
				 trace();
				 space_symbol_morse();
				 point();
				 space_symbol_morse();
				 point();
				 space_symbol_morse();
				 point();
				 space_symbol_morse();
				 point();

				 break;
		  case ('7'):
				 trace();
				 space_symbol_morse();
				 trace();
				 space_symbol_morse();
				 point();
				 space_symbol_morse();
				 point();
				 space_symbol_morse();
				 point();

				 break;
		  case ('8'):
				 trace();
				 space_symbol_morse();
				 trace();
				 space_symbol_morse();
				 trace();
				 space_symbol_morse();
				 point();
				 space_symbol_morse();
				 point();

				 break;
		  case ('9'):
				 trace();
				 space_symbol_morse();
				 trace();
				 space_symbol_morse();
				 trace();
				 space_symbol_morse();
				 trace();
				 space_symbol_morse();
				 point();

				 break;
		  case ('0'):
				 trace();

				 break;

		  case(' '):
		  		 space_word();

		}
		counter++;
		space_letter();
	}
}
