// To compile and run
// gcc i2c.c -o i2c
// gcc i2c.c -o i2c -D DEBUG
// ./i2c

#include <stdio.h>
#include "i2c.h"

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
	// dados de 8 bits
	unsigned char rcv_buffer = 0x00;
	STATE state = INIT1;
	int error=0;
	
	while(!error)
	{
		switch(state)
		{
			case INIT1:// any	
				if(!getSignal(fp, sb)) error=1;
				if(sb->cur_sda==1 && sb->cur_slc ==1) state = INIT2;
				// stay in others cases

				#ifdef DEBUG
				printf("..init1\n");
				#endif

				break;

			case INIT2:// 11
				if(!getSignal(fp, sb)) error=1;
				if(sb->cur_sda==0 && sb->cur_slc ==1) state = START1;
				if(sb->cur_sda==0 && sb->cur_slc ==0) state = INIT1;
				if(sb->cur_sda==1 && sb->cur_slc ==0) state = INIT1;
				// stay in others cases

				#ifdef DEBUG
				printf("..init2\n");
				#endif

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
				if(!getSignal(fp, sb)) error=1;
				if(sb->cur_sda==1 && sb->cur_slc ==0) state = INIT1;
				if(sb->cur_sda==1 && sb->cur_slc ==1) state = STOP;
				if(sb->cur_sda==0 && sb->cur_slc ==0) state = START2;
				// stay in others cases

				#ifdef DEBUG
				printf("..start1_\n");
				#endif
				
				break;

			case START2:;// 00
				if(!getSignal(fp, sb)) error=1;
				if(sb->cur_sda==1 && sb->cur_slc ==1) state = INIT1;
				if(sb->cur_sda==1 && sb->cur_slc ==0) state = START3;
				if(sb->cur_sda==0 && sb->cur_slc ==1) state = BIT0_;
				// stay in others cases

				#ifdef DEBUG
				printf("..start2\n");
				#endif
				
				break;

			case START3:// 10
				if(!getSignal(fp, sb)) error=1;
				if(sb->cur_sda==0 && sb->cur_slc ==1) state = INIT1;
				if(sb->cur_sda==0 && sb->cur_slc ==0) state = START2;
				if(sb->cur_sda==1 && sb->cur_slc ==1) state = BIT1_;
				// stay in others cases

				#ifdef DEBUG
				printf("..start3\n");
				#endif

				break;

			case STOP:// 11
				printf("..stopped\n");
				if(!getSignal(fp, sb)) error=1;
				if(sb->cur_sda==0 && sb->cur_slc ==1) state = START1;
				else state = STOP_;

				break;

			case STOP_:// 11
				if(!getSignal(fp, sb)) error=1;
				if(sb->cur_sda==0 && sb->cur_slc ==1) state = START1;
				// stay in others cases

				#ifdef DEBUG
				printf("..stop_\n");
				#endif

				break;

			case BIT0_:// 01
				if(!getSignal(fp, sb)) error=1;
				if(sb->cur_sda==1 && sb->cur_slc ==0) state = INIT1;
				if(sb->cur_sda==1 && sb->cur_slc ==1) state = STOP;
				if(sb->cur_sda==0 && sb->cur_slc ==0 && sb->bit_bool ==0) state = BIT0;
				if(sb->cur_sda==0 && sb->cur_slc ==0 && sb->bit_bool ==1) state = ACK;
				// stay in others cases

				#ifdef DEBUG
				printf("..bit0_\n");
				#endif

				break;

			case BIT0:// 000
				printf("..bit0\n");
				if(!getSignal(fp, sb)) error=1;
				if(sb->cur_sda==1 && sb->cur_slc ==1) state = INIT1;
				if(sb->cur_sda==0 && sb->cur_slc ==1) state = BIT0_;
				if(sb->cur_sda==0 && sb->cur_slc ==0) state = START2;
				if(sb->cur_sda==1 && sb->cur_slc ==0) state = START3;

				rcv_buffer |= (0 << sb->bit_number);
				sb->bit_number +=1;
				
				break;

			case BIT1_:// 11
				if(!getSignal(fp, sb)) error=1;
				if(sb->cur_sda==0 && sb->cur_slc ==0) state = INIT1;
				if(sb->cur_sda==0 && sb->cur_slc ==1) state = START1_;
				if(sb->cur_sda==1 && sb->cur_slc ==0 && sb->bit_bool ==0) state = BIT1;
				if(sb->cur_sda==1 && sb->cur_slc ==0 && sb->bit_bool ==1) state = NACK;
				// stay in others cases

				#ifdef DEBUG
				printf("..bit1_\n");
				#endif

				break;

			case BIT1:// 100
				printf("..bit1\n");
				if(!getSignal(fp, sb)) error=1;
				if(sb->cur_sda==0 && sb->cur_slc ==1) state = INIT1;
				if(sb->cur_sda==0 && sb->cur_slc ==0) state = START2;
				if(sb->cur_sda==1 && sb->cur_slc ==0) state = START3;
				if(sb->cur_sda==1 && sb->cur_slc ==1) state = BIT1_;

				rcv_buffer |= (1 << sb->bit_number);
				sb->bit_number  +=1;

				break;

			case ACK:// 001
				printf("..ack");
				sb->bit_number =0;
				if(!getSignal(fp, sb)) error=1;
				if(sb->cur_sda==1 && sb->cur_slc ==1) state = INIT1;
				if(sb->cur_sda==0 && sb->cur_slc ==0) state = START2;
				if(sb->cur_sda==1 && sb->cur_slc ==0) state = START3;
				if(sb->cur_sda==0 && sb->cur_slc ==1) state = BIT0_;

				printByteHexa(rcv_buffer);
				
				break;
				
			case NACK:// 101
				printf("..nack\n");
				if(!getSignal(fp, sb)) error=1;
				sb->bit_number =0;
				if(sb->cur_sda==0 && sb->cur_slc ==1) state = INIT1;
				if(sb->cur_sda==0 && sb->cur_slc ==0) state = START2;
				if(sb->cur_sda==1 && sb->cur_slc ==0) state = START3;
				if(sb->cur_sda==1 && sb->cur_slc ==1) state = BIT1_;
				
		}
		sb->bit_bool = (sb->bit_number == 8)? 1:0;
	}
}

void printByteHexa(unsigned char byte)
{
	printf(" >>received: %x\n",byte);
}