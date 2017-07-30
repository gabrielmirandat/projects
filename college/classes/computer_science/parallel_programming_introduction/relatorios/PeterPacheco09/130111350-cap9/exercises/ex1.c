/* gcc ex1.c -o ex1
 *
 * Modified bug.c.  Serial program
 * Program that tries to read a list of floats and sort them in
 *    increasing order.
 * Warning!  This program is definitely incorrect!
 *
 * Input:
 *    size of list (int)
 *    list of floats
 *
 * Output:
 *    Sorted list
 *
 * Algorithm:
 *    1. Get list size
 *    2. Get first input float.
 *    3. For each new element
 *        (a) read it in
 *        (b) use linear search to determine where it
 *            should be inserted
 *        (c) insert it by shifting greater elements down
 *            one
 *    4. Print list
 *
 * See Chap 9, pp 180 & ff in PPMPI
 */
#include <stdio.h>

/* Maximum list size */
#define MAX 100

/* Function for printing contents of list */
void Print_x(char* title, float x[], int size);

void Snapshot(char* title, int num_vals, float x[],
    int i, int j,  int k, float temp);

// 5 3 4 1 2
// len: 5
// vet: 3 5
// tmp: 4
// i: 2
// j: 0
// k: 
int main() {
    int num_vals;   /* Input list size                  */
    float x[MAX];   /* Storage for the sorted list      */
    float temp;     /* Most recently read input value   */
    int i, j, k;    /* Subscripts.  i:  counts input    */
                    /* values, j:  position to insert   */
                    /* new value.                       */

    printf("How many input values?\n");
    scanf("%d", &num_vals);

    printf("Now enter each value.\n");
    /* Get first value */
    scanf("%f", &(x[0]));

    for (i = 1; i < num_vals; i++) {
        scanf("%f", &temp);

        /* Determine where to insert */
        j = i - 1;
        while ((j >= 0) && (temp < x[j]))
        {
        	x[j+1] = x[j];
            j--;
        }
            
		x[j+1] = temp;
    }

    Print_x("Contents of x", x, num_vals); /* Print_x */
    return 0;
} 


void Print_x(char* title, float x[], int size) {
    int i;

    printf("%s\n", title);
    for (i = 0; i < size; i++)
        printf("%f ", x[i]);
    printf("\n");
} /* Print_x */

void Snapshot(char* title, int num_vals, float x[],
    int i, int j,  int k, float temp) {

    printf("*********************\n");
    printf("%s\n", title);
    printf("num_vals = %d, i = %d, temp = %f\n",
        num_vals, i, temp);
    printf("j = %d, k = %d\n", j, k);
    Print_x("x = ", x, i);
    printf("*********************\n\n");
    fflush(stdout);
}

