#include <cs50.h>
#include <stdio.h>

void print_row(int spaces, int bricks);

int main(void)
{
    int height;
    int spaces;
    spaces = height - 1;

    do{
        height = get_int("Heigh: ");
    } while(height < 1 || height > 8);

    for(int i = 0; i < height; i++){
        print_row(spaces, i + 1);
    }


}

void print_row(int spaces, int bricks){
    for(int i = 0; i < bricks; i++){
        printf("#");
    }
    printf("\n");
}
