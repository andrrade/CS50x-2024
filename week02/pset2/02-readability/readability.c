#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count(int type, string text);
int Liau(int letters, int words, int sentences);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count(1, text);
    int words = count(2, text);
    int sentences = count(3, text);
    int grade = Liau(letters, words, sentences);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }
}

int count(int type, string text)
{
    int counter = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (type == 1 && isalpha(text[i])) // Count letters
        {
            counter++;
        }
        else if (type == 2 && isspace(text[i - 1])) // Count words
        {
            counter++;
        }
        else if (type == 3 &&
                 (text[i] == '.' || text[i] == '!' || text[i] == '?')) // Count sentences
        {
            counter++;
        }
    }
    if (type == 2)
    {
        counter++; // Plus 1 to last word
    }
    return counter;
}

int Liau(int letters, int words, int sentences)
{
    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    index = round(index);

    return index;
}
