#include<iostream>
#include<cstdio>
const int N = 202;
const int INF = 1 << 28;
int path[N][N];
int floyd(int s, int t, int n)
{
    int i, j, k;
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
        {
            if (path[i][k] != INF)    // 优化，减少不必要的时间损耗
                for (j = 0; j < n; j++)
                    if (path[i][j] > path[i][k] + path[k][j])
                        path[i][j] = path[i][k] + path[k][j];
        }
    return path[s][t];
}

int main()
{
    int i, j, n, m, a, b, x, s, t, ans;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
            {
                if (i == j)
                    path[i][j] = 0;
                else
                    path[i][j] = INF;
            }
        for (i = 0; i < m; i++)
        {
        scanf("%d%d%d", &a,&b,&x);
        if (x < path[a][b]) path[a][b] = path[b][a] = x;
        }
              scanf("%d%d",&s,&t);
              ans = floyd(s, t, n);
            printf("%d\n", ans < INF ? ans : -1);
             }
      return 0;
}

                    