#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    printf("%c", *s); // s[0]
    printf("%c", *(s + 1)); // s[1]
    printf("%c\n", *(s + 2)); // s[2]
}
