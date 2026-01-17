#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef enum
{
    informatica = 0,
    fisica = 1,
    matematica = 2,
    letteratura = 3
} SETTORE;

typedef struct
{
    int giorno;
    int mese;
    int anno;
} DATA;

typedef struct
{
    int codice_id;
    char titolo[50];
    char autore[50];
    DATA pubblicazione;
    SETTORE reparto;
} LIBRI;

void aggiungiLibro()
{
    // wb
    // rb
    FILE *file = fopen("indice.txt", "a"); // "a" sta per append: aggiunge senza cancellare
    if (file == NULL)
    {
        printf("Errore nell'apertura del file!\n");
        return;
    }

    LIBRI nuovo;
    nuovo.codice_id = rand() % 1000;

    printf("\n--- Inserimento nuovo libro (ID: %d) ---\n", nuovo.codice_id);
    printf("Titolo: ");
    scanf(" %[^\n]s", nuovo.titolo); // Legge anche gli spazi
    printf("Autore: ");
    scanf(" %[^\n]s", nuovo.autore);
    printf("Data (gg mm aaaa): ");
    scanf("%d %d %d", &nuovo.pubblicazione.giorno, &nuovo.pubblicazione.mese, &nuovo.pubblicazione.anno);
    printf("Reparto (0:Info, 1:Fis, 2:Mat, 3:Lett): ");
    int rep;
    scanf("%d", &rep);
    nuovo.reparto = (SETTORE)rep;

    // Scrittura su file in formato tabellare o riga singola
    fprintf(file, "%d|%s|%s|%d/%d/%d|%d\n",
            nuovo.codice_id, nuovo.titolo, nuovo.autore,
            nuovo.pubblicazione.giorno, nuovo.pubblicazione.mese, nuovo.pubblicazione.anno,
            nuovo.reparto);

    fclose(file);
    printf("Libro salvato con successo!\n");
}

void leggiLibri()
{
    FILE *file = fopen("indice.txt", "r");
    if (file == NULL)
    {
        printf("Nessun database trovato (indice.txt vuoto o inesistente).\n");
        return;
    }

    char riga[200];
    printf("\n--- Elenco Libri in Indice ---\n");
    while (fgets(riga, sizeof(riga), file))
    {
        printf("%s", riga);
    }
    fclose(file);
}

int main()
{
    srand(time(NULL));
    int scelta;

    do
    {
        printf("\n=== GESTIONE CANILE (LIBRI) ===\n");
        printf("1. Aggiungi un libro\n");
        printf("2. Leggi tutti i libri\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        switch (scelta)
        {
        case 1:
            aggiungiLibro();
            break;
        case 2:
            leggiLibri();
            break;
        case 0:
            printf("Chiusura...\n");
            break;
        default:
            printf("Scelta non valida.\n");
        }
    } while (scelta != 0);
    return 0;
}
