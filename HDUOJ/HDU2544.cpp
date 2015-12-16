#include<iostream>
#include<cstdio>
#include<iostream>
using namespace std;
const int N = 106;
const int INF = 99999999;
int path[N][N];
int floyd(int s, int t, int n)
{
    int i, j, k;
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
        {
            if(path[i][k]!=INF)
                for (j = 1; j <= n; j++)
                    {
                        if (path[i][j] > path[i][k] + path[k][j])
                        {
                            path[i][j] = path[i][k] + path[k][j];
                        }
                    }

        }
    return path[s][t];
}

int main()
{
    int i, j, n, x, ans,a,b,s,m;
    while (scanf("%d%d", &n,&m) != EOF&&(n+m)!=0)
    {
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
            {
                if (i == j)
                    path[i][j] = 0;
                else
                    path[i][j] = INF;
            }
        for (i=1; i <= m;i++)
        {
            scanf("%d%d%d", &a,&b,&x);
            if (x < path[a][b])
            path[a][b] = path[b][a] = x;
        }
            ans = floyd(1, n, n);
            printf("%d\n", ans);
    }
      return 0;
}