#include <stdio.h>

int main()
{
    int x, y;
    while(~scanf("%d %d", &x, &y))
    {
        if((x+y)%86)
        {
            printf("no\n");
        }
        else
        {
            puts("yes");
        }
    }
    return 0;
}
