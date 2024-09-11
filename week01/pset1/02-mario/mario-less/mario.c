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
        int spaces = height - i - 1; // Número de espaços diminui a cada linha
        int bricks = i + 1;          // Número de blocos aumenta a cada linha
        print_row(spaces, bricks);
    }
}

void print_row(int spaces, int bricks)
{
    // Imprime os espaços à esquerda
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }

    // Imprime os blocos
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    printf("\n");
}
