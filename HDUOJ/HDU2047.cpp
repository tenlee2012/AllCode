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
const int maxn = 50;

long long a[maxn];

int main()
{
    int n;
    a[1] = 3;
    long long x = 2, y = 1;
    long long xx = 2, yy = 1;
    for(int i = 2; i < 40; i++)
    {
        a[i] = 3 * x + 2 * y;
        xx = x; yy = y;
        x = 2 * yy + 2 * xx;
        y = xx;
        //printf("%d %lld\n", i, a[i]);
    }
    while(~scanf("%d", &n))
    {
        printf("%lld\n", a[n]);
    }
    return 0;
}
