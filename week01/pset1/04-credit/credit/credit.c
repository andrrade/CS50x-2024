#include <cs50.h>
#include <stdio.h>

// Declaração das funções
long get_length(long number);
long first_numbers(long number);
void what_card(long number);
bool get_sum(long number);

int main(void)
{
    long number;
    do
    {
        number = get_long("Number: "); // Solicita o número do cartão ao usuário
    }
    while (number < 0); // Verifica se o número é positivo

    get_length(number);   // Obtém a quantidade de dígitos do número
    first_numbers(number); // Obtém os primeiros dígitos do número

    get_sum(number);      // Calcula a soma para o algoritmo de Luhn

    if(get_sum(number)){
        what_card(number);    // Determina o tipo de cartão com base no número
    }
    else
    {
        prinf("INVALID");
    }
}

// Função para determinar o comprimento (número de dígitos) do cartão
long get_length(long number)
{
    int i = 0;
    while (number > 0) // Conta quantos dígitos há no número
    {
        number /= 10; // Remove o último dígito
        i++;
    }
    return i; // Retorna o comprimento
}

// Função para obter os primeiros dígitos do cartão
long first_numbers(long number)
{
    int i = 0;
    while (number > 99) // Reduz o número até restarem apenas os dois primeiros dígitos
    {
        number /= 10; // Remove o último dígito
    }
    return number; // Retorna os primeiros dígitos
}

// Função para identificar o tipo de cartão
void what_card(long number)
{
    int length = get_length(number); // Obtém o comprimento do número do cartão
    int firsts = first_numbers(number); // Obtém os dois primeiros dígitos

    // Verifica o tipo de cartão com base no comprimento e nos primeiros dígitos
    if ((length == 15) && (firsts >= 34 && firsts <= 37))
    {
        printf("AMEX\n");
    }
    else if ((length == 16) && (firsts >= 51 && firsts <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((length >= 13 && length <= 16) && ((firsts / 10) == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n"); // Caso nenhum tipo de cartão seja identificado
    }
}

// Função para calcular a soma dos dígitos usando o algoritmo de Luhn
bool get_sum(long number)
{
    long sum = 0; // Inicializa a soma
    bool troca = false; // Flag para alternar a multiplicação

    while (number > 0)
    {
        long digit = number % 10; // Armazena o último dígito de number
        // Ex: se number for 1234, então 1234 % 10 resulta em 4
        number /= 10; // Remove o último dígito encontrado
        // Ex: se number for 1234, então 1234 / 10 resulta em 123

        if (troca) // Verifica se o dígito deve ser multiplicado
        {
            digit *= 2; // Multiplica o dígito por 2
            if (digit >= 10)
            {
                // Se o número contiver 2 casas decimais, acontece a soma entre os dígitos individuais
                digit = (digit % 10) + (digit / 10);
                // Ex: se digit for 14, 14 % 10 resulta em 4 (último)
                // e 14 / 10 resulta em 1 (primeiro)
                // Esta verificação é apenas para números de duas casas decimais,
                // pois o maior número possível é 18 (9 * 2)
            }
        }
        sum += digit; // Adiciona o dígito (ou a soma dos dígitos) à soma total
        troca = !troca; // Alterna a flag para o próximo dígito
    }

    return (sum % 10 == 0); // Return true if the total sum modulo 10 is 0 (valid), otherwise false (invalid)
}
