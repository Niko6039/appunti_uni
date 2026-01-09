#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RANDNUM 100
#define DIMARRAY 10

void stampa(int array[])
{
    for (int i = 0; i < DIMARRAY; i++)
    {
        if (array[i] > 0)
        {
            printf("%d", array[i]);
            //               si vede se la parte dopo del array è piena o no
            //               I            e  si vede se siamo al ultimo elemento
            if (array[i + 1] > 0 && i < (DIMARRAY - 1))
            {
                printf(" - ");
            }
        }
    }
    printf("\n");
}

void casuale(int array[])
{
    srand(time(NULL));
    for (int i = 0; i < DIMARRAY; i++)
    {
        // non è compreso lo 0 pero va dal 1 fino al 10 abbiamo sempre 10 num
        array[i] = rand() % RANDNUM + 1;
    }
}

void ordine(int array[], int pari[], int dispari[])
{
    int countP = 0, countD = 0;
    for (int i = 0; i < DIMARRAY; i++)
    {
        if ((array[i] % 2) == 1)
        {
            // dispari
            dispari[countD] = array[i];
            countD++;
        }
        else
        {
            // pari
            pari[countP] = array[i];
            countP++;
        }
    }
}

float media(int array[], int verifica)
{
    int somma = 0, cont = 0;
    float media = 0;
    for (int i = 0; array[i] > 0; i++)
    {
        if (verifica == 0)
        {
            // pari
            if (array[i] % 2 == 0)
            {
                somma += array[i];
                cont++;
            }
        }
        else if (verifica == 1)
        {
            // dispari
            if (array[i] % 2 == 0)
            {
                somma += array[i];
                cont++;
            }
        }
    }
    return media;
}

int main()
{
    int v[DIMARRAY];
    int pari[DIMARRAY] = {0};
    int dispari[DIMARRAY] = {0};
    casuale(v);
    stampa(v);
    ordine(v, pari, dispari);

    stampa(pari);
    stampa(dispari);

    // 0 se è pari 1 se è dispari
    printf("Media pari: %2.f\n", media(pari, 0));
    printf("Media pari: %2.f\n", media(dispari, 1));
}