#include <cs50.h>
#include <stdio.h>

int main(void) {
    long number;

    do {
        number = get_long("Number: ");
    } while (number <= 0);

    int length = 0;
    long temp = number;
    while (temp > 0) {
        temp /= 10;
        length++;
    }

    // Verifica o comprimento e o prefixo
    if (length < 13) {
        printf("INVALID\n");
    } else if ((length >= 13 && length <= 16) && (number / 1000000000000 == 34 || number / 1000000000000 == 37)) {
        printf("AMEX\n");
    } else if (length == 16 && (number / 100000000000000 >= 51 && number / 100000000000000 <= 55)) {
        printf("MASTERCARD\n");
    } else if (length == 15 && (number / 10000000000000 == 4)) {
        printf("VISA\n");
    } else {
        printf("INVALID\n");
    }
}
