#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

typedef enum
{
    farmacologica = 0,
    fisioterapia = 1,
    chirurgica = 2,
    diagnostica = 3
} TIPO;

typedef struct
{
    int giorno;
    int mese;
    int anno;
} DATA;

typedef struct
{
    TIPO tipologia;
    char descrizione[150];
    char nome_medico_prescrittore[50]; // Corretto refuso "medicio"
    DATA data_inizio;
    DATA data_fine;
} TERAPIA;

typedef struct
{
    char codice_fiscale[17]; // 16 caratteri + terminatore \0
    char nome[30];
    char cognome[30];
    char gruppo_sanguigno[4]; // Modificato a 4 per gestire "AB+" o "O-" + \0
    DATA data_nascita;
    TERAPIA terapie_prescritte[50];
    int numero_terapie; // Contatore per gestire l'array di terapie
} PAZIENTE;

typedef struct
{
    PAZIENTE pazienti[50];
    char nome[50];
    int numero_pazienti; // Contatore per i pazienti nel reparto
} REPARTO;

typedef struct
{
    PAZIENTE paziente;
    DATA data_accettazione;
    char motivo[100];
} RICEZIONE; // Rinominata da RICEVERE per coerenza semantica

typedef struct
{
    REPARTO reparti[10]; // Un ospedale ha più reparti
    char nome_ospedale[100];
    char indirizzo[100];
} OSPEDALE;

// Funzione di esempio per stampare i dati di un paziente
void stampaPaziente(PAZIENTE p)
{
    printf("Paziente: %s %s (%s)\n", p.nome, p.cognome, p.codice_fiscale);
    printf("Gruppo Sanguigno: %s\n", p.gruppo_sanguigno);
    printf("Data di Nascita: %02d/%02d/%d\n", p.data_nascita.giorno, p.data_nascita.mese, p.data_nascita.anno);
    printf("-------------------------------\n");
}

int main()
{

    return 0;
}