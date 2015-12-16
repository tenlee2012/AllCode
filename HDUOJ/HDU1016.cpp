#include<cstdio>
#include<cstring>
void dfs(int x);
int prime(int y);
int n, vis[100] = {0}, isp[100] = {0}, a[100] = {0};
int main()
{
    //freopen("1.txt","w",stdout);
    int k = 0;

    while (~scanf("%d", &n) && n != 0)
    {
        memset(vis, 0, sizeof(vis));
        memset(isp, 0, sizeof(isp));
        memset(a, 0, sizeof(a));
        printf("Case %d:\n", ++k);

        if(n % 2 == 0 || n == 1)
        {
            for (int i = 2; i <= 2 * n; i++)
            {
                isp[i] = prime(i);
            }

            a[0] = 1;
            dfs(1);
        }

        printf("\n");
    }
}
int prime(int y)
{
    for (int i = 2; i < y; i++)
    {
        if (y % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

void dfs(int x)
{
    if (x == n && isp[a[0] + a[n - 1]])
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d", a[i]);

            if (i != n - 1)
            {
                printf(" ");
            }
            else
            {
                printf("\n");
            }
        }
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            if (!vis[i] && isp[i + a[x - 1]])
            {
                a[x] = i;
                vis[i] = 1;
                dfs(x + 1);
                vis[i] = 0;
            }
        }
    }
}
