#include <cs50.h>
#include <stdio.h>

int calculate_coins(int cents, int type);

int main(void)
{
    int cents;

    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    int quarters = calculate_coins(cents, 25);
    cents %= 25;

    int dimes = calculate_coins(cents, 10);
    cents %= 10;

    int nickles = calculate_coins(cents, 5);
    cents %= 5;

    int pennies = calculate_coins(cents, 1);
    cents %= 1;

    int total_coins = quarters + dimes + nickles + pennies;

    printf("%d\n", total_coins);

    return 0;
}

int calculate_coins(int cents, int type)
{
    return cents / type;
}
