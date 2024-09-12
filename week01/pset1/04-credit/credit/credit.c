#include <cs50.h>
#include <stdio.h>

void length(int number);

int main(void){
    int number;
    do
    {
        number = get_int("Number ");
    }
    while (number < 0);

    length(number);
}

void length(int card)
{
    int i;
    while ((card / 10) > 0)
    {
        i++;
    }
    printf("%i\n", i);
}
