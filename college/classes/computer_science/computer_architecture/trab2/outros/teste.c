#include <stdio.h>
#include <stdlib.h>

int *get_bits(int n, int bitswanted){
  int *bits = malloc(sizeof(int) * bitswanted);

  int k;
  for(k=0; k<bitswanted; k++){
    int mask =  1 << k;
    int masked_n = n & mask;
    int thebit = masked_n >> k;
    bits[k] = thebit;
  }

  return bits;
}

int main(){
  int n=2;

  int  bitswanted = 5;

  int *bits = get_bits(n, bitswanted);

  printf("%d = ", n);

  int i;
  for(i=bitswanted-1; i>=0;i--){
    printf("%d ", bits[i]);
  }

  printf("\n");
}
