#include "rational.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
rational_t make_rational(int num, int den){
   rational_t rat_number;
   rat_number.numerator = num;
   rat_number.denominator = den;
   return rat_number;
}
void r2a(rational_t x, char result[]){

    sprintf(result,"%d/%d", x.numerator, x.denominator);
}

rational_t rat_add (rational_t a,rational_t b){
    rational_t c;
    c.numerator = a.numerator* b.denominator + a.denominator* b.numerator;
    c.denominator = a.denominator * b.denominator;
    return simplest_form(c);
}
rational_t rat_sub (rational_t a,rational_t b){
    rational_t c;
    c.numerator = a.numerator*b.denominator - a.denominator* b.numerator;
    c.denominator = a.denominator * b.denominator;
    return simplest_form(c);
}
rational_t rat_mul (rational_t a,rational_t b){
    rational_t c;
    c.numerator = a.numerator *b.numerator;
    c.denominator = a.denominator * b.denominator;
    return simplest_form(c);
}
rational_t rat_div (rational_t a,rational_t b) {
    rational_t c;
    c.numerator = a.numerator * b.denominator;
    c.denominator= a.denominator * b.numerator;
    return simplest_form(c);
}
rational_t simplest_form(rational_t d){
    int gcd;
    int i;
    int a= abs(d.numerator);
    int b= abs(d.denominator);

    for (i=1;i<=a && i<= b;i++){
        if(a%i==0 && b%i==0){
            gcd =i;
        }
   }

   d.numerator= d.numerator/gcd;
   d.denominator= d.denominator/gcd;

    if(d.numerator < 0 && d.denominator < 0){
        d.numerator = abs(d.numerator);
        d.denominator = abs(d.denominator);
    }
    if(d.numerator == abs(d.numerator) && d.denominator == -abs(d.denominator))
    {
        d.numerator = -abs(d.numerator);
        d.denominator = abs(d.denominator);
    }
    return d;
}


