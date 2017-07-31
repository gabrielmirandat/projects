// To compile and run
// gcc i2c.c -o i2c
// gcc i2c.c -o i2c -D DEBUG
// ./i2c

#include <stdio.h>

//states
typedef enum
{
	INIT1,
	INIT2, 
	START1, 
	START1_,
	START2, 
	START3,
	STOP, 
	STOP_, 
	BIT0_,
	BIT0,
	BIT1_,
	BIT1,
	ACK,
	NACK
} STATE;

// signal buffer flow 
typedef struct 
{
	unsigned int cur_sda: 1;
	unsigned int cur_slc: 1;
	unsigned int bit_bool: 1;
	unsigned int bit_number;
}Signal;

int beginFile(FILE** fp);
int getSignal(FILE* fp, Signal* s);
void stateMachine(FILE* fp, Signal* s);
void printByteHexa(unsigned char byte);