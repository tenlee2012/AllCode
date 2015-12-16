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
    a[1] = 0; a[2] = 1; a[3] = 2;
    for(int i = 4; i <= 40; i++)
    {
        a[i] = a[i-1] + a[i-2];
    }
    int T, n;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        printf("%lld\n", a[n]);
    }
    return 0;
}
