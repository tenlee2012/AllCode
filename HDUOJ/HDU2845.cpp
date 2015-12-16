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
const int maxn = 2000005;
int a[maxn],b[maxn];
int main()
{
    int n, m;
    while(~scanf("%d %d", &n, &m))
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                scanf("%d", &a[j]);
            }
            for(int j = 2; j <= m; j++)
            {
                a[j] = max(a[j-2]+a[j], a[j-1]);
            }
            b[i] = a[m];
        }
        for(int i = 2; i <= n; i++)
        {
             b[i] = max(b[i-2]+b[i], b[i-1]);
        }
         printf("%d\n", b[n]);
    }
     return 0;
 }
