#include <stdio.h>

#define DIM 10

void stampa(char *puntatori[]){
    printf("La parola finale e': ");
    for (int i = 0; i < DIM; i++) {
        printf("%c", *puntatori[i]);
    }
    printf("\n");
}

void leggi_caratteri(char *punt[], char car[]){
    printf("Inserisci %d caratteri:\n", DIM);
    for (int i = 0; i < DIM; i++) {
        scanf(" %c", &car[i]);
        punt[i] = &car[i];
    }
}

int main() {
    char array_car[DIM]; 
    char *puntatori[DIM];

    leggi_caratteri(puntatori, array_car);
    stampa(puntatori);
    
    return 0;
}