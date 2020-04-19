#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int s = get_string("gimme string: ");

    int i = get_int("gimme numba: ");

    printf("%c\n", s + i);
}