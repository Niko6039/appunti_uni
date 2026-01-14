#include <stdio.h>

#define MAX_CANI 100
#define MAX_STR   20
#define MAX_VACCINAZIONI 10
#define MAX_ADOZIONI 5

typedef enum
{
	TAGLIA_PICCOLA = 0,
	TAGLIA_MEDIA = 1,
	TAGLIA_GRANDE = 2
} Taglia; 

typedef struct
{
  int giorno;
  int mese;
  int anno;
} Data;

typedef struct
{
  char azione[MAX_STR];	
  char principio_attivo[MAX_STR];
  char patologia[MAX_STR];	
  Data data_somministrazione;
} Vaccinazione;

typedef struct
{
  char via[MAX_STR];
  char citta[MAX_STR];
  int numero;
  int cap;	
} Indirizzo;


typedef struct
{
  char nome[MAX_STR];
  char cognome[MAX_STR];
  Indirizzo indirizzo;
} Adottante;


typedef struct
{
  Adottante adottante;
  Data dataAdozione;
} Adozione;


typedef struct
{
  char nome[MAX_STR];
  char razza[MAX_STR];
  
  Taglia taglia;
  int anni;
  
  Vaccinazione vaccinazioni[MAX_VACCINAZIONI];
  int numeroVaccinazioni;
  
  Adozione adozioni[MAX_ADOZIONI];
  int numeroAdozioni;
} Cane;

typedef struct 
{
  char nome[MAX_STR];
  Cane cani[MAX_CANI];
} Canile;

