#include <cs50.h>
#include <stdio.h>

void print_row(int bricks);

int main(void){
    int height;

    do{
        height = get_int("Height: ");
    } while(height < 1 || height > 8);

    print_row(height);
}

void print_row(int bricks);
{
    for(int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    printf("\n");
}
