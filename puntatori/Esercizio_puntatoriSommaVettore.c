#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10
int main()
{
    int v[MAX];
    int *p = v;
    int sum = 0;
    srand(time(NULL));
    for (int i = 0; i < MAX; i++)
    {
        v[i] = rand() % 10 + 1;
        sum++;
        printf("%d\n", v[i]);
        p = &v[i];
    }
}