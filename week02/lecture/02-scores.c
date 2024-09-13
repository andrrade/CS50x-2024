// Averages three numbers using array, a constant, and a helper function

#include <cs50.h>
#include <stdio.h>

// Constant
const int N = 3; // Variável global

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

    // Print average
    printf("Average: %f\n", average(N, scores));
}

float average(int length, int array[])
{
    // Calculate average
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / (float) length;
}
