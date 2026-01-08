#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define max 10
// aprire un file scriverci e poi leggerlo
typedef struct
{
    cod[30];
    int n;
    float mis;
} sensore;

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
    }

    sensore sens[max];
    for (int i = 0; i < max; i++)
    {
        }
    return 0;
}