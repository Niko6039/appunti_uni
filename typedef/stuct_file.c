#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 30

typedef struct
{
    char cod[10];
    int n;
    float mis;
} SENSORE;

int main()
{
    srand(time(NULL));
    int n_random = MAX;
    FILE *fp;
    //
    fp = fopen("sensori.txt", "wb");
    if (fp == NULL)
    {
        perror("Errore nell'apertura del file (scrittura)!\n");
        return 1;
    }

    SENSORE sens[MAX];
    for (int i = 0; i < n_random; i++)
    {
        //          array         int   i + 1
        sprintf(sens[i].cod, "%d", i + 1);
        sens[i].n = rand() % 31;
        sens[i].mis = (float)rand() / (float)(RAND_MAX / MAX);
        //     indirizzo di sens[i],
        //               dimensione del sens
        //
        //
        fwrite(&sens[i], sizeof(SENSORE), 1, fp);
    }
    fclose(fp);
    printf("Salvataggio Completato!\n");
    fp = fopen("sensori.txt", "rb");
    if (fp == NULL)
    {
        perror("Errore nell'apertura del file (lettura)!\n");
        return 1;
    }
    SENSORE lettura;
    while (fread(&lettura, sizeof(SENSORE), 1, fp) == 1)
    {
        printf("Codice: %s - Num: %d - Misura: %.2f\n", lettura.cod, lettura.n, lettura.mis);
    }
    fclose(fp);
    return 0;
}
