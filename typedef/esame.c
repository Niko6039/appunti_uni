// fai un programma che simuli una macchianetta
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX 10
#define MAXNOME 50

typedef struct
{
    char nome[MAXNOME];
    float prezzo;
} prodotto;

int riempiMacchinetta(prodotto prd[])
{
    int sc = 1;
    int i = 0;
    printf("Aggiungi i tuoi prodotti:\n");

    for (i = 0; i < MAX && sc == 1; i++)
    {
        printf("\nProdotto %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", prd[i].nome);

        printf("Prezzo: ");
        scanf("%f", &prd[i].prezzo);

        printf("Vuoi continuare? \n(1 -> si | 0 -> no): ");
        scanf("%d", &sc);
    }
    return i;
}

void viewMacchinetta(prodotto prd[], int n)
{
    char nome[MAXNOME];
    // nome[i] = prd[i].nome;
    for (int i = 0; i < n; i++)
    {

        char *p = prd[i].nome;

        int j = 0;

        while (*(p + j) != '\0')
        {
            nome[j] = *(p + j);
            j++;
        }
        nome[j] = '\0';

        /*
        for (int j = 0; *(i + p) != '\0'; i++)
        {
            nome[j] = *(p + j);
        }*/

        printf("Prodotto %d\n", i + 1);
        printf("Nome: %s\n", nome);
        printf("Prezzo: %.2f", prd[i].prezzo);
    }
}

int main()
{
    prodotto prod[MAX];
    int count = riempiMacchinetta(prod);
    viewMacchinetta(prod, count);

    return 0;
}