#include <stdio.h>
#include <stdlib.h>

int intcomp(const void *x, const void *y)
{
    return *(int*)x - *(int*)y;
}

int a[10000000];

int main(int argc, char** argv)
{
    int i = 0;
    int n = 0;
    while(scanf("%d", &a[n]) != EOF)
        n++;
    qsort((void*)a, n, sizeof(int), intcomp);
    for(i=0; i<n; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}
