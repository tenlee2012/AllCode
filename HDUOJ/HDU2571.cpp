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

using namespace std;

const int inf = 0x3f;
const int INF = 0x3f3f3f3f;
const int maxn = 1005;

int G[maxn][maxn], dp[maxn][maxn];

int main()
{
    int m, n, T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                scanf("%d", &G[i][j]);
                dp[i][j] = G[i][j];
            }
        }

        int ans = 0;
        
        for(int i = 1; i <= n; i++)
        {
            if(i != 1)dp[i][1] = G[i][1] + dp[i-1][1];
            for(int j = 2; j <= m; j++)
            {
                int ma = -INF;
                for(int k = 1; k < j; k++)
                {
                    if(j%k == 0) ma = max(ma, dp[i][k]);
                }
                if(i == 1)
                {
                    dp[i][j] = G[i][j] + max(dp[i][j-1], ma);
                }
                else 
                {
                    dp[i][j] = G[i][j] + max(dp[i][j-1], max(ma, dp[i-1][j]));  
                }
                //printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
            }
        }
        ans = dp[n][m];
        printf("%d\n", ans);
    }
    return 0;
}
