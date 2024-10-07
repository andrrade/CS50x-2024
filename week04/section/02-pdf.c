// #include <cs50.h>
// #include <stdio.h>
// #include <stdint.h>

// int main(int argc, string argv[])
// {
//     // TODO: Check first four bytes in given file
//     string filename = argv[1];
//     FILE *f = fopen(filename, "r");
//     uint8_t buffer[4]; // right size of value to use
//     int blocks_read = fread(buffer, 1, 4, f);

//     for (int i = 0; i < 4; i++)
//     {
//         printf("%i\n", buffer[i]);
//     }
//     printf("Blocks read: %i\n", blocks_read);
//     fclose(f);
// }

#include <cs50.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, string argv[])
{
    // Verifica se o número correto de argumentos foi passado
    if (argc != 2)
    {
        printf("Uso: ./pdf <arquivo>\n");
        return 1;
    }

    // Abre o arquivo
    string filename = argv[1];
    FILE *f = fopen(filename, "r");

    // Verifica se o arquivo foi aberto com sucesso
    if (f == NULL)
    {
        printf("Erro ao abrir o arquivo: %s\n", filename);
        return 1;
    }

    // Lê os primeiros 4 bytes do arquivo
    uint8_t buffer[4];
    int blocks_read = fread(buffer, 1, 4, f);

    // Verifica se foram lidos 4 bytes
    if (blocks_read != 4)
    {
        printf("Erro ao ler o arquivo ou arquivo muito pequeno.\n");
        fclose(f);
        return 1;
    }

    // Verifica se o arquivo é um PDF comparando os bytes com %PDF
    if (buffer[0] == 37 && buffer[1] == 80 && buffer[2] == 68 && buffer[3] == 70) // 37 = '%', 80 = 'P', 68 = 'D', 70 = 'F'
    {
        printf("O arquivo é um PDF :)\n");
    }
    else
    {
        printf("O arquivo não é um PDF :(\n");
    }

    // Exibe os primeiros 4 bytes
     for (int i = 0; i < 4; i++)
    {
        printf("%i\n", buffer[i]);
    }

    // Exibe a qtde de blocos/bytes lidos:
    printf("Blocks read: %i\n", blocks_read);
    // Fecha o arquivo
    fclose(f);

    return 0;
}
