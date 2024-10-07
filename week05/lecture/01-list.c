#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    int *tmp = malloc(4 * sizeof(int));
    if (tmp == NULL)
    {
        free(list); // good practice
        return 1;
    }

    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i]; // copying into the temporary array whatever was in the old array
    }
    tmp[3] = 4;
    free(list);
    list = tmp; // list now point to the new chunk of memory

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    free(list);
    return 0;
}
