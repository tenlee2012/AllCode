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
const int maxn = 1e5+5;

struct Node
{
    int l, r;
    LL sum, add;
}tree[maxn * 6];

void Build(int i, int l, int r);
void Update(int i, int l, int r, int val);
void PushDown(int i);
LL Query(int i, int l, int r);

int main()
{
    int n, q;
    int a, b, c;
    char op;
    while(~scanf("%d %d", &n, &q))
    {
        Build(1, 1, n);
        while(q--)
        {
            scanf(" %c", &op);
            if(op == 'Q')
            {
                scanf("%d %d", &a, &b);
                printf("%lld\n", Query(1, a, b));
            }
            else 
            {
                scanf("%d %d %d", &a, &b, &c);
                Update(1, a, b, c);
            }
        }
    }
    return 0;
}

void Build(int i, int l, int r)
{
    tree[i].l = l;
    tree[i].r = r;
    tree[i].add = 0;
    if(l == r)
    {
        scanf("%lld", &tree[i].sum);
        return;
    }
    int mid = (l + r) >> 1;
    Build(i << 1, l, mid);
    Build(i << 1 | 1, mid + 1, r);
    tree[i].sum = tree[i<<1].sum + tree[i<<1|1].sum;
}

void Update(int i, int l, int r, int val)
{
    if(tree[i].l == l && tree[i].r == r) //刚好满足时,就标记了
    {
        tree[i].add += val;
        return;
    }
    tree[i].sum += (r - l + 1) * val; //注意此处是 r - l + 1, 而不是 tree[i].r - tree[i].l + 1
    int mid = (tree[i].l + tree[i].r) >> 1;
    if(r <= mid)
    {
        Update(i<<1, l, r, val);
    }
    else if(l > mid)
    {
        Update(i<<1|1, l, r, val);
    }
    else 
    {
        Update(i<<1, l, mid, val);
        Update(i<<1|1, mid+1, r, val);
    }
}

void PushDown(int i)
{
    tree[i<<1|1].add += tree[i].add;
    tree[i<<1].add += tree[i].add;
    tree[i].sum += (tree[i].r  - tree[i].l + 1) * tree[i].add;
    tree[i].add = 0; //重置为0
 
}

LL Query(int i, int l, int r)
{
    if(tree[i].add != 0)  // 向下更新
    {
        PushDown(i);
    }
    if(tree[i].l == l && tree[i].r == r)
    {
        return tree[i].sum;
    }
    int mid = (tree[i].l + tree[i].r) >> 1;
    if(r <= mid)
    {
        return Query(i<<1, l, r);
    }
    else if(l > mid)
    {
        return Query(i<<1|1, l, r);
    }
    else 
    {
        return (Query(i<<1, l, mid) + Query(i<<1|1, mid+1, r));
    }

}
