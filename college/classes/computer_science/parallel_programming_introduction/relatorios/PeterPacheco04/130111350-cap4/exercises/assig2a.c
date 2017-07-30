/* Modified serial.c -- serial trapezoidal rule
 *
 * Calculate definite integral using trapezoidal rule.
 * The function f(x) is hardwired.
 * Input: a, b, n.
 * Output: estimate of integral from a to b of f(x)
 *    using n trapezoids.
 *
 * See Chapter 4, pp. 53 & ff. in PPMPI.

   To compile and run: 
          gcc assig2a.c -o assig2a
          ./assig2a
 */

#include <stdio.h>

float f(float x);  /* Function we're integrating */

int main() {
    float  integral;   /* Store result in integral   */
    float  a, b;       /* Left and right endpoints   */
    int    n;          /* Number of trapezoids       */
    float  h;          /* Trapezoid base width       */
    float  x;
    int    i;

    printf("Enter a, b, and n\n");
    scanf("%f %f %d", &a, &b, &n);

    h = (b-a)/n;
    integral = (f(a) + f(b) + f((b+a)/2))/3.0;
    x = a;
    
    for (i = 1; i <= n-1; i++) {
        x = x + h;
        integral = integral + f(x);
    }
    integral = integral*h;

    printf("With n = %d trapezoids, our estimate of the integral from %f to %f = %f\n", n, a, b, integral);

    return 0;
} /* main */


float f(float x) {
    float return_val;
    /* Calculate f(x).  Store calculation in return_val. */

    return_val = x*x;
    return return_val;
} /* f */
