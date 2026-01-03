//[distanzal — Scrivere una funzione Che riceva in ingresso Ie coordinate a: , y di due punti del
// piano cartesiano e restituisca la loro distanza. Scrivere successivamente un programma che
// richieda in input le coordinate di un punto A e ne visualizzi la distanza dal punto B (5, 3)
// utilizzando la funzione indicata.
// d(P1, P2)= rad((x2 - x1)+);

#include <stdio.h>
#include <math.h>

double distanza(double x1, double y1, double x2, double y2)
{
    double xDif = x2 - x1;
    double yDif = y2 - y1;
    double sol = sqrt(pow(xDif, 2) + pow(yDif, 2));
    return sol;
}

int main()
{
    double x1, y1;
    double x2 = 5.0;
    double y2 = 3.0;

    printf("=== Calcolo distanza dal punto B(5, 3) ===\n");

    printf("Inserisci la coordinata X del punto A: ");
    scanf("%lf", &x1);

    printf("Inserisci la coordinata Y del punto A: ");
    scanf("%lf", &y1);

    double risultato = distanza(x1, y1, x2, y2);

    printf("\nLa distanza tra A(%.2lf, %.2lf) e B(%.2lf, %.2lf) e': %.4lf\n", x1, y1, x2, y2, risultato);

    return 0;
}