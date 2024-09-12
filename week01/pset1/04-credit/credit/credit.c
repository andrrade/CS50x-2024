#include <cs50.h>
#include <stdio.h>

long length(long card);
void first_numbers(long all_numbers);

int main(void){
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while (number < 0);

    length(number);
    first_numbers(number);
}

long length(long card)
{
    int i = 0;
    while (card > 0)
    {
        card /= 10;
        i++;
    }
    return i;
}

void first_numbers(long all_numbers)
{
    int i = 0;
    while (all_numbers > 99)
    {
        all_numbers /= 10;
    }
    printf("%li\n", all_numbers);
}

