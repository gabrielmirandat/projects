// gcc i2c.c -o i2c
// printf("..\n");
#include <stdio.h>
#include "i2c.h"

// dados de 8 bits
unsigned int rcv_buffer[8];
unsigned int rcv_buffer_counter = 0;

int main(int argc, char* argv[])
{
	FILE* flow_file;
	Signal signal_buffer = { 1,1,0,0 };

	// try to begin using FILE
	if(!beginFile(&flow_file))
	{
		perror("error opening file.\n");
		return -1;
	}
	
	stateMachine(flow_file, &signal_buffer);
	
	fclose(flow_file);
	return 1;
}

int beginFile(FILE** fp)
{
	*fp = fopen("content/entrada2.txt", "r");
	return (*fp == NULL)? 0 : 1;
}


int getSignal(FILE* fp, Signal* sb)
{
	int c;

	c = fgetc(fp);

	if(c == EOF) return 0;
	sb->cur_sda = c; 
	sb->cur_slc = fgetc(fp);
	// to remove \n
	fgetc(fp);
	return 1;
}

void stateMachine(FILE* fp, Signal* sb)
{
	STATE state = INIT1;
	int error=0;
	
	while(!error)
	{
		switch(state)
		{
			case INIT1:// any	
				if(!getSignal(fp, sb)) error=1; /*printf("..init1\n");*/
				if(sb->cur_sda==1 && sb->cur_slc ==1) state = INIT2;
				// stay in others cases
				
				break;

			case INIT2:// 11
				if(!getSignal(fp, sb)) error=1; /*printf("..init2\n");*/
				if(sb->cur_sda==0 && sb->cur_slc ==1) state = START1;
				if(sb->cur_sda==0 && sb->cur_slc ==0) state = INIT1;
				if(sb->cur_sda==1 && sb->cur_slc ==0) state = INIT1;
				// stay in others cases

				break;

			case START1:// 01
				printf("..started\n");
				if(!getSignal(fp, sb)) error=1;
				if(sb->cur_sda==1 && sb->cur_slc ==0) state = INIT1;
				if(sb->cur_sda==1 && sb->cur_slc ==1) state = STOP;
				if(sb->cur_sda==0 && sb->cur_slc ==0) state = START2;
				if(sb->cur_sda==0 && sb->cur_slc ==1) state = START1_;
				
				break;

			case START1_:// 01
				if(!getSignal(fp, sb)) error=1; /*printf("..start1_\n");*/
				if(sb->cur_sda==1 && sb->cur_slc ==0) state = INIT1;
				if(sb->cur_sda==1 && sb->cur_slc ==1) state = STOP;
				if(sb->cur_sda==0 && sb->cur_slc ==0) state = START2;
				// stay in others cases
				
				break;

			case START2:;// 00
				if(!getSignal(fp, sb)) error=1; /*printf("..start2\n");*/
				if(sb->cur_sda==1 && sb->cur_slc ==1) state = INIT1;
				if(sb->cur_sda==1 && sb->cur_slc ==0) state = START3;
				if(sb->cur_sda==0 && sb->cur_slc ==1 && sb->bit_bool ==0) state = BIT0;
				if(sb->cur_sda==0 && sb->cur_slc ==1 && sb->bit_bool ==1) state = ACK;
				// stay in others cases
				
				break;

			case START3:// 10
				if(!getSignal(fp, sb)) error=1; /*printf("..start3\n");*/
				if(sb->cur_sda==0 && sb->cur_slc ==1) state = INIT1;
				if(sb->cur_sda==0 && sb->cur_slc ==0) state = START2;
				if(sb->cur_sda==1 && sb->cur_slc ==1 && sb->bit_bool ==0) state = BIT1;
				if(sb->cur_sda==1 && sb->cur_slc ==1 && sb->bit_bool ==1) state = NACK;
				// stay in others cases

				break;

			case STOP:// 11
				printf("..stopped\n");
				if(!getSignal(fp, sb)) error=1;
				if(sb->cur_sda==0 && sb->cur_slc ==1) state = START1;
				else state = STOP_;

				break;

			case STOP_:// 11
				if(!getSignal(fp, sb)) error=1; /*printf("..stop_\n");*/
				if(sb->cur_sda==0 && sb->cur_slc ==1) state = START1;
				// stay in others cases

				break;

			case BIT0:// 010
				printf("..bit0\n");
				sb->bit_number +=1;
				if(!getSignal(fp, sb)) error=1;
				if(sb->cur_sda==1 && sb->cur_slc ==0) state = INIT1;
				if(sb->cur_sda==0 && sb->cur_slc ==0) state = START2;
				if(sb->cur_sda==1 && sb->cur_slc ==1) state = STOP;
				if(sb->cur_sda==0 && sb->cur_slc ==1) state = BIT0_;
				
				break;

			case BIT0_:// 01
				if(!getSignal(fp, sb)) error=1; /*printf("..bit0_\n");*/
				if(sb->cur_sda==1 && sb->cur_slc ==0) state = INIT1;
				if(sb->cur_sda==0 && sb->cur_slc ==0) state = START2;
				if(sb->cur_sda==1 && sb->cur_slc ==1) state = STOP;
				// stay in others cases

				break;

			case BIT1:// 110
				printf("..bit1\n");
				sb->bit_number  +=1;
				if(!getSignal(fp, sb)) error=1;
				if(sb->cur_sda==0 && sb->cur_slc ==0) state = INIT1;
				if(sb->cur_sda==0 && sb->cur_slc ==1) state = START1_;
				if(sb->cur_sda==1 && sb->cur_slc ==0) state = START3;
				if(sb->cur_sda==1 && sb->cur_slc ==1) state = BIT1_;

				break;

			case BIT1_:// 11
				if(!getSignal(fp, sb)) error=1; /*printf("..bit_\n");*/
				if(sb->cur_sda==0 && sb->cur_slc ==0) state = INIT1;
				if(sb->cur_sda==0 && sb->cur_slc ==1) state = START1_;
				if(sb->cur_sda==1 && sb->cur_slc ==0) state = START3;
				// stay in others cases

				break;

			case ACK:// 011
				printf("..ack\n");
				sb->bit_number =0;
				if(!getSignal(fp, sb)) error=1;
				if(sb->cur_sda==1 && sb->cur_slc ==0) state = INIT1;
				if(sb->cur_sda==0 && sb->cur_slc ==0) state = START2;
				if(sb->cur_sda==1 && sb->cur_slc ==1) state = STOP;
				// stay in others cases

				break;
				
			case NACK:// 111
				printf("..nack\n");
				if(!getSignal(fp, sb)) error=1;
				sb->bit_number =0;
				if(sb->cur_sda==0 && sb->cur_slc ==0) state = INIT1;
				if(sb->cur_sda==0 && sb->cur_slc ==1) state = START1_;
				if(sb->cur_sda==1 && sb->cur_slc ==0) state = START3;
				// stay in others cases
		}
		sb->bit_bool = (sb->bit_number == 8)? 1:0;
	}
}