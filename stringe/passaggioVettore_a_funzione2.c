#include <stdio.h>

int menu()
{
    int sc;
    do
    {
        printf("Cosa vuoi : \n1)Pizza \n2)Sushi \n3)Niente\n");
        scanf("%d", &sc);
    } while (sc < 0 && sc > 4);
    return sc;
}

void main()
{
    int scelta = menu();
    if (scelta == 1)
    {
        printf("Sei normale:)");
    }
    else if (scelta == 2)
    {
        printf("Crizy!!!");
    }
    else
    {
        printf("Allora alla prossima!!");
    }
}
