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

double a[maxn];

void Init()
{
    a[1] = 1.0;
    for(int i = 2; i <= 1000; i++)
    {
        if(i%2 == 0) a[i] = a[i-1] - 1 / (double)i;
        else a[i] = a[i-1] + 1 / (double)i;
    }
}

int main()
{
    Init();
    int T, n;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        printf("%.2f\n", a[n]);
    }
    return 0;
}
