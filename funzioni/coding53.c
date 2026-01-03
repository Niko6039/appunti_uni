//Scrivere un programma che riceve 10 numeri positivi. Alla fine dell’immissione il 
//programma stamperà un istogramma verticale che rappresenta i valori immessi 
//dall’utente.

// V[10] = {2,4,5,1,3,6,6,5,3,1}
// valoreMax = 6
#include <stdio.h>
#include <stdlib.h>

#define NUM_ELEMENTI 10

void stampaIstogramma(const int v[], int maxValore) {
    printf("\n--- Istogramma Verticale ---\n\n");

    for (int i = maxValore; i >= 1; --i) {
        printf("%d | ", i);
        
        for (int j = 0; j < NUM_ELEMENTI; ++j) {
            
            if (v[j] >= i) {
                printf(" * ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }

    printf("  +");
    for (int k = 0; k < NUM_ELEMENTI; ++k) {
        printf("---");
    }
    printf("\n");
    
    printf("    ");
    for (int k = 0; k < NUM_ELEMENTI; ++k) {
        printf(" %d ", k + 1);
    }
    printf("\n");
}

int main() {
    int numeri[NUM_ELEMENTI];
    int valoreMassimo = 0;

    printf("Inserisci %d numeri interi positivi:\n", NUM_ELEMENTI);

    for (int i = 0; i < NUM_ELEMENTI; ++i) {
        int input;
        
        do {
            printf("Numero %d: ", i + 1);
            if (scanf("%d", &input) != 1) {
                printf("Input non valido. Reinserisci.\n");
                while (getchar() != '\n'); 
                input = 0;
                continue;
            }

            if (input <= 0) {
                printf("Errore: Inserisci solo numeri positivi (> 0).\n");
            }
        } while (input <= 0);

        numeri[i] = input;
        
        if (input > valoreMassimo) {
            valoreMassimo = input;
        }
    }
    
    printf("\nAcquisizione completata. Valore massimo: %d\n", valoreMassimo);

    stampaIstogramma(numeri, valoreMassimo);

    return 0;
}