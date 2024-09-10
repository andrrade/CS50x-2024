#include <stdio.h>
#include <cs50.h>

int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickles(int cents);
int calculate_pennies(int cents);

int main(void){
    int cents;

    do{
        cents = get_float("Change owed: ");
    }
    while(cents < 0);

    int quarters = calculate_quarters(cents);
    cents -= (quarters * 25);

    int dimes = calculate_dimes(cents);
    cents -= (dimes * 10);

    int nickles = calculate_nickles(cents);
    cents -= (nickles * 5);

    int pennies = calculate_pennies(cents);
    cents -= (pennies * 1);
}

int calculate_quarters(int cents){
    int quarters = 0;
    while(cents >= 25){
        quarters++;
        cents -= 25;
    }
    return quarters;
}

int calculate_dimes (int cents){
    int dimes = 0;
    while(dimes >= 10){
        dimes++;
        cents -= 10;
    }
    return dimes;
}

int calculate_nickles(int cents){
    int nickles = 0;
    while(nickles >= 5){
        nickles++;
        cents -= 5;
    }
    return nickles;
}

int calculate_pennies(int cents){
    int pennies = 0;
    while(pennies >= 1){
        pennies++;
        cents -= 1;
    }
    return pennies;
}
