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

#define ll long long
const int inf = 0x3f;
const int INF = 0x3f3f3f3f;
const int maxn = 1e6+5;

int n, m, z, l;
ll a[maxn];

int main()
{
    a[1] = 0;
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d %d %d", &n, &m, &z, &l);
        ll ans;
        for(int i = 2; i <= n; i++)
        {
            a[i] = (a[i-1] * m + z) % l;
            //printf("%d\n", a[i]);
        }
        ans = a[1] * 2;
        for(int i = 2; i <= n; i++)
        {
            ans = ans ^ (a[i] * 2);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
