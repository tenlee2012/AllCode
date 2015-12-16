#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int vis[3005] = {0};
int a[3005] = {0};
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    //freopen("1.in","r",stdin);
    int n;
    while (~scanf("%d", &n))
    {
        int i, j;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }

        sort(a, a + n, cmp);
        memset(vis, 0, sizeof(vis));
        int sum = 0;

        for (i = 0; i < n; i++)
        {
            if (vis[i])
            {
                continue;
            }    //printf("max a[%d] = %d\n", i, a[i]);
            sum++;
            int max = a[i];
            for (j = i + 1; j < n; j++)
            {
                if (vis[j])        continue;

                if (a[j] < max)
                {
                    //printf("j = %d\n", j);
                    max = a[j];
                    vis[j] = 1;
                }
            }
        }
        printf("%d\n", sum);
    }
}
