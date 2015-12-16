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
const int maxn = 1e3+5;
const int M = 1e9+7;
int dp[maxn][maxn], a[maxn], n, p;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &p);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        clc(dp, 0);
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++)
        {
            int t = ((p - a[i]) % p + p) % p;
            for(int j = 0; j < p; j++)
            {
                dp[i][j] = (dp[i-1][j] + dp[i-1][t]) % M; // (t + a[i]) % p == j
                t = (t + 1) % p;
            }
        }
        printf("%d\n", dp[n][0]);
    }
    return 0;
}


