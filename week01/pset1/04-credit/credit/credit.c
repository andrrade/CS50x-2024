#include <cs50.h>
#include <stdio.h>

long length(long card);
long first_numbers(long all_numbers);
void what_card(long card_number);

int main(void){
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while (number < 0);

    length(number);
    first_numbers(number);
    what_card(number);
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

long first_numbers(long all_numbers)
{
    int i = 0;
    while (all_numbers > 99)
    {
        all_numbers /= 10;
    }
    return all_numbers;
}

void what_card(long card_number)
{
    long 
    if(card_number == 1){

    }
}
