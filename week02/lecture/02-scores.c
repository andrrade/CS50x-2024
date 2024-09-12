#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int scores[3]; // declara que o vetor terá 3 espaços na memória

    scores[0] = get_int("Score: "); // armazena o valor na primeira posição do vetor
    scores[1] = get_int("Score: "); // armazena o valor na segunda posição do vetor
    scores[2] = get_int("Score: "); // armazena o valor na terceira posição do vetor

    printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);
}
