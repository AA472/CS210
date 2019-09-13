#ifndef RATIONAL_H_INCLUDED
#define RATIONAL_H_INCLUDED

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct{
    int denominator;
    int numerator;
} rational_t;


rational_t make_rational(int num, int den);
void r2a(rational_t x, char result[]);
rational_t rat_add(rational_t a,rational_t b);
rational_t rat_sub(rational_t a,rational_t b);
rational_t rat_mul(rational_t a,rational_t b);
rational_t rat_div(rational_t a,rational_t b);
rational_t simplest_form(rational_t c);


#endif // RATIONAL_H_INCLUDED
