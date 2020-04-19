#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Prompt user for change owed
    float change;
    int totalcoins=0;
    int coins;
    do
    {
        change = get_float("Change owed?\n");
    }
    // Check that it's a non-zero value
    while (change <= 0);

    // Round change up to avoid imprecisions
    int ex_change = round(change * 100);

    // Initiate loop
    if (ex_change >= 25)
    {
        coins = ex_change / 25;
        ex_change = ex_change % 25;
        totalcoins = coins + totalcoins;
    }
    if (ex_change >= 10)
    {
        coins = ex_change / 10;
        ex_change = ex_change % 10;
        totalcoins = coins + totalcoins;
    }
    if (ex_change >= 5)
    {
        coins = ex_change / 5;
        ex_change = ex_change % 5;
        totalcoins = coins + totalcoins;
    }
    if (ex_change >= 1)
    {
        coins = ex_change / 1;
        ex_change = ex_change % 1;
        totalcoins = coins + totalcoins;
    }

    // Print number of coins used
    printf("Coins used: %i\n", totalcoins);
}
