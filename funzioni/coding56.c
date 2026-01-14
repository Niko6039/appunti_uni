#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define MIN 1
#define MAX 50

void inizializzaVettoreCasuale(int v[], int min, int max);
void stampaVettore(const char *messaggio, const int v[], int dimensione);
void swap(int *a, int *b);
int partition(int v[], int low, int high, int pivotIndex);

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int v[], int low, int high, int pivotIndex)
{
    swap(&v[pivotIndex], &v[high]);
    int pivot = v[high];

    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (v[j] <= pivot)
        {
            i++;
            swap(&v[i], &v[j]);
        }
    }

    swap(&v[i + 1], &v[high]);

    return (i + 1);
}

void inizializzaVettoreCasuale(int v[], int min, int max)
{
    for (int i = 0; i < N; i++)
    {
        v[i] = min + rand() % (max - min + 1);
    }
}

void stampaVettore(const char *messaggio, const int v[], int dimensione)
{
    printf("%s [", messaggio);
    for (int i = 0; i < dimensione; i++)
    {
        printf("%d%s", v[i], (i < dimensione - 1) ? ", " : "");
    }
    printf("]\n");
}

int main()
{
    int vettore[N];

    srand(time(NULL));

    inizializzaVettoreCasuale(vettore, MIN, DIMARRAY);
    stampaVettore("Vettore iniziale:", vettore, N);

    int indice_pivot_iniziale = rand() % N;
    int valore_pivot = vettore[indice_pivot_iniziale];

    printf("\nPosizione pivot scelta casualmente (indice): %d\n", indice_pivot_iniziale);
    printf("Valore pivot: %d\n", valore_pivot);

    printf("\n--- Avvio Partizionamento ---\n");

    int indice_pivot_finale = partition(vettore, 0, N - 1, indice_pivot_iniziale);

    stampaVettore("Vettore partizionato:", vettore, N);

    printf("\nRisultato:\n");
    printf("Pivot (%d) posizionato all'indice %d\n", valore_pivot, indice_pivot_finale);
    printf("Partizione Sinistra (elementi <= %d)\n", valore_pivot);
    printf("Partizione Destra (elementi > %d)\n", valore_pivot);

    return 0;
}