//[minim031] Scrivere una funzione Che, ricevuti in ingresso tre numeri interi, restituisca il valore
// minimo. Utilizzare la funzione per visualizzare il minimo di ciascuna delle seguenti terne di
// valori: (12, 56, 230), (13, -13, 44), (0, 1, 2).
#include <stdio.h>

int min3(int x, int y, int z)
{
    int sol = 0;
    if (x < y && x < z)
    {
        // x
        sol = x;
    }
    else if (y < x && y < z)
    {
        // y
        sol = y;
    }
    else if (z < x && z < y)
    {
        // z
        sol = z;
    }
    else
    {
        // sono tutti uguali
        sol = x;
        printf("Le soluzione sono tutte uguali: \n");
    }
    return sol;
}

int main()
{
    printf("Il valore minore tra (12, 56, 230) e' il %d\n", min3(12, 56, 230));
    printf("Il valore minore tra (13, -13, 44) e' il %d\n", min3(13, -13, 44));
    printf("Il valore minore tra (0, 1, 2) e' il %d\n", min3(0, 1, 2));
    printf("Il valore minore tra (0, 0, 0) e' il %d\n", min3(0, 0, 0));
    return 0;
}