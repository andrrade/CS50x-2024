#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>



int main(void)
{
    string text = get_string("Text: ");
    int length = strlen(text);
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);




}

int count(int type, string text, int length)
{
    for (int i = 0; i < length; i++)
    {
        if(isalpha(text[i]))
        {
            letters++;
        }
        if(isspace(text[i]))
        {
            words++;
        }
        if(text[i] == "." || text[i] == "!" || text[i] == "?")
        {
            sentences++;
        }
    }
}
