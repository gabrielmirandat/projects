// gcc mergsort.c -Wall -g -o mergsort
#include <stdio.h>
#define max 100000

int a[max+1];
int b[max];

// to concatenate the lists
void merging(int low, int mid, int high) {
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(a[l1] <= a[l2])
         b[i] = a[l1++];
      else
         b[i] = a[l2++];
   }
   
   while(l1 <= mid)    
      b[i++] = a[l1++];

   while(l2 <= high)   
      b[i++] = a[l2++];

   for(i = low; i <= high; i++)
      a[i] = b[i];
}

// main recursive sort
// call sort in two lists
void sort(int low, int high) {
   int mid;

   if(low < high) {
      mid = (low + high) / 2;
      sort(low, mid);
      sort(mid+1, high);
      merging(low, mid, high);
   } else { 
      return;
   }   
}

int main() { 
   int i, n, num_elements;
   // while( scanf("%d",&n) != EOF ){a[i++] = n;}
   
   i = 0 ;
   n = 0;
   if (scanf("%d", &n) == 1 && n > 0 && n < max)
   {
    int array[n];
    for (i = 0; i < n; i++)
    {
        if (scanf("%d", &array[i]) != 1)
            break;// …process error — terminate loop?…
    }
    // …use array…
   }
   
   num_elements = i;
   printf("sai do loop\n");

   printf("List before sorting\n");
   for(i = 0; i <= num_elements; i++)
   	printf("%d ", a[i]);
return 0;
   sort(0, num_elements);

   printf("\nList after sorting\n");
   for(i = 0; i <= num_elements; i++)
	printf("%d ", a[i]);

   return 0;
}
