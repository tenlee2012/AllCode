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
const int maxn = 1e2+5;
long long a[maxn];

int main()
{
    int T, x, y;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &x, &y);
        memset(a, 0, sizeof(a));
        a[x] = 1;
        for(int i = x+1; i <= y; i++)
        {
            a[i] = a[i-1] + a[i-2];
        }
        printf("%lld\n", a[y]);
    }
    return 0;
}
