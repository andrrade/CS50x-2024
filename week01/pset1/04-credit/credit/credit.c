#include <cs50.h>
#include <stdio.h>

long get_length(long number);
long first_numbers(long number);
void what_card(long number);
void get_sum(long number);

int main(void)
{
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while (number < 0);

    get_length(number);
    first_numbers(number);
    what_card(number);
    get_sum(number);
}

long get_length(long number)
{
    int i = 0;
    while (number > 0)
    {
        number /= 10;
        i++;
    }
    return i;
}

long first_numbers(long number)
{
    int i = 0;
    while (number > 99)
    {
        number /= 10;
    }
    return number;
}

void what_card(long number)
{
    int length = get_length(number);
    int firsts = first_numbers(number);
    if ((length == 15) && (firsts >= 34 && firsts <= 37))
    {
        printf("AMEX\n");
    }
    else if ((length == 16) && (firsts >= 51 && firsts <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((length >= 13 && length <= 16) && ((firsts / 10) == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

void get_sum(long number)
{
    long sum = 0;
    bool troca = false;
    while (number > 0)
    {
        long digit =
        number % 10;
        number /= 10; // last digit

        if(troca)
        {
            digit *= 2;
            if (digit > 9) // Se o resultado for maior que 9, some os dígitos individuais
            {
                digit = (digit % 10) + (digit / 10);
            }
        }
        sum += digit;
        troca = !troca;
    }


    printf("Sum = %li\n", sum);
}
