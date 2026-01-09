#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CANI 100
#define MAX_STR 50
#define MAX_VAC 10

typedef enum
{
    taglia_piccola = 0,
    taglia_media = 1,
    taglia_media = 2
} TAGLIA;

typedef struct
{
    int giorno;
    int mese;
    int anno;
} DATA;

typedef struct
{
    char vacciano[MAX_STR];
    char principio_attivo[MAX_STR];
    char patologia[MAX_STR];
    DATA data_somminastrazioen;
} VACCINAZIONE;

typedef struct
{
    char nome[MAX_STR];
    char cognome[MAX_STR];
} ADOTTANTE;

typedef struct
{
    ADOTTANTE adottante;
    char via[MAX_STR];
    char citta[MAX_STR];
} ADORZIONE;

typedef struct
{
    char nome[MAX_STR];
    char razza[MAX_STR];
    // int se diamo un numer tra 0 e 2 s
    TAGLIA taglia;
    int anni;
    //
    VACCINAZIONE vaccinazioni[MAX_VAC];
} CANE;

typedef struct
{
    CANE cani[MAX_CANI]
} CANILE;
