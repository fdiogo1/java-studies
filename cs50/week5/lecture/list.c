#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = (int*) calloc(3, sizeof(int));

    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    int *tmp = realloc(list, 4 * sizeof(int)); // the realloc makes a copy of "list" to "tmp", adjusting the size.

    if (tmp == NULL) // if there isn't space enough in memory
    {
        free(list);
        return 1;
    }

    list = tmp;

    tmp[3] = 4;

    list = tmp;

    for (int i = 0; i < 4; i++)
    {
        printf("%d\n", *(list + i));
    }

    free(list); // it could be free(tmp) also, because the two pointers are pointing to the same memory.
    list = NULL;
    return 0; // echo $? to check
}