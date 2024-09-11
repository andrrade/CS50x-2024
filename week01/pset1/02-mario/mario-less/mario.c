#include <cs50.h>
#include <stdio.h>

// declarando outras funções além da main;
void print_row(int spaces, int bricks);
void print_col(int height);

// função main (principal);
int main(void){
    int height; // declarando variável fora do loop;

    do{
        height = get_int("Height: "); // input para o usuário;
    } while(height < 1 || height > 8); // definindo valores inválidos;

    print_col(height); // chamando a função que imprime a pirâmide do mário;

}

// função que cria as linhas com os espaços e blocos;
void print_row(int spaces, int bricks) // passando os parâmetros 'qtde de espaços' e  'qtde de blocos' por linha;
{
    for (int i = 0; i < spaces; i++){
        printf(" "); // printando o espaço;
    }
    for(int i = 0; i < bricks; i++)
    {
        printf("#"); // printando o bloco;
    }
    printf("\n");
}

// função que cria as colunas;
void print_col(int height){ // tem como parâmetro a altura;
    for(int i = 0; i < height; i++){
        int spaces = height - i - 1;    // fórmula para fazer a pirâmide invertida, ex: height = 4;
                                        // espaços serão representados por '.';
                                        // spaces = height - i - 1;
                                        // ...# -> i = 0 -> spaces = 4 - 0 - 1 = 3;
                                        // ..## -> i = 1 -> spaces = 4 - 1 - 1 = 2;
                                        // .### -> i = 2 -> spaces = 4 - 2 - 1 = 1;
                                        // #### -> i = 3 -> spaces = 4 - 3 - 1 = 0;
        print_row(spaces, i + 1);
    }
}
