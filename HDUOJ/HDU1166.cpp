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
#define clc(a, b) memset(a, b, sizeof(a))
const int inf = 0x3f;
const int INF = 0x3f3f3f3f;
const int maxn = 5e4+5;

int c[maxn], n;

int lowbit(int x)
{
    return x&-x;
}

void add(int x, int val)
{
    while(x<=n)
    {
        c[x] += val;
        x += lowbit(x);
    }
}

int query(int l, int r)
{
    int sum1 = 0, sum2 = 0;
    while(r > 0)
    {
        sum1 += c[r];
        r -= lowbit(r);
    }
    l = l-1;
    while(l > 0)
    {
        sum2 += c[l];
        l -= lowbit(l);
    }
    return sum1-sum2;
}

int main()
{
    int T, x, l, r;
    char q[100];
    scanf("%d", &T);
    for(int t = 1; t <= T; t++)
    {
        scanf("%d", &n);
        clc(c, 0);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            add(i+1, x);
        }
        printf("Case %d:\n", t);
        while(true)
        {
            scanf(" %s", q);
            if(!strcmp(q, "End")) break;
            if(!strcmp(q, "Query"))
            {
                scanf("%d %d", &l, &r);
                printf("%d\n", query(l, r));
            }
            else if(!strcmp(q, "Sub"))
            {
                scanf("%d %d", &l, &x);
                add(l, -x);
            }
            else
            {
                scanf("%d %d", &l, &x);
                add(l, x);
            }
        }
    }
    return 0;
}
