#include <stdio.h>
#include <cs50.h>

int main(void){
    float change;
    float m25 = 0.25;
    float m10 = 0.10;
    float m5 = 0.5;
    float m1 = 0.1;

    do{
        change = get_float("Change owed: ");
    }
    while(change <= 0);

    if(change % m25 == 0){
        
    }
}
