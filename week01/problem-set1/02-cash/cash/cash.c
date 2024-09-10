#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void){
    float change;

    do{
        change = get_int("Change owed: ");
    }
    while(change < 0);

    int cents = round(change * 100);

    int quarters = cents / 25;
    cents %= 25;

    int dimes = cents / 10;
    cents %= 10;

    int nickles = nickles / 5;
    cents %= 5;

    int pennies = cents / 1;
    cents %= 1;

    int total_coins = quarters + dimes + nickles + pennies;

    printf("Total coins: %d\n", total_coins);
}
