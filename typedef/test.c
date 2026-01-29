#include <stdio.h>
#include <stdbool.h>

#define MAX 250

void setFrase(char *p)
{
    int i = 0;
    char lettera = getchar();

    while (i < MAX - 1 && lettera != '\n' && lettera != EOF)
    {
        *(p + i) = (char)lettera;
        lettera = getchar();
        i++;
    }
    *(p + i) = '\0';
}

void setCesare(char *p, char chiave)
{
    int i = 0;
    char tmp;
    while (*(p + i) != '\0')
    {
        tmp = *(p + i);

        // Corretto: serve && (AND), non || (OR)
        if (tmp >= 'a' && tmp <= 'z')
        {
            tmp = (tmp - 'a' + chiave) % 26 + 'a';
            *(p + i) = tmp;
        }
        else if (tmp >= 'A' && tmp <= 'Z')
        {
            tmp = (tmp - 'A' + chiave) % 26 + 'A';
            *(p + i) = tmp; // Aggiunto il salvataggio mancante
        }
        i++;
    }
}

void decifraCesare(char *p, int chiave)
{
    int i = 0;
    char tmp;
    while (*(p + i) != '\0')
    {
        tmp = *(p + i);

        // Corretto: && e rimosso errore logico (avevi >= 'z')
        if (tmp >= 'a' && tmp <= 'z')
        {
            tmp = (tmp - 'a' - chiave % 26 + 26) % 26 + 'a';
            *(p + i) = tmp;
        }
        else if (tmp >= 'A' && tmp <= 'Z')
        {
            tmp = (tmp - 'A' - chiave % 26 + 26) % 26 + 'A';
            *(p + i) = tmp;
        }

        i++;
    }
}

int main()
{
    char sc = 'y';
    do
    {
        char frase[MAX];
        char *p = frase;
        int chiave;

        printf("Inserisci la frase: ");
        setFrase(p);

        printf("Hai inserito: %s\n", frase);

        printf("Inserisci un numero (chiave): ");
        scanf("%d", &chiave);

        setCesare(p, (char)chiave);
        printf("La frase cifrata: %s\n", frase);

        decifraCesare(p, chiave);
        printf("La frase decifrata: %s\n", frase);

        printf("Vuoi continuare? (y/n): ");
        scanf(" %c", &sc);

        // Pulizia del buffer fondamentale per il prossimo getchar()
        while (getchar() != '\n')
            ;

    } while (sc == 'y' || sc == 'Y');

    return 0;
}