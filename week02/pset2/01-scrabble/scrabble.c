#include <cs50.h>
#include <ctype.h> // isupper and islower
#include <stdio.h>
#include <string.h> // strlen

// Array to store Scrabble point values for each letter (A-Z)
int POINTS[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Function prototype for compute_score, which calculates the score of a word
int compute_score(string word);

int main(void)
{
    // Prompt player 1 to input a word
    string word1 = get_string("Player 1: ");

    // Prompt player 2 to input a word
    string word2 = get_string("Player 2: ");

    // Compute the score of the word entered by player 1
    int score1 = compute_score(word1);

    // Compute the score of the word entered by player 2
    int score2 = compute_score(word2);

    // Determine the winner by comparing the scores
    if (score1 > score2)
    {
        // Player 1 wins if their score is higher
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        // Player 2 wins if their score is higher
        printf("Player 2 wins!\n");
    }
    else
    {
        // If the scores are tied, it's a draw
        printf("Tie!\n");
    }
}

// Function to compute the Scrabble score of a given word
int compute_score(string word)
{
    // Initialize the score to 0
    int score = 0;

    // Loop through each character in the word
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        // Check if the character is an uppercase letter (A-Z)
        if (isupper(word[i]))
        {
            // Subtract 'A' to get the index of the letter in the alphabet (e.g., 'A' - 'A' = 0, 'B'
            // - 'A' = 1) // This index corresponds to the position in the POINTS array, where each
            // letter has its Scrabble value.
            score += POINTS[word[i] - 'A'];
        }
        // Check if the character is a lowercase letter (a-z)
        else if (islower(word[i]))
        {
            // Subtract 'a' to get the index of the letter in the alphabet (e.g., 'a' - 'a' = 0, 'b'
            // - 'a' = 1) This works similarly to the uppercase logic and allows us to access the
            // POINTS array for lowercase letters.
            score += POINTS[word[i] - 'a'];
        }
    }

    // Return the total score for the word
    return score;
}
