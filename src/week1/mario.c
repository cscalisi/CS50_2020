#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get height of pyramid
    int n;
    do
    {
        n = get_int("Height: ");
    }
    
    // Make sure that the number is between 1 and 8
    while (n < 1 || n > 8);

    // Start first loop: print n rows
    for (int i = 0; i < n; i++)
    {
        // Initialize second loop: print n - 1 empty spaces
        for (int d = n - 1; d > i; d--)
        {
            printf(" ");
        }
        for (int x = n - i; x < n + 1; x++)
            // Print hashes to create the pyramid
        {
            printf("#");
        }
        printf("\n");
    }
}

