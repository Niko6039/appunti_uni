#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 10
#define maxrand 100

void casuale(int tuamadre[])
{
    srand(time(NULL));
    int x;
    for (int i = 0; i < max; i++)
    {
        // 0 fino a 99 (maxrand) => 1 fino a 100 (maxrand + 1)
        x = rand() % maxrand + 1;
        tuamadre[i] = x;
    }
}

void stampa(int tuamadre[])
{
    for (int i = 0; i < max; i++)
    {
        if (i != max - 1)
        {
            printf("%d - ", tuamadre[i]);
        }
        else
        {
            printf("%d \n", tuamadre[i]);
        }
    }
}

int main()
{
    int anna[max];
    casuale(anna);
    stampa(anna);
}