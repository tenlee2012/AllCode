#include <stdio.h>
#include <string.h>

using namespace std;
const int MAXN = 1e5 + 10;
int n;
char str[MAXN];

int main()
{
    while(~scanf("%d", &n) && n)
    {
        int xx = 0, yy = 0;
        for(int i = 0; i < n; i++)
        {
            scanf(" %c", &str[i]);
            if(str[i] == 'H') xx++;
            else yy++;
        }
        if(n % 2)
        {
            puts("-1");
            continue;
        }
        if(xx%2 || yy%2)
        {
            puts("-1");
            continue;
        }
        int x = 0, y = 0;
        int f = 0;
        for(int i = 0; i < n/2; i++)
        {
            if(str[i] == 'H') x++;
            else y++;
        }
        if(x == xx/2 && y == yy/2)
        {
            printf("1\n%d\n", n/2);
            continue;
        }
        for(int i = 0, j = n/2; i < n/2; i++, j++)
        {
            if(str[j] == 'H') x++;
            else y++;
            if(str[i] == 'H') x--;
            else y--;
            if(x == xx/2 && y == yy/2)
            {
                printf("2\n%d %d\n", i+1, j+1);
                f = 1;
                break;
            } 
        }
        if(f == 0)
            puts("-1");
    }
    return 0;
}