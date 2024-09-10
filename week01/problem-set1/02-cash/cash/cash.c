#include <stdio.h>
#include <cs50.h>

int main(void){
    float change;

    do{
        change = get_float("Change owed: ");
    }
    while(change < 0);


    int total_coins = quarters + dimes + nickles + pennies;

    printf(total_coins);
}

int calculate_coins(){
    
}
