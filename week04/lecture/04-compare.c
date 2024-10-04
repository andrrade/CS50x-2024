#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{

    char *s = get_string("s: ");
    char *t = get_string("t: ");
    // p.s. s and t are adresses of the first character, no strings

    if (strcmp(s, t) == 0) // 0 = same; positive number = one comes before another; negative number = if the opposite is true.
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}
