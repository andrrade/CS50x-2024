#include <cs50.h>
#include <stdio.h>

int main(void) {
    long number;

    do {
        number = get_long("Number: ");
    } while (number <= 0);

    // Calcula o comprimento do número
    int length = 0;
    long temp = number;
    while (temp > 0) {
        temp /= 10;
        length++;
    }

    // Verifica o comprimento e o prefixo
    // Obtemos o prefixo dos primeiros dígitos para comparação
    int prefix = number;
    while (prefix >= 100) {
        prefix /= 10;
    }

    if (length < 13 || length > 16) {
        printf("INVALID\n");
    } else if (length == 15 && (prefix == 34 || prefix == 37)) {
        printf("AMEX\n");
    } else if (length == 16 && (prefix >= 51 && prefix <= 55)) {
        printf("MASTERCARD\n");
    } else if ((length == 13 || length == 16) && (prefix / 10 == 4)) {
        printf("VISA\n");
    } else {
        printf("INVALID\n");
    }
}
