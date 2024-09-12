#include <cs50.h>
#include <stdio.h>

int main(void)
{
    const int N;
    int scores[N]; // declara que o vetor terá 3 espaços na memória

    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: ");
    }
    printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / (float) N);
}
