//Author LJH
//www.cnblogs.com/tenlee
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#define clc(a, b) memset(a, b, sizeof(a))
#define LL long long
using namespace std;

const int inf = 0x3f;
const int INF = 0x3f3f3f3f;
const int maxn = 1e2+5;
int g[maxn][maxn];

int main()
{
    int v, u, n, m;
    while(~scanf("%d %d", &n, &m))
    {
        clc(g, 0);
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d", &u, &v);
            g[v][u] = g[u][v] = 1;
        }
        if(!g[1][n]) printf("1 1\n");
        else printf("1 %d\n", n*(n-1)/2);
    }
    return 0;
}
