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
using namespace std;

const int inf = 0x3f;
const int INF = 0x3f3f3f3f;
const int maxn = 40;
long long a[maxn][maxn];

int main()
{
    for(int i = 1; i <= 30; i++)
    {
        a[i][1] = 1;
        for(int j = 2; j < i; j++)
        {
            a[i][j] = a[i-1][j] + a[i-1][j-1];
        }
        a[i][i] = 1;
    }
    int n;
    while(~scanf("%d", &n))
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                printf("%lld", a[i][j]);
                i != j ? printf(" ") : printf("\n");
            }
        }
        puts("");
    }
    return 0;
}
