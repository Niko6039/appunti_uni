#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MAX 15

void casuale(int *p)
{
    int x = 10;
    for (int i = 0; i < MAX; i++)
    {
        x = (rand() % 41) + 10;
        *(p + i) = x;
        printf("%d ", *(p + i));
    }
}

int minpari(int *p)
{
    int min = 50;
    for (int i = 0; i < MAX; i++)
    {
        if ((*(p + i)) % 2 == 0)
        {
            if (*(p + i) < min)
            {
                min = *(p + i);
            }
        }
    }
}

int media(int *p, bool scelta)
{
    int ris;
    if (scelta)
    {
        // pari
    }
    else
    {
        // dispari
    }
    return ris;
}

int main()
{
    srand(time(NULL));
    int array[MAX];
    int *p = &array[0];
    casuale(p);
    int mPari = media(p, 1);    // media pari
    int mDispari = media(p, 0); // media dispari
    printf("\nil minimo e' %d", minpari(p));
}