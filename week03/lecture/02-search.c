#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    string s = get_string("String: ");
    for(int i = 0; i < 6; i++)
    {
        if(strings[i] == s)
        {
            printf("Found\n");
            return 0;
        }
    }
    return 1;
}
