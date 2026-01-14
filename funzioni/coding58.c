// Scrivere un programma in C che genera una matrice (NxN) e:
//  • Calcola la media globale di C
//     ok                            ok
//  • Calcola la somma delle righe, colonne, diagonale principale,
// diagonale secondaria
//  • Calcola la media delle righe, colonne, diagonale principale,
// diagonale secondaria
//  • La matrice SCARTO (NxN) che contiene per ogni elemento lo
// scarto di ogni elemento della matrice C rispetto alla sua media globale

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void casualeMatrice(int m[][N])
{
    printf("------------MATRICE CASUALE------------\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            m[i][j] = rand() % 100;
            printf("%02d ", m[i][j]);
        }
        printf("\n");
    }
}

void sommaRighe(int m[N][N], int som[N])
{
    int x = 0;
    printf("------------SOMMA RIGHE------------\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            x = m[i][j] + x;
            if (j == N - 1)
            {
                som[i] = x;
                printf("Riga %d: %d\t", i + 1, som[i]);
                if ((i + 1) % 2 == 0)
                {
                    printf("\n");
                }
            }
        }
    }
}

void sommaColonne(int m[N][N], int som[N])
{
    int x = 0;
    printf("------------SOMMA COLONNE------------\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            x = m[j][i] + x;
            if (j == N - 1)
            {
                som[i] = x;
                printf("Colonna %d: %d\t", i + 1, som[i]);
                if ((i + 1) % 2 == 0)
                {
                    printf("\n");
                }
            }
        }
    }
}

void sommaDiagonale(int m[N][N], int som[N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
        }
    }
}
int main()
{
    int matrice[N][N];
    int righe[N], colonne[N], diPrincipale[N];
    casualeMatrice(matrice);
    sommaRighe(matrice, righe);
    sommaColonne(matrice, colonne);
}