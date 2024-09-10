#include <cs50.h>
#include <stdio.h>

long input(long number);
// long checkSum(long number);
// long checkCard(long number);

int main(void) {

}

long input(){
    long number;

    do {
        number = get_long("Number: ");
    } while (number <= 0);
}

// long checkSum(long number){

// }

// long checkCard(long number){

// }

