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
const int maxn = 1e6+5;

int main()
{
    long long n, m, k;
    long long sum;
    while(~scanf("%lld %lld %lld", &n, &m, &k))
    {
        sum = 0;
        for(long long i = 1; k - 2*i >= 2 && i <= n; i++) //长，对应n
        {
            long long  mi = min((k-2*i)/2, m);
            long long  x = n - i + 1, y = m + 1;
            sum = sum + x * (mi * y - (1+mi)*mi/2);
        }
        printf("%lld\n", sum);
    }
    return 0;
}
