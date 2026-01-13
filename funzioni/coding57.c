// Scrivere un programmino in C che una volta caricato in modo
// random un vettore di 10 numeri interi chiede all’utente un
// numero intero a tre cifre. Gli indici corrispondenti alle cifre del
// numero intero dato in input dall’utente vengono azzerati. Il
// programma da in output il vettore modificato
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 99

void causale(int v[])
{
    for (int i = 0; i < max; i++)
    {
        v[i] = rand() % 100 + 1;
        printf("%d ", v[i]);
        if (i % 11 == 10)
        {
            printf("\n");
        }
    }
    printf("\n\n");
}

int main()
{
    srand(time(NULL));
    int array[max];
    causale(array);
    int x = 1;
    while (x != 0)
    {
        printf("Scegli un numero (digita 0 per uscire): ");
        scanf("%d", &x);
    }
}
