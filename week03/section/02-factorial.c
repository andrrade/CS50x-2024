#include <cs50.h>
#include <stdio.h>

int factorial(int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("n: ");
    }
    while(n < 0);

    printf("%i\n", factorial(n));
}
