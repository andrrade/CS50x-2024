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
        number % 10; // armazena o último dígito de number
        // Ex: se number for 1234, então 1234 % 10 resulta em 4
        number /= 10; // remove o último dígito encontrado
        // Ex: se number for 1234, então 1234 / 10 resulta em 123.

        if(troca)
        {
            digit *= 2;
            if (digit >= 10) // Se o número conter 2 casas decimais...
            {
                digit = (digit % 10) + (digit / 10); // soma o último e o primeiro dígito do número, respectivamente
            }
            // se digit for 14, 14 % 10 resulta em 4 (último)
            // se digit for 14, 14 / 10 resulta em 1 (em divisão inteira) (primeiro)
        }
        sum += digit;
        troca = !troca;
    }


    printf("Sum = %li\n", sum);
}
