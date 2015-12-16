//Author LJH
//www.cnblogs.com/tenlee
#include <bits/stdc++.h>

#define clc(a, b) memset(a, b, sizeof(a))
#define LL long long
using namespace std;

const int inf = 0x3f;
const int INF = 0x3f3f3f3f;
const int maxn = 1e2+5;

int n, m, a[maxn], b[maxn];

int main()
{
    int x, y;
    while(~scanf("%d %d", &n, &m))
    {
        int mi = INF, nu;
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d", &x, &y);
            nu = (n%x) == 0 ? n/x : n/x+1;
            mi = (nu*y) < mi ? (nu*y) : mi;
        }
        printf("%d\n", mi);
    }
    return 0;
}
