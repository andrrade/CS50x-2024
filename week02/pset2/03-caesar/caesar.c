#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, int argv[])
{
    if (argc != 2){
        printf("Usage: ./caesar key\n")
    }

    string key = argv[1];

    for (int i = 0; i < strlen(key); i++)
    {
        if(!isdigit(key[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key_num = atoi(key);

     string text = get_string("plaintext: ");
    printf("ciphertext: "); // Imprime o prefixo para o texto cifrado

    // Loop para cifrar cada caractere do texto
    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) { // Se o caractere é uma letra
            // Fórmula para cifrar: Ci = (Pi + key) % 26

            // Verifica se o caractere é maiúsculo ou minúsculo
            char offset = isupper(text[i]) ? 'A' : 'a';

            // Converte o caractere de ASCII para índice alfabético (0-25)
            int alphabetic_index = text[i] - offset;

            // Aplica o deslocamento com a fórmula do Cifra de César
            int shifted_index = (alphabetic_index + key_num) % 26;

            // Converte de volta para ASCII e imprime o caractere cifrado
            printf("%c", shifted_index + offset);
        } else {
            // Se não for uma letra, apenas imprime o caractere original
            printf("%c", text[i]);
        }
    }

    printf("\n"); // Nova linha após o texto cifrado
    return 0; // Sai do programa sem erro
}
