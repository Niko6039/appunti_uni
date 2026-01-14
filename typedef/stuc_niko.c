#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define max 10
// aprire un file scriverci e poi leggerlo
typedef struct
{
    char cod[30];
    int n;
    float misura;
} SENSORE;

int main()
{
    srand(time(NULL));
    FILE *fl;
    int casuale;
    // nome del file e non creamo altri file, perche e' gia esistente
    //                         visto che queto file avra molti tipi di dati
    //                         gli mettiamo write bit
    fl = fopen("sensori.txt", "wb");
    // controliamo se ci sono erroro
    if (fl == NULL)
    {
        // perror si usa quando si vuole stampare un errore
        // se il programma e' perfettamente funzionante ma c'e' un problema di apertura del file:
        // questo messaggio verra segnato come un errore
        perror("Errore di apertura file!\n");
        return 1;
    }

    SENSORE sens[max];
    for (int i = 0; i < max; i++)
    {
        // stiamo assengando al sens[i].cod la stringa i + 1
        // questa non la stampera a video ma la memorizzera solo nel array
        sprintf(sens[i].cod, "%d", i + 1);

        // assengo a sens[i].n un numero casuale tra 1 e 30
        sens[i].n = rand() % 31;

        // assegno anche qui un nuemro casuale ma con la virgola
        sens[i].misura = (float)rand() / (float)(RAND_MAX / max);

        //
        fwrite(&sens[i], sizeof(SENSORE), 1, fl);
    }
    // file close
    fclose(fl);

    printf("Salvataggio riuscito!");

    fl = fopen("sensori.txt", "rb");
    if (fl == NULL)
    {
        perror("Errore di apertura file!\n");
        return 1;
    }

    SENSORE lettura;
    // Legge il file: passiamo l'indirizzo della variabile dove salvare i dati (&lettura),
    // specifichiamo la dimensione della struttura (sizeof), quanti elementi
    // leggere alla volta (1) e il puntatore al file (fl).
    while (fread(&lettura, sizeof(SENSORE), 1, fl))
    {
        printf("Codice: %s - Num: %d - Misura: %.2f \n", lettura.cod, lettura.n, lettura.misura);
    }
    fclose(fl);
    return 0;
}