#include <cs50.h>
#include <stdio.h>

int how_much(int cents, int type);

// função principal
int main(void)
{
    int change;
    do{
        change = get_int("Change owed: "); // input para receber o valor que o usuário precisa de troco
    }
    while(change < 0);

    int quarters = how_much(change, 25);
    change -= quarters;
    int dimes = how_much(change, 10);
    change -= dimes;
    int nickles = how_much(change, 5);
    change -= nickles;
    int pennies = how_much(change, 1);
    change -= pennies;

    int total_coins = quarters + dimes + nickles + pennies;
    printf("%i\n", total_coins);
}

int how_much(int cents, int type){
    return cents / type;
}
