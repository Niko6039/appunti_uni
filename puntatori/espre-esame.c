#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h> // Necessaria per toupper

#define COLONNE 9
#define RIGHE ((COLONNE / 2) + 1)

// Popola la matrice con numeri casuali (es. 1-10)
void casuale(int *p)
{
    for (int i = 0; i < RIGHE; i++)
    {
        for (int j = 0; j < COLONNE; j++)
        {
            // Formula corretta: (riga * totale_colonne) + colonna
            *(p + (i * COLONNE) + j) = rand() % 10 + 1;
        }
    }
}

// Visualizza la tabella con le coordinate
void viewTabella(int *p)
{
    printf("\n    "); // Spazio per allineamento
    for (int j = 0; j < COLONNE; j++)
    {
        printf("%d  ", j + 1); // Intestazione numerica (1, 2, 3...)
    }
    printf("\n");

    for (int i = 0; i < RIGHE; i++)
    {
        printf("%c |", 'A' + i);
        for (int j = 0; j < COLONNE; j++)
        {
            int valore = *(p + (i * COLONNE) + j);

            // Se il valore è 0, mostriamo una 'X' (barca colpita), altrimenti il numero
            if (valore == 0)
                printf(" X ");
            else
                printf("%2d ", valore);
        }
        printf("\n");
    }
}

int main()
{
    char ch = 'y', scelta1;
    int scelta2;
    int v[RIGHE][COLONNE];
    int *p = &v[0][0];

    srand(time(NULL));
    casuale(p); // Genera la tabella una volta all'inizio

    do
    {
        viewTabella(p);

        printf("\nInserisci coordinate barca (es. A1): ");
        if (scanf(" %c%d", &scelta1, &scelta2) == 2)
        {
            // Convertiamo la lettera in indice (A=0, B=1...)
            int rigaIndex = toupper(scelta1) - 'A';
            // Convertiamo il numero in indice (1=0, 2=1...)
            int colIndex = scelta2 - 1;

            // Controllo se le coordinate sono valide
            if (rigaIndex >= 0 && rigaIndex < RIGHE && colIndex >= 0 && colIndex < COLONNE)
            {
                printf("Hai colpito la cella %c%d!\n", toupper(scelta1), scelta2);
                *(p + (rigaIndex * COLONNE) + colIndex) = 0; // Segniamo il colpo con lo zero
            }
            else
            {
                printf("Coordinate non valide!\n");
            }
        }

        printf("\nVuoi continuare? (y/n): ");
        scanf(" %c", &ch);
    } while (ch != 'n' && ch != 'N');

    printf("Grazie per aver giocato!\n");
    return 0;
}