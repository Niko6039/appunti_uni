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
    FILE *fp;

    //          aprire / crea il file
    //          I              tipologia whire in bit
    fp = fopen("sensori.txt", "wb");
    if (fp == NULL)
    {
        perror("Errore nell'apertura del file (scrittura)!\n");
        return 1;
    }

    SENSORE sens[MAX];
    for (int i = 0; i < MAX; i++)
    {
        //       array che si vuole usare
        //       I            stringa da memorizzare
        //       I            I      eventuale parametro
        sprintf(sens[i].cod, "%d", i + 1);

        sens[i].n = rand() % 31;

        sens[i].mis = (float)rand() / (float)(RAND_MAX / MAX);

        //     indirizzo di sens[i]
        //     I         dimensione del sens
        //     I         I              Num di elementi
        //     I         I              I    puntatore (dove dobbiamo scrivere)
        fwrite(&sens[i], sizeof(SENSORE), 1, fp);
    }
    // chiusira
    fclose(fp);

    printf("Salvataggio Completato!\n");
    //                        read bit
    fp = fopen("sensori.txt", "rb");
    // controllo errore
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
