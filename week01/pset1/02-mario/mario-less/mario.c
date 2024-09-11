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
        int spaces = 0;            // Mantemos o espaço sempre zero para alinhar à esquerda
        int bricks = height - i;   // O número de blocos diminui a cada linha
        print_row(spaces, bricks);
    }
}

void print_row(int spaces, int bricks)
{
    // Imprime espaços (sempre zero neste caso)
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
