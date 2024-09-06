#include <stdio.h>
#include <cs50.h>

void meow(int n);

int main(void){
    for(int i = 0; i < 3; i++){
        meow();
    }
}

void meow(int n){
    printf("meow\n");
}
