#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 10

void stampa(int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
        {
            printf("%d - ", v[i]);
        }
        else
        {
            printf("%d\n", v[i]);
        }
    }
}
void randV(int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        v[i] = rand() % 10 + 1; // Numeri piccoli (1-10) per leggere meglio l'esempio
    }
}
void copiaV(int v[], int c[], int n)
{
    for (int i = 0; i < n; i++)
    {
        c[i] = v[i];
    }
}

void sx(int v[], int sx[], int n)
{
    copiaV(v, sx, n);
    int primo = sx[0];
    for (int i = 0; i < n - 1; i++)
    {
        sx[i] = sx[i + 1];
    }

    sx[n - 1] = primo;
}

void dx(int v[], int dx[], int n)
{
    copiaV(v, dx, n);
    int ultimo = dx[n - 1];
    for (int i = n - 1; i > 0; i--)
    {
        dx[i] = dx[i - 1];
    }

    dx[0] = ultimo;
}

int main()
{
    int vetn[NUM];
    int vetRisultato[NUM];
    int scelta;

    srand(time(NULL));

    randV(vetn, NUM);

    printf("Vettore Originale:\n");
    stampa(vetn, NUM);

    printf("\nScegli operazione:\n1) Shift verso Sinistra (SX)\n2) Shift verso Destra (DX)\nScelta: ");
    scanf("%d", &scelta);

    if (scelta == 1)
    {
        sx(vetn, vetRisultato, NUM);
        printf("\n--> Risultato Shift SX:\n");
        stampa(vetRisultato, NUM);
    }
    else if (scelta == 2)
    {
        dx(vetn, vetRisultato, NUM);
        printf("\n--> Risultato Shift DX:\n");
        stampa(vetRisultato, NUM);
    }
    else
    {
        printf("Scelta non valida.\n");
    }

    return 0;
}