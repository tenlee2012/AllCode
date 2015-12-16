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
const int maxn = 1e6+5;
const LL mod = 1000000007;

LL pow2(LL a, LL b)
{
    LL r = 1;
    LL base = a;
    while(b)
    {
        if(b&1)
        {
            r = r * base % mod;
        }
        base = base * base % mod;
        b >>= 1;
    }
    return r;
}

int main()
{
    int T;
    LL n;
    LL sum;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lld", &n);
        if(n == 0)
        {
            printf("1\n");  continue;
        }
        if(n == 1)
        {
            printf("0\n"); continue;
        }
        if(n == 2)
        {
            printf("1\n"); continue;
        }
        sum = pow2(2, n-1) % mod - 1; 
        printf("%lld\n", sum % mod);
    }
    return 0;
}
