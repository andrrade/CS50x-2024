#include <cs50.h>
#include <stdio.h>

// função principal
int main(void)
{
    int change;
    do{
        change = get_int("Change owed: "); // input para receber o valor que o usuário precisa de troco
    }
    while(change < 0);

    int quarters = 25;
    int dimes 10;
    int nickles = 5;
    int pennies 1;

    


}
