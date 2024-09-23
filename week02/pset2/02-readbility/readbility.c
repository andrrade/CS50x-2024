#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count(int type, string text, int length);

int main(void)
{
    string text = get_string("Text: ");
    int length = strlen(text, length);
    int letters = count_letters(text, length);
    int words = count_words(text, length);
    int sentences = count_sentences(text, length);
}

int count_letters(string text, int length)
{
    int letters = 0;
    for (int i = 0; i < length; i++)
    {
        if(isalpha(text[i]))
        {
            letters++;
        }

    }
    return letters;
}

int count_words(string text, int length)
{
    int words = 0;
     if(isspace(text[i]))
        {
            words++;
        }
    return words++;
}

int count_sentences(string text, int length)
{
    int sentences = 0;
     if(text[i] == "." || text[i] == "!" || text[i] == "?")
        {
            sentences++;
        }
        return sentences;
}
