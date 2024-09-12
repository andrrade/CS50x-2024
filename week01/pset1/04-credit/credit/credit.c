#include <cs50.h>
#include <stdio.h>

void length(long number);

int main(void){
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while (number < 0);

    length(number);
}

long length(long card)
{
    int i = 0;
    while (card > 0)
    {
        card /= 10;
        i++;
    }
    printf("%i\n", i);
}
