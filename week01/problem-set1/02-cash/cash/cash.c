#include <stdio.h>
#include <cs50.h>

int main(void){
    float change;
    float m25 = 0.25;
    float m10 = 0.10;
    float m5 = 0.5;
    float m1 = 0.1;
    int qtde = 0;

    do{
        change = get_float("Change owed: ");
    }
    while(change <= 0);

    do{
        if(change % m25 == 0){
           change = change/m25;
           qtde ++;
        }
        else{
            if(change % m10 == 0){
                change = change/m10;
                qtde++
            }
            else{
                if(change % m5 == 0){
                    change = change/m5;
                    qtde++
                }
                else{
                    if(change % m1 == 0){
                        change
                    }
                }
            }
        }
    } while(change != 0);
}
