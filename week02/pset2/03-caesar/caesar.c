#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, int argv[])
{
    if (argc != 2){
        printf("Usage: ./caesar key\n")
    }

    key = argv[1];

    for (int i = 0; i < strlen(key); i++)
    {
        if(!isdigit(key[i]))
        {
            printf("Usage: ./caesar key\n");
        }
    }

    key = atoi(key);

    string text = get_string();
    string cipher;
    for (int i = 0; i < strlen(text); i++)
    {
        if(isalpha(text[i]))
        {
            if(isupper(text[i]))
            {
               cipher[i] = (text[i] + key) % 26
            }
            if(islower(text[i]))
            {
                'a' + key;
            }
        }
    }
}