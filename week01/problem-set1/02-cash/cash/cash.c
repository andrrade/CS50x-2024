#include <stdio.h>
#include <cs50.h>

int calculate_coins(int cents, int type);

int main(void)
{
    int cents;

    // Solicita ao usuário o valor em centavos
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    // Calcula o número de cada tipo de moeda
    int quarters = calculate_coins(cents, 25);
    cents %= 25;

    int dimes = calculate_coins(cents, 10);
    cents %= 10;

    int nickles = calculate_coins(cents, 5);
    cents %= 5;

    int pennies = calculate_coins(cents, 1);
    cents %= 1;

    // Calcula o total de moedas
    int total_coins = quarters + dimes + nickles + pennies;

    // Exibe o total de moedas
    printf("Total coins: %d\n", total_coins);

    return 0;
}

int calculate_coins(int cents, int type)
{
    return cents / type; // Calcula a quantidade de moedas
}
