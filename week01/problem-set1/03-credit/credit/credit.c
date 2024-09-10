#include <cs50.h>
#include <stdio.h>

long input(void);
long checkSum(long number);
// long checkCard(long number);
// long print();

int main(void) {
    long number = input();
}

long input(){
    long number;

    do {
      number = get_long("Number: ");
    } while (number <= 0);
    return number;
}

long checkSum(long number){
    ((number / 10) % 10) * 2
}

// long checkCard(long number){

// }

// long print (){

// }
