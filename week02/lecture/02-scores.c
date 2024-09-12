// #include <cs50.h>
#include <stdio.h>

int main(void)
{
    int scores[3]; // declara que o vetor terá 3 espaços na memória

    int scores[0] = 72; // armazena o valor na primeira posição do vetor
    int scores[1] = 73; // armazena o valor na segunda posição do vetor
    int scores[2] = 33; // armazena o valor na terceira posição do vetor

    printf("Average: %f\n", (scores[1] + scores[2] + scores[3]) / 3.0);
}
