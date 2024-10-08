#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("X: ");
    int y = get_int("Y: ");
    printf("&i + &i = &i\n", x, y, x + y);
}
