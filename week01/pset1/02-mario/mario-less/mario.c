#include <cs50.h>
#include <stdio.h>

void print_row(int bricks);
void print_col(int height);

int main(void){
    int height;

    do{
        height = get_int("Height: ");
    } while(height < 1 || height > 8);

    print_col(height);

}

void print_row(int spaces, int bricks)
{
    for(int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    printf("\n");
}

void print_col(int height){
    for(int i = 0; i < height; i++){
        int space = height - i - 1;
        print_row(i + 1);
    }
}
