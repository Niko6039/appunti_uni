#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CANI 100
#define MAX_STR 50
#define MAX_VAC 10

typedef enum
{
    TAGLIA_PICCOLA = 0,
    TAGLIA_MEDIA = 1,
    TAGLIA_GRANDE = 2
} TAGLIA;

typedef struct
{
    int giorno;
    int mese;
    int anno;
} DATA;

typedef struct
{
    char vaccino[MAX_STR];
    char principio_attivo[MAX_STR];
    char patologia[MAX_STR];
    DATA data_somministrazione;
} VACCINAZIONE;

typedef struct
{
    char nome[MAX_STR];
    char cognome[MAX_STR];
    char codice_fiscale[17]; // Aggiunta utile per identificare l'adottante
} ADOTTANTE;

typedef struct
{
    ADOTTANTE adottante;
    DATA data_adozione;
    char via[MAX_STR];
    char citta[MAX_STR];
} ADOZIONE;

typedef struct
{
    char nome[MAX_STR];
    char razza[MAX_STR];
    TAGLIA taglia;
    int anni;

    // gestione vaccini:
    VACCINAZIONE vaccinazioni[MAX_VAC];
    int num_vaccini; // Fondamentale: quanti vaccini ha fatto davvero?
    bool adottato;
    ADOZIONE info_adozione;
} CANE;

typedef struct
{
    CANE cani[MAX_CANI];
    int totale_cani; // Fondamentale: quanti cani ci sono nel canile?
} CANILE;