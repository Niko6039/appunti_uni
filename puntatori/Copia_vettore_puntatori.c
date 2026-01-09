#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 30
int main()
{
    int v1[DIMARRAY];
    int v2[DIMARRAY];

    srand(time(NULL));

    printf("Array v1:\n");
    for (int i = 0; i < DIMARRAY; i++)
    {
        v1[i] = rand() % 30 + 1;
        if (i == DIMARRAY - 1)
        {
            printf("%d\n", v1[i]);
        }
        else
        {
            printf("%d - ", v1[i]);
        }
    }

    int *p = v1;
    for (int i = 0; i < DIMARRAY; i++)
    {
        v2[i] = *(p + i);
    }

    printf("\nArray v2 (Copiato tramite puntatore):\n");
    for (int i = 0; i < DIMARRAY; i++)
    {
        if (i == DIMARRAY - 1)
        {
            printf("%d\n", v2[i]);
        }
        else
        {
            printf("%d - ", v2[i]);
        }
    }
    return 0;
}