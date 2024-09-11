#include <cs50.h>
#include <stdio.h>

void print_row(int length);

int main(void)
{
    int height;
    do{
        height = get_int("Heigh: ");
    } while(height < 1 || height > 8);

    print_row(height);
}

void print_row(int length);
