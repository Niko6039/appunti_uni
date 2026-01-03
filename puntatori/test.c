#include <stdio.h>

int main() {
    // Dichiarazione delle variabili
    int x = 10;
    int *ptr;   // Dichiara un puntatore a int (puntatore a intero)

    // Assegna l'indirizzo di memoria della variabile 'x' al puntatore 'ptr'
    ptr = &x;

    // Visualizza il valore e l'indirizzo di memoria
    printf("Value of x: %d\n", x);          // Mostra il valore contenuto in x (10)
    printf("Address of x: %px\n", &x);       // Mostra l'indirizzo di memoria di x
    printf("Pointer ptr: %p\n", ptr);       // Mostra il valore del puntatore (che è l'indirizzo di x)
    printf("Value via pointer: %d\n", *ptr); // Mostra il valore puntato da ptr (usa l'operatore di deferenziazione *)

    
    // Modifica il valore di 'x' attraverso il puntatore
    *ptr = 20;
    printf("New value of x: %d\n", x);      // Mostra il nuovo valore di x (20)
    printf("La dimensione del puntatore è: %zu bytes\n", sizeof(ptr)); // Mostra la dimensione del puntatore

    return 0;
}