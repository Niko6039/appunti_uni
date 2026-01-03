#include<stdio.h>

void sottoprogramma(int * v){
    int i;
    
    for(i = 0; i<= 10 ; i++)
    {
    	printf("%d\n",*(v+i));
	}
}


void main () {
int mioVettore[] ={3,5,7,9,4,1,0,6,2,10};
sottoprogramma(mioVettore);
}

