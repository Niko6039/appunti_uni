#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void casuale(int v[])
{
    for (int i = 0; i < MAX; i++)
    {
        v[i] = rand() % 10 + 1;
    }
}

void ordineVet(int v[], int ord[])
{
    // 1. Copia gli elementi di v in ord
    for (int i = 0; i < MAX; i++)
    {
        ord[i] = v[i];
    }

    // 2. Ordina il vettore ord (Bubble Sort)
    int temp;
    for (int i = 0; i < MAX - 1; i++)
    {
        for (int j = 0; j < MAX - i - 1; j++)
        {
            if (ord[j] > ord[j + 1])
            {
                temp = ord[j];
                ord[j] = ord[j + 1];
                ord[j + 1] = temp;
            }
        }
    }
}

void stampaVettore(int v[])
{
    for (int i = 0; i < MAX; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main()
{
    int v[MAX];
    int ord[MAX];

    srand(time(NULL));

    casuale(v);
    ordineVet(v, ord);

    printf("Vettore originale (v):  ");
    stampaVettore(v);

    printf("Vettore ordinato (ord): ");
    stampaVettore(ord);

    return 0;
}