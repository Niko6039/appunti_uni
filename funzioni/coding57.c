#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 99

void stampa(int v[])
{
    printf("\n--- Stato attuale dell'array ---\n");
    for (int i = 0; i < MAX; i++)
    {
        if (v[i] == 0)
            printf("__ "); // Mostra uno spazio vuoto per i numeri cancellati
        else
            printf("%02d ", v[i]);

        if (i % 11 == 10)
            printf("\n");
    }
    printf("\n");
}

void causale(int v[])
{
    for (int i = 0; i < MAX; i++)
    {
        v[i] = rand() % 100 + 1;
    }
}

void cancella(int v[], int x)
{
    int trovati = 0;
    for (int i = 0; i < MAX; i++)
    {
        if (v[i] == x)
        {
            v[i] = 0;
            trovati++;
        }
    }
    if (trovati > 0)
        printf("\n[OK] Numero %d rimosso %d volte.\n", x, trovati);
    else
        printf("\n[!] Numero %d non trovato.\n", x);
}

int main()
{
    srand(time(NULL));
    int array[MAX];
    causale(array);

    int x = -1;
    while (x != 0)
    {
        stampa(array);
        printf("Scegli un numero da cancellare (0 per uscire): ");
        scanf("%d", &x);
        if (x != 0)
        {
            cancella(array, x);
        }
    }

    printf("Programma terminato.\n");
    return 0;
}