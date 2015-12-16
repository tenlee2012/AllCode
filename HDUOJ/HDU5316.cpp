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
typedef long long ll;
const ll inf = -10000000000;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;

struct Sum
{
    ll jo, jj, oo, oj;
};
struct Tree
{
    int l, r;
    Sum s;
}tree[maxn << 2];
int n, m;
ll a[maxn];

inline Sum getSum(Sum l, Sum r)
{
    Sum ss;
    ss.jj = max(l.jj, r.jj); 
    ss.jj = max(ss.jj, l.jj+r.oj);
    ss.jj = max(ss.jj, l.jo+r.jj);

    ss.jo = max(l.jo, r.jo);
    ss.jo = max(ss.jo, l.jj+r.oo);
    ss.jo = max(ss.jo, l.jo+r.jo);

    ss.oo = max(l.oo, r.oo); 
    ss.oo = max(ss.oo, l.oj+r.oo);
    ss.oo = max(ss.oo, l.oo+r.jo);

    ss.oj = max(l.oj, r.oj);
    ss.oj = max(ss.oj, l.oj+r.oj);
    ss.oj = max(ss.oj, l.oo+r.jj);
    return ss;
}
void Build(int i, int l, int r)
{
    tree[i].l = l;
    tree[i].r = r;
    if(l == r)
    {
        if(l%2) // j
        {
            tree[i].s.jj = a[l]; tree[i].s.jo = inf;
            tree[i].s.oo = inf; tree[i].s.oj = inf;
        }
        else
        {
            tree[i].s.jj = inf; tree[i].s.jo = inf;
            tree[i].s.oo = a[l]; tree[i].s.oj = inf;
        }
       return;
    }
    int mid = (l + r) >> 1;
    Build(i<<1, l, mid);
    Build(i<<1|1, mid+1, r);
    tree[i].s = getSum(tree[i<<1].s, tree[i<<1|1].s);
}
void Update(int i, int id, ll val)
{
    if(tree[i].l == id && tree[i].r == id)
    {
        if(id%2) // j
        {
            tree[i].s.jj = val; tree[i].s.jo = inf;
            tree[i].s.oo = inf; tree[i].s.oj = inf;
        }
        else
        {
            tree[i].s.jj = inf; tree[i].s.jo = inf;
            tree[i].s.oo = val; tree[i].s.oj = inf;
        }
       return;
    }
    int mid = (tree[i].l + tree[i].r) >> 1;
    if(id > mid) Update(i<<1|1, id, val);
    else Update(i<<1, id, val);
    tree[i].s = getSum(tree[i<<1].s, tree[i<<1|1].s);
}
Sum Quary(int i, int l, int r)
{
    if(tree[i].l == l && tree[i].r == r)
    {
        return tree[i].s;   
    }
    int mid = (tree[i].l + tree[i].r) >> 1;
    if(r <= mid) return Quary(i<<1, l, r);
    else if(l > mid) return Quary(i<<1|1, l, r);
    else return(getSum(Quary(i<<1, l, mid), Quary(i<<1|1, mid+1, r))); 
}
int main()
{
    //freopen("MUL3/data/1001/1001.in", "r", stdin);
    //freopen("001.out", "w", stdout);
    int T, x, y, op;
    Sum s;
    ll sum = 0, v;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
        }
        Build(1, 1, n);
        while(m--)
        {
            scanf("%d", &op);
            if(x > y) swap(x, y);
            if(op == 0)
            {
                scanf("%d %d",&x, &y);
                if(n == 0)
                {
                    puts("0");continue;
                }
                s = Quary(1, x, y);
                sum = max(s.jj, s.jo);
                sum = max(sum, s.oo);
                sum = max(sum, s.oj);
                printf("%lld\n", sum);
            }
            else 
            {
                scanf("%d %lld", &x, &v);
                Update(1, x, v);
            }
        }
    }
    return 0;
}
