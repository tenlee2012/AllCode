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
#define ll long long

ll a[maxn], b[maxn];
int root[maxn], tot;
struct Node
{
    int ls, rs, sum;
}p[maxn * 20];

int Build(int l, int r)
{
    int rt = tot++;
    p[rt].sum = 0;
    if(l == r) return rt;
    int m = (l + r) >> 1;
    p[rt].ls = Build(l, m);
    p[rt].rs = Build(m+1, r);
    return rt;
}

int Update(int x, int v, int i, int l, int r)
{
    int rt = tot++;
    p[rt] = p[i];
    p[rt].sum += v;
    if(l == r) return rt;
    int m = (l + r) >> 1;
    if(x <= m) p[rt].ls = Update(x, v, p[i].ls, l, m);
    else
        p[rt].rs = Update(x, v, p[i].rs, m+1, r);
    return rt;
}

int Query(int i, int j, int k, int l, int r)
{
    if(l == r)
        return p[i].sum - p[j].sum;
    int ret = 0, m = (l + r) >> 1;
    if(k > m)
    {
        ret += (p[p[i].ls].sum - p[p[j].ls].sum);
        ret += Query(p[i].rs, p[j].rs, k, m+1, r);
    }
    else
    {
        ret += Query(p[i].ls, p[j].ls, k, l, m);
    }
    return ret;
}

int main()
{
    int T;
    scanf("%d\n", &T);
    for(int t = 1; t <= T; t++)
    {
        tot = 0;
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++)
        {
            scanf("%I64d", &a[i]);
            b[i] = a[i];
        }
        sort(b+1, b+1+n);
        int tmp = unique(b+1, b+1+n) - b - 1;
        tmp++;
        b[tmp] = inf;
        root[0] = Build(1, tmp);
        for(int i = 1; i <= n; i++)
        {
            int k = lower_bound(b+1, b+1+tmp, a[i]) - b;
            root[i] = Update(k, 1, root[i-1], 1, tmp);
        }
        printf("Case %d:\n", t);
        while(m--)
        {
            int l, r;
            ll v;
            scanf("%d %d %I64d", &l, &r, &v);
            l++; r++;
            int k = upper_bound(b+1, b+1+tmp, v) - b - 1;
            int ans = 0;
            if(k > 0) 
                ans = Query(root[r], root[l-1], k, 1, tmp);
            printf("%d\n", ans);
        }
    }
    return 0;
}
