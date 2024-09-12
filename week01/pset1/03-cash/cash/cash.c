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

    int quarters = how_much(int change, 25);
    
    int dimes = how_much(int change, 25);
    int nickles = how_much(int change, 25);
    int pennies = how_much(int change, 25);





}

int how_much(int cents, int type){
    return cents / type;
}
