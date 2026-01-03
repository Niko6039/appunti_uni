#include <stdio.h>
int main(){
    int v[]= {9,5,6,7,10};

    int *p = v;
    printf("%d \n", *(p)); //9
    printf("%p \n", &(p));

    p++;
    printf("%d \n", *(p)); // 5
    printf("%p \n", &(p));

    p--;
    printf("%d \n", *(p)); // 9
    printf("%p \n", &(p));

    p = p + 2;
    printf("%d \n", *(p)); // 6
    printf("%p \n", &(p));

    p = p - 2;
    printf("%d \n", *(p)); // 9
    printf("%p \n", &(p));

    return 0; 
}