#include <cs50.h>
#include <stdio.h>

// Protótipos das funções
long input(void);
bool checkSum(long number);

int main(void) {
    // Obtém o número do usuário
    long number = input();

    // Verifica a validade do número
    bool valid = checkSum(number);

    // Exibe se o número é válido ou inválido
    if (valid) {
        printf("VALID\n");
    } else {
        printf("INVALID\n");
    }

    return 0;
}

// Função para ler o número do usuário
long input(void) {
    long number;
    do {
        number = get_long("Number: ");
    } while (number <= 0);
    return number;
}

// Função para calcular a soma de verificação e verificar validade
bool checkSum(long number) {
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

    // Verifica se a soma é válida (último dígito é 0)
    return (sum % 10 == 0);
}

void checkCard(long number){
int length = get_length(number);
    long prefix = get_prefix(number);

    if (!is_valid(number)) {
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
