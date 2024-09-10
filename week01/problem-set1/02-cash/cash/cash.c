#include <stdio.h>
#include <cs50.h>

int calculate_coins(int cents, int type);

int main(void){
    int cents;

    do{
        cents = get_int("Change owed: ");
    }
    while(cents < 0);

    int quarters = calculate_coins(&cents, 25);
    int dimes = calculate_coins(&cents, 10);
    int nickles = calculate_coins(&cents, 5);
    int pennies = calculate_coins(&cents, 1);

    int total_coins = quarters + dimes + nickles + pennies;

    printf("Total coins: %d\n", total_coins);
}

int calculate_coins(int *cents, int type){
    int coins = *cents / type;
    *cents %= type;
    return coins;
}
