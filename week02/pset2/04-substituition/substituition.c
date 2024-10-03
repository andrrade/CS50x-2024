#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Verifica se o número correto de argumentos foi passado
    if (argc != 2 || strlen(argv) != 26)
    {
        printf("Usage: ./substituition key\n");
        return 1;
    }

    // Verifica se a key contém apenas dígitos
    string letters = argv[1];
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(letters[i]))
        {
            printf("Usage: ./substituition key\n");
            return 1;
        }
    }

    // Solicita o texto a ser criptografado
    string text = get_string("Plaintext: ");

    printf("Ciphertext: ");

    // Criptografa o texto
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            // Para letras maiúsculas
            if (isupper(text[i]))
            {

            }
            // Para letras minúsculas
            else if (islower(text[i]))
            {
                
            }
        }
        else
        {
            // Se não for letra, imprime o caractere sem alteração
            printf("%c", text[i]);
        }
    }

    printf("\n");
    return 0;
}
