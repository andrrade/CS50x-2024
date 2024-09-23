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
            // formula = Ci = (Pi + key) % 26
            // convert ascii para index alfabeticos
            // shift alphabetic index usando a formula
            // converter o resultado para index
        }
    }
}
