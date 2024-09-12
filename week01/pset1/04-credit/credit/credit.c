#include <cs50.h>
#include <stdio.h>

long get_length(long card);
long first_numbers(long all_numbers);
void what_card(long card_number);

int main(void){
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while (number < 0);

    get_length(number);
    first_numbers(number);
    what_card(number);
}

long get_length(long card)
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
    int length = get_length(card_number);
    int firsts = first_numbers(card_number);
    if ((length == 15) && (first_numbers >= 34 || first_numbers <= 37))
    {
        printf("AMEX\n");
    }
    else if ((length == 16) && (first_numbers >= 51 && first_numbers <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((length >= 13 && length <= 16) && ((first_numbers / 10) == 4))
    {
        printf("VISA\n");
    }
    else{
        printf("INVALID\n");
    }
}
