#include <stdio.h>

int main()
{
    char sa[] = "alticcio";
    char c = 't';
    int trovato = 0;
    int i;
    //        fine della stringa
    //             '/0'
    for (i = 0; (sa[i] != '\0') && (trovato != 1); i++)
    {
        // se il char nella posizione i è uguale a c allora mettiano trovato a 1
        if (sa[i] == c)
        {
            trovato = 1;
        }
    }
    // se è statp trovato allora stampiamo la posizione
    if (trovato == 1)
    {
        printf("Trovato la prima occorrenza in posizione %d\n", (i));
    }
    else
    {
        printf("Non trovato\n");
    }

    return 0;
}