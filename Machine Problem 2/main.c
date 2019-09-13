#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()

{
    double num;
    double root;

    printf("Enter a number: ");
    scanf("%lf", &num);

    root= sqrt(num);    //Function call

    printf("The square root is %f\n",root);

    return 0;




}
