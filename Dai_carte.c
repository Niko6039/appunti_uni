#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZZO 52
#define SEMI 4
#define SCALA 13

void azzeraMazzo(int mazzo[SEMI][SCALA]);
void mischia_carte(int mazzo[SEMI][SCALA]);
void view_mazzo(int mazzo[SEMI][SCALA]);
void dai_carte();
int main()
{
    int mazzo[SEMI][SCALA];
    int cartePerGiocatore = 4;
    int numGiocatori = 4;
    char scelta;
    do
    {
        mischia_carte(mazzo);
        printf("Vuoi rigiocare? (n/y)\n");
        scanf(" %c", &scelta);
    } while (scelta == 'y' || scelta == 'Y');
    return 0;
}
//--------------------------------------------
void azzeraMazzo(int mazzo[SEMI][SCALA])
{
    for (int i = 0; i < SEMI; i++)
    {
        for (int j = 0; j < SCALA; j++)
        {
            mazzo[i][j] = 0;
        }
    }
}
//--------------------------------------------
void mischia_carte(int mazzo[SEMI][SCALA])
{
    srand(time(0));
    azzeraMazzo(mazzo);
    int riga, colonna;
    for (int i = 0; i < MAZZO; i++)
    {
        do
        {
            riga = rand() % (SEMI);
            colonna = rand() % (SCALA);
            // debug (view ogni tentativo che fa il programma)
            printf("riga:%d;colonna:%d; i=%d\n", riga, colonna, i);
        } while (mazzo[riga][colonna] != 0);
        mazzo[riga][colonna] = i;
    }
}

void view_mazzo(int mazzo[SEMI][SCALA])
{
    for (int i = 0; i < SEMI; i++)
    {
        switch (i)
        {
        case 0:
            printf("cuori  :");
            break;

        case 1:
            printf("quadri  :");
            break;

        case 2:
            printf("fiori  :");
            break;

        case 3:
            printf("picche  :");
            break;
        }

        for (int j = 0; j < SCALA; j++)
        {
            printf("%d - ", mazzo[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
}