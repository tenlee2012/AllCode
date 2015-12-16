//Author LJH
//www.cnblogs.com/tenlee
#include <stdio.h>

const int inf = 0x3f;
const int INF = 0x3f3f3f3f;
const int maxn = 50;

int a[maxn];
int main()
{
    int T;
    int m, n, t;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        int dir = 1, nu = 1, killed = 0;
        t = n + 5;
        int ans = 1;
        while(t--)
        {
            while(a[nu] <= 0 && nu <= n && nu > 0)
            {
                if(nu == n && dir == 1) nu = 1;
                else if (nu == 1 && dir == -1) nu = n;
                else nu += dir;
            }
            //printf("nu = %d\n", nu);
            if(m >= a[nu])
            {
                dir = dir == 1 ? -1 : 1;
                killed++;
            }
            ans = nu;
            if(killed >= n)
                break;
            a[nu] = a[nu] - m;
            if(nu == n && dir == 1) nu = 1;
            else if (nu == 1 && dir == -1) nu = n;
            else nu += dir;
        }
        printf("%d\n", ans);
    }

    return 0;
}
