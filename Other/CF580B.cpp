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

struct Fri
{
    int m, s;
}fri[maxn];
int n, d;
bool cmp(Fri A, Fri B)
{
    if(A.m == B.m) return A.s < B.s;
    return A.m < B.m;
}

int main()
{
    while(~scanf("%d %d", &n, &d))
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &fri[i].m ,&fri[i].s);
        }
        sort(fri, fri+n, cmp);
        LL ans = fri[0].s, s = fri[0].s, s1 = fri[0].s, s2 = fri[0].s;
        int j = 0, k = 0, pre = 0;
        for(int i = 1; i < n; i++)
        {
            s2 += fri[i].s;
            while(fri[i].m - fri[j].m >= d)
            {
                j++;
                s1 += fri[j].s;
            }
            s = s2 - s1 + fri[j].s;
            ans = max(ans, s);
        }
        ans = max(ans, s);
        printf("%lld\n", ans);
    }
    return 0;
}
