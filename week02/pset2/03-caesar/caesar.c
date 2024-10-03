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

    string key = argv[1];

    for (int i = 0; i < strlen(key); i++)
    {
        if(!isdigit(key[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key_num = atoi(key);

    string text = get_string("Plaintext: ");

    for (int i = 0; i < strlen(text); i++)
    {
        if(isalpha(text[i]))
        {
            string cypher = (text[i] + key_num) % 26;
            if(isupper(text[i])) {
                cypher += cypher;
            }
            else {
                cypher += cypher;
            }
        }
    }

}
