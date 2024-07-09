#include <stdio.h>
#include <string.h>
#include "funcs.h"

/*  
    Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into a base b character 
    representation in the string s. In particular, itob(n,s,16) formats n as a hexadecimal integer in s.
*/
void ex3p5(int n, char s[], int b)
{
    int i, sign;

    if ((sign = n) < 0)  /* record sign */
        n = -n;          /* make n positive */
    i = 0;
    do {       /* generate digits in reverse order */
        s[i++] = n % b + '0';   /* get next digit */
    } while ((n /= b) > 0);     /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */
int main()
{
    int fahr, celsius;
    int lower, upper, step;
    double sum, atof(char []);

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    fahr = lower;
    while (fahr <= upper) {
        celsius = 5 * (fahr-32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }

    printf("\n\nitoa with base: ");
    char s[10] = {0}; // Replace '100' with the desired size of the character array
    ex3p5(6, s, 2);
    printf("%s", s);

    return 1;
}
