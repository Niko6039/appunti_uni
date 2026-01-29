#include <stdio.h>
#include <stdlib.h>

void main()
{
    char *p_ch;
    char ch = 'A';
    char ch1 = 'B';
    char ch2;

    printf("L\'indirizzo di p che\': %p \n", &p_ch);
    p_ch = &ch1;
    printf("Il valore di p che\': %p \n", p_ch);
    printf("L'indirizzo di ch1 che\': %p \n", *p_ch);
    ch2 = *p_ch;
}