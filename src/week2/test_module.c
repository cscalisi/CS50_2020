#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int i = get_int("gimme number: ");

    int div = get_int("divide by: ");

    float mod = (i + div) % 26;

    printf("%f\n", mod);
}