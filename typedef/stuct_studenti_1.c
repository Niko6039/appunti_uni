#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome_cognome[20];
    int numero_tessera;
    int matricola;
} studenti;

int main()
{
    studenti s1;
    char nome[20];

    printf("Nome e Cognome(char): ");
    scanf(" %s", &s1.nome_cognome);
    // strcpy(s1.nome_cognome, nome);

    printf("Numero Tessera(int): ");
    scanf("%d", &s1.numero_tessera);

    printf("Matricila(int): ");
    scanf("%d", &s1.matricola);

    // stampa
    //-------------------------------------------------
    printf("-------------\nStudente: %s\n", s1.nome_cognome);
    printf("Numero Tessera: %d\n", s1.numero_tessera);
    printf("Matricila: %d\n", s1.matricola);

    return 0;
}