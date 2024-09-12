#include <cs50.h>
#include <stdio.h>

void length(long number);

int main(void){
    long number;
    do
    {
        number = get_int("Number: ");
    }
    while (number < 0);

    length(number);
}

void length(long card)
{
    long i = 0;
    while (card > 0)
    {
        card /= 10;
        i++;
    }
    printf("%li\n", i);
}
