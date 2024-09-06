#include <stdio.h>
#include <cs50.h>

int main(void){
    do{
        n = get_int("Size: ");
    }
    while(n < 1);

    printf("\n");

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("#");
        }
        printf("\n");
    }
}
