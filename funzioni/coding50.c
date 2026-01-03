// Data una sequenza di 10 numeri interi ordinarli in modo  crescente e decrescente su due vettori differenti.

// OrdinaVettori_CRE_DECRE.c
// Soluzione che usa due funzioni una per ordinamento crescente e l’altra per quello decrescente

// OrdinaVettori_CRE_DECRE2.c
//  Soluzione che usa una funzione per entrambi gli ordinamento con variabile sentinella
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void stampa(int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
            printf("%d - ", v[i]);
        else
            printf("%d \n", v[i]);
    }
}

void randVet(int vet[], int n)
{
    for (int i = 0; i < n; i++)
    {
        vet[i] = rand() % 100 + 1;
    }
}

void copiaVet(int vet[], int ord[], int n)
{
    for (int i = 0; i < n; i++)
    {
        ord[i] = vet[i];
    }
}

void ordinatoCres(int vet[], int ord[], int n){
    copiaVet(vet, ord, n);
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
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

void ordinatoDecr(int vet[], int ord[], int n)
{
    copiaVet(vet, ord, n);
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (ord[j] < ord[j + 1])
            {
                temp = ord[j];
                ord[j] = ord[j + 1];
                ord[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int dim;
    int scelta;

    srand(time(NULL));

    do
    {
        printf("Inserisci un numero (Grandezza vettore, 0 per uscire): ");
        scanf("%d", &dim);
        if (dim > 0)
        {

            int vet[dim];
            int ord[dim];

            randVet(vet, dim);
            printf("Vettore originale:\n");
            stampa(vet, dim);

            printf("Scegli ordinamento:\n1) Ordinamento Crescente \n2) Ordinamento Decrescente\nScelta: ");
            scanf("%d", &scelta);

            if (scelta == 1)
            {
                ordinatoCres(vet, ord, dim);
                printf("--> Ordinato (Crescente):\n");
                stampa(ord, dim);
            }
            else if (scelta == 2)
            {
                ordinatoDecr(vet, ord, dim);
                printf("--> Ordinato (Decrescente):\n");
                stampa(ord, dim);
            }
            else
            {
                printf("Scelta non valida!\n");
            }
        }

    } while (dim != 0);

    printf("Programma terminato.\n");
    return 0;
}