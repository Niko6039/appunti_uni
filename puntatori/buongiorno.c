#include <stdio.h>
#define lunghezza 11

void stampa1(char *p){
    for (int i = 0; *(p + i) != '\0'; i++){
        printf("%c", *(p + i)); 
    }
    printf("\n");
}

void stampa2(char v[], int dimensione){
    for(int i = 0; i < dimensione; i++){
        printf("%c", v[i]); 
    }
    printf("\n");
}

int main(){
    char part1[] = "Buongiorno!";
    
    char *p = &part1[0];
    stampa1(p);
    
    stampa2(part1, lunghezza);
    
    return 0;
}