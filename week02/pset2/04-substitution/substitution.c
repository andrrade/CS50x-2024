#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_valid_key(string key);

int main(int argc, string argv[])
{
    // Verifica se o número correto de argumentos foi passado e se a chave tem 26 caracteres
    if (argc != 2 || strlen(argv[1]) != 26)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Verifica se a chave é válida (somente letras e sem duplicatas)
    string key = argv[1];
    if (!is_valid_key(key))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
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
                // Substitui pela letra correspondente da chave (maiuscula)
                printf("%c", toupper(key[text[i] - 'A']));
            }
            // Para letras minúsculas
            else if (islower(text[i]))
            {
                // Substitui pela letra correspondente da chave (minúscula)
                printf("%c", tolower(key[text[i] - 'a']));
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

// Função para verificar se a chave é válida (26 caracteres únicos e alfabéticos)
bool is_valid_key(string key)
{
    // Verifica se todos os caracteres são letras e se não há duplicatas
    int seen[26] = {0}; // Array para rastrear letras já vistas

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            return false; // Não é uma letra
        }

        int index = toupper(key[i]) - 'A'; // Índice da letra no alfabeto
        if (seen[index])
        {
            return false; // Letra repetida
        }

        seen[index] = 1; // Marca a letra como vista
    }

    return true; // Chave válida
}
