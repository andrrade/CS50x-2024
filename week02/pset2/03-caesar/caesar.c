#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Verificando se todos os caracteres da key são dígitos
    for (int i = 0; i < strlen(key); i++) {
        if (!isdigit(key[i])) {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convertendo a key para número
    int key_num = atoi(key);

    // Solicitando o texto do usuário
    string text = get_string("Plaintext: ");

    printf("Ciphertext: ");

    // Criptografando o texto
    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            // Para letras maiúsculas
            if (isupper(text[i])) {
                printf("%c", (text[i] - 'A' + key_num) % 26 + 'A');
            }
            // Para letras minúsculas
            else if (islower(text[i])) {
                printf("%c", (text[i] - 'a' + key_num) % 26 + 'a');
            }
        }
        else {
            // Se não for letra, imprime o caractere sem alteração
            printf("%c", text[i]);
        }
    }

    printf("\n");
    return 0;
}
