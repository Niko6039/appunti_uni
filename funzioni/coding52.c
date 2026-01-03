//Data serie N di voti (dal 4 al 10) 
//determinare la media, mostrare in 
//output il risultato e dire se 
//l'alunno è promosso o bocciato.
//Funzioni da usare:
//caricaVettore
//calcolaMedia
//visualizzaRisultati

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 10
void stampa(int v[], int num){
    for(int i=0; i<num; i++){
        printf("%d ", v[i]);

    }
}
void alunno1(int v[], int num){
 //Alunno promosso 
    for(int i=0; i<num; i++){
        v[i] =(rand() % 4) + 6;
    }
}

void alunno2(int v[], int num){
    //Alunno bocciato 
    for(int i=0; i<num; i++){
        v[i] = rand() % 4 + 1;
    }
}

void media(int v[], int num){
    int somma = 0;
    for(int i=0; i<num; i++){
        somma += v[i];
    }
    float media = somma / num;
    printf("Media: %.2f\n", media);
}
int main(){
    int voti[n];
    int scelta;
    srand(time(NULL));
    printf("Scelta:\n1)Andrea\n2)Bobn\n");
    scanf("%d", &scelta);
    if(scelta == 1){
        alunno1(voti, n);
        
    }else if (scelta == 2){
        alunno2(voti, n);
    }
    stampa(voti, n);
    media(voti, n);
    return 0;
}