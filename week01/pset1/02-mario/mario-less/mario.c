#include <cs50.h>
#include <stdio.h>

int main(void)
{
    do{
        int height = get_int("Heigh: ");
    } while(height < 1 || height > 8);

}
