#include <cs50.h>
#include <stdio.h>

int main(void){
    char c= get_char("Do you agree? ");

    if(c == 'y'){
        printf("SIM");
    }
    else{
        if(c == 'n'){
            printf("NÃO");
        }
        else{
            printf("BURRO");
        }
    }
}
