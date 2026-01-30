#include <stdio.h>
#include <ctype.h>
#include <string.h>

// --- Prototipi delle Funzioni ---
// L'uso dei prototipi permette di definire le funzioni dopo il main, migliorando la leggibilità.
void contaVocaliESpazi(const char *ptrFrase, int *pVocali, int *pSpazi);
void trasformaInMinuscolo(char *ptrFrase);
void traduciFarfalliano(const char *ptrFrase);
void pulisciBuffer();

int main() {
    char frase[256] = ""; // Array di caratteri per memorizzare la stringa
    int scelta;
    int nVocali = 0, nSpazi = 0;

    do {
        // --- Visualizzazione Menu ---
        printf("\n====================================");
        printf("\n       ANALIZZATORE DI TESTO        ");
        printf("\n====================================");
        printf("\n 1. Inserisci una nuova frase");
        printf("\n 2. Conta vocali e spazi (Puntatori)");
        printf("\n 3. Converti in minuscolo");
        printf("\n 4. Traduci in Codice Farfalliano");
        printf("\n 0. Esci");
        printf("\n------------------------------------");
        printf("\n Scelta: ");

        // Controllo validità input numerico
        if (scanf("%d", &scelta) != 1) {
            printf("\n[Errore] Inserire un numero valido.\n");
            pulisciBuffer();
            continue;
        }
        pulisciBuffer(); // Pulizia dopo scanf

        switch (scelta) {
            case 1:
                printf("\nInserisci la frase: ");
                fgets(frase, sizeof(frase), stdin);
                // Rimuove il carattere newline '\n' catturato da fgets
                frase[strcspn(frase, "\n")] = 0;
                printf(">> Frase acquisita con successo.\n");
                break;

            case 2:
                if (strlen(frase) == 0) {
                    printf("\n[!] Errore: Inserisci prima una frase (opzione 1).\n");
                } else {
                    // Passiamo l'indirizzo delle variabili per modificarle via puntatore
                    contaVocaliESpazi(frase, &nVocali, &nSpazi);
                    printf("\nRisultati Analisi:");
                    printf("\n- Numero di Vocali: %d", nVocali);
                    printf("\n- Numero di Spazi: %d\n", nSpazi);
                }
                break;

            case 3:
                if (strlen(frase) == 0) {
                    printf("\n[!] Errore: Frase vuota.\n");
                } else {
                    trasformaInMinuscolo(frase);
                    printf("\n>> Frase convertita: %s\n", frase);
                }
                break;

            case 4:
                if (strlen(frase) == 0) {
                    printf("\n[!] Errore: Frase vuota.\n");
                } else {
                    printf("\n>> Traduzione Farfallina: ");
                    traduciFarfalliano(frase);
                    printf("\n");
                }
                break;

            case 0:
                printf("\nChiusura del programma in corso...\n");
                break;

            default:
                printf("\n[!] Scelta non valida.\n");
        }
    } while (scelta != 0);

    return 0;
}

// --- Definizioni delle Funzioni ---

/**
 * Funzione che utilizza puntatori per restituire più di un valore al chiamante.
 * ptrFrase: puntatore costante alla stringa (sola lettura).
 * pVocali e pSpazi: puntatori agli interi definiti nel main.
 */
void contaVocaliESpazi(const char *ptrFrase, int *pVocali, int *pSpazi) {
    *pVocali = 0; // Reset dei valori tramite dereferenziazione
    *pSpazi = 0;

    while (*ptrFrase != '\0') {
        char corrente = tolower(*ptrFrase);
        if (corrente == 'a' || corrente == 'e' || corrente == 'i' || 
            corrente == 'o' || corrente == 'u') {
            (*pVocali)++;
        } else if (corrente == ' ') {
            (*pSpazi)++;
        }
        ptrFrase++; // Sposta il puntatore al prossimo carattere
    }
}

/**
 * Modifica la stringa originale trasformando ogni maiuscola in minuscola.
 */
void trasformaInMinuscolo(char *ptrFrase) {
    for (int i = 0; ptrFrase[i] != '\0'; i++) {
        ptrFrase[i] = tolower(ptrFrase[i]);
    }
}

/**
 * Traduce e stampa a video la versione farfallina della frase.
 */
void traduciFarfalliano(const char *ptrFrase) {
    for (int i = 0; ptrFrase[i] != '\0'; i++) {
        char c = ptrFrase[i];
        char m = tolower(c);

        if (m == 'a' || m == 'e' || m == 'i' || m == 'o' || m == 'u') {
            printf("%cf%c", c, m);
        } else {
            putchar(c);
        }
    }
}

/**
 * Pulisce il buffer di input (stdin) per evitare cicli infiniti 
 * o letture errate dopo lo scanf.
 */
void pulisciBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}