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
