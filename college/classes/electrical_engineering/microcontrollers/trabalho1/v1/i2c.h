// gcc i2c.c -o i2c
#include <stdio.h>

//states
// wrong states
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
	BIT0,
	BIT0_,
	BIT1,
	BIT1_,
	ACK,
	NACK
} STATE;

// signal flow
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