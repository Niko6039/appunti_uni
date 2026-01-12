#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Definizioni di base ---

typedef struct
{
    char nome[50];
    char cognome[50];
    char documento[20];
    char nazionalita[30];
} Passeggero;

typedef struct
{
    char modello[50];
    int capacita;
} Aeromobile;

typedef enum
{
    PROGRAMMATO,
    RITARDO,
    CANCELLATO,
    DECOLLATO,
    ATTERRATO
} StatoVolo;

// --- Relazione N:M (Passeggero - Volo) ---
// Per gestire la relazione "Prenotazione" tra molti passeggeri e molti voli
typedef struct NodoPasseggero
{
    Passeggero *info;
    struct NodoPasseggero *next;
} NodoPasseggero;

typedef struct
{
    char codice[10];
    char compagnia[50];
    char origine[50];
    char destinazione[50];
    StatoVolo stato;
    Aeromobile aereo;
    NodoPasseggero *lista_passeggeri;   // Elenco imbarcati
    NodoPasseggero *storico_passeggeri; // Storico completo
} Volo;

// --- Gerarchia Aeroporto (1:N) ---

// Nodo per gestire la lista di voli assegnati a un gate
typedef struct NodoVolo
{
    Volo *volo_assegnato;
    struct NodoVolo *next;
} NodoVolo;

typedef struct
{
    char codice_gate[10];
    NodoVolo *storico_voli; // Relazione Gate (1) -- (N) Volo
} Gate;

// Nodo per la lista di gate in un terminal
typedef struct NodoGate
{
    Gate info;
    struct NodoGate *next;
} NodoGate;

typedef struct
{
    char nome_terminal[20];
    NodoGate *lista_gate; // Relazione Terminal (1) -- (N) Gate
} Terminal;

// Nodo per la lista di terminal in un aeroporto
typedef struct NodoTerminal
{
    Terminal info;
    struct NodoTerminal *next;
} NodoTerminal;

typedef struct
{
    char nome_aeroporto[50];
    NodoTerminal *lista_terminal; // Relazione Aeroporto (1) -- (N) Terminal
} Aeroporto;

int main()
{
    printf("Sistema Aeroportuale inizializzato secondo lo schema ER.\n");
    return 0;
}