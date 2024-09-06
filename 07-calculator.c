#include <stdio.h>
#include <cs50.h>

int add(int a, int b);

int main(void){
    int x = get_float("x: ");
    int y = get_float("y: ");

    printf("%f\n", add(x, y));
}

int add(int a, int b){
    return a + b;
}
