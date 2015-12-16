#include <stdio.h>

#define maxn 100005
int a[maxn];

int main()
{
    int n;
    while(scanf("%d", &n) && n)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        int sum = -100000, max = -100000, x , y, c, d;
        for(int i = 0; i < n; i++)
        {
            if(sum + a[i] < a[i])
            {
                sum = a[i]; x = i; y = i;
            }
            else 
            {
                sum += a[i]; y++;
            }
            if(sum > max)
            {
                max = sum;
                c = x; d = y;
            }
        }
        if(max < 0) 
            printf("%d %d %d\n", 0, a[0], a[n-1]);
        else
            printf("%d %d %d\n", max, a[c], a[d]);
    }
    return 0;
}