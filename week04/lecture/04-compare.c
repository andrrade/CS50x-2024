#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{

    char *s = get_string("s: ");
    char *t = get_string("t: ");
    // p.s. s and t are adresses of the first character, no strings

    if (strcmp(s, t))
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}
