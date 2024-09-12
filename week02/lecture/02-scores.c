// Averages three numbers using array, a constant, and a helper function

#include <cs50.h>
#include <stdio.h>

// Constant
const int N;

// Prototype
float average(int length, int array[]);

int main(void)
{
    // Get scores
    int scores[N]; // declara que o vetor terá 3 espaços na memória
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: ");
    }

    // print Average
    printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / (float) N);
}
