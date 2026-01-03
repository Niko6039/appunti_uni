//[minim — Scrivere una funzione Che, ricevuti in ingresso due numeri interi, restituisca il valore
// minimo. Utilizzare Ia funzione per visualizzare il minimo di ciascuna delle seguenti coppie di
// valori: (45, 70), (32, -11), (0, 0).
#include <stdio.h>

int min(int x, int y)
{
    int sol;
    if (x < y)
    {
        sol = x;
    }
    else if (x > y)
    {
        sol = y;
    }
    else
    {
        sol = x;
        printf("I due numeri sono uguali (%d)\n", x);
    }
    return sol;
}

int main()
{
    printf("Min tra 45 e 70: %d \n", min(45, 70));
    printf("Min tra 32 e -11: %d\n", min(32, -11));
    printf("Min tra 0 e 0: %d\n", min(0, 0));
    return 0;
}