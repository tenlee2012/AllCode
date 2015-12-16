#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
     
#define maxn 1000
int n, m, match[maxn];
bool edge[maxn][maxn], visit[maxn];

bool crosspath(int u)
{
    for(int i = 1; i <= m; i++)
    {
        if(edge[u][i] && !visit[i])
        {
            visit[i] = true;
            if(match[i] == -1 || crosspath(match[i]))
            {
                match[i] = u;
                return true;
            }
        }
    }
    return false;
}
int hungry()
{
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        memset(visit, false, sizeof(visit));
        if(crosspath(i))
        {
            ans++;
        }
    }
    return ans;
}
int main()
{
    int T;
    while(~scanf("%d %d", &n, &m))
    {
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                edge[i][j] = false;
            }
            match[i] = -1;
        }
        for(int i = 1; i <= n; i++)
        {
            int num; scanf("%d", &num);
            while(num--)
            {
                int x, y;
                scanf("%d", &x);
                edge[i][x] = true;
            }
        }
        printf("%d\n", hungry());
    }
}
