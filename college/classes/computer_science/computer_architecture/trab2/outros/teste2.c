#include<stdio.h>
#include<stdint.h>

int main()
{
int a = 0xFF;
uint32_t masc = 40;
uint16_t end = 2;

int ola = masc + end;
printf("%d", ola);
/*

printf("\nShiftar a de 1 bit pra direita  : %d",a >> 1);    //3
printf("\nShiftar a de 2 bits pra direita : %d",a >> 2);    //1
printf("\nShiftar a de 3 bit pra direita  : %d",a >> 3);    //0

printf("\nShiftar a de 1 bit pra esquerda  : %d",a << 1);   //12
printf("\nShiftar a de 2 bits pra esquerda : %d",a << 2);   //24
printf("\nShiftar a de 3 bits pra esquerda : %d",a << 3);   //48

printf("\nShiftar 1 de a bits pra esquerda : %d",1 << a);   //64

printf("\nAND logico bit a bit de 6(110) e 4(100) : %d", 6 & 1);  //4
*/
return(0);
}
