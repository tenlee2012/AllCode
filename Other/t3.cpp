#include<stdio.h>
#include <stdlib.h>

int main() 
{
    void *a = (void*)100;
    int* aa = (int*)malloc(4 * sizeof(int));
    aa[1] = 100;
    printf("%d\n", aa[1]);
    free(aa);
    //printf("%d %c %f\n", a, a, a);
    return 0;
}
