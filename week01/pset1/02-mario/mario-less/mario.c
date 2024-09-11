#include <cs50.h>
#include <stdio.h>

void print_row(int spaces, int bricks);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    } while (height < 1 || height > 8);

    for (int i = 0; i < height; i++)
    {
        int spaces = i;           // O número de espaços começa de 0 e aumenta
        int bricks = height - i;  // O número de blocos diminui
        print_row(spaces, bricks);
    }
}

void print_row(int spaces, int bricks)
{
    // Imprime espaços
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }

    // Imprime blocos
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    printf("\n");
}
