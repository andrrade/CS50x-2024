#include <cs50.h>
#include <stdio.h>

long input(void);
long checkSum(long number);
// long checkCard(long number);
// long print();

int main(void) {
    long number = input();
    long sum = checkSum(number);
    printf("Checksum: %ld\n", sum);
    printf("Checksum: %ld\n", valid);
    return 0;
}

long input(){
    long number;

    do {
      number = get_long("Number: ");
    } while (number <= 0);
    return number;
}

long checkSum(long number){
    long sum = 0;
    bool alternate = false;

    while (number > 0) {
        int digit = number % 10;
        number /= 10;

        if (alternate) {
            digit *= 2;
            if (digit > 9) {
                digit -= 9;
            }
        }

        sum += digit;
        alternate = !alternate;
    }

    return sum;
}

long checkCard(long sum){
    bool valid = false;
    if(sum % 10 == 0){
        valid = !valid;
    }
    return valid;
}

// long print (){

// }
