#include <stdio.h>
#include <stdbool.h>
void calcolaMedia();

int main()
{
    void (*menu[])(void) = {calcolaMedia};
    menu[0]();

    /* K&R camelCase
    if (true){
    ...
    }else{
    ...
    }*/

    return 0;
}

void calcolaMedia()
{
    printf("%d", 2 + 2);
}