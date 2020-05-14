#include <math.h>
#include <stdio.h>

#define PI 3.14159265

int
main(void) {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("n! equals approximately %f\n",
           pow(n, n) * pow(M_E, -n) * sqrt(M_PI * (2*n + 1 / 3.0) ));

    return 0;
}
