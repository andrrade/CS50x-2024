#include <cs50.h>
#include <stdio.h>

void length(int number);

int main(void){
    int number;
    do
    {
        number = get_int("Number: ");
    }
    while (number < 0);

    length(number);
}

void length(int card)
{
    int i = 0;
    while (card > 0)
    {
        card /= 10;
        i++;
    }
    printf("%i\n", i);
}
