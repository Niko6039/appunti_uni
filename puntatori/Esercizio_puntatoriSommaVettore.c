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

float media(int v[])
{
    int som = 0;
    float media;
    for (int i = 0; i < MAX; i++)
    {
        som = som + v[i];
    }
    return media = som / MAX;
}

float media2(int *v)
{
    int som = 0;
    float media;

    for (int i = 0; i < MAX; i++)
    {
        som = *(v + i) + som;
    }

    return media = som / MAX;
    //
}