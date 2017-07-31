#include<stdio.h>
#include<math.h>

int main(void){
    float freq, h, ganho;
    while(freq != 0){
    printf("Entre com a freq \n");
    scanf("%f", &freq);
    freq = freq*2*3.141592653589*1000;
    h = 1.0/(sqrt(1 + pow(freq,2.0)*pow((3.651),2.0)*pow(10.0,-12.0)));
    ganho = log10(h)*20;
    printf("h = %f \n", h);
    printf("ganho = %f \n", ganho);
    }
    return 0;

}
