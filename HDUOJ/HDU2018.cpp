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
const int maxn = 60;
long long a[maxn];

inline void preSlove()
{
    a[1] = 1; a[2] = 2;
    a[3] = 3; a[4] = 4;
    int n1 = 0, n2 = 0, j = 1;
    for(int i = 5; i < 55; i++)
    {
        a[i] = a[i-1] + a[i-3];
        j++;
    }
}
int main()
{
    preSlove();
    int n;
    while(~scanf("%d", &n) && n)
    {
        printf("%lld\n", a[n]);
    }
    return 0;
}
