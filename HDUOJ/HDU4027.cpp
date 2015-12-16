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

struct Node
{
    int l, r;
    LL sum;
    int flag;
}tree[maxn << 2];

void Build(int i, int l, int r)
{
    tree[i].l = l;
    tree[i].r = r;
    tree[i].flag = 0;
    if(l == r)
    {
        scanf("%lld", &tree[i].sum);
        return;
    }
    int mid = (l + r) >> 1;
    Build(i<<1, l, mid);
    Build(i<<1|1, mid+1, r);
    tree[i].sum = tree[i<<1].sum + tree[i<<1|1].sum;
}

void PushDown(int i)
{
    if(tree[i].flag)
        return;
    if(tree[i].l == tree[i].r)
    {
        tree[i].sum = sqrt(tree[i].sum);
        if(tree[i].sum == 1)
        {
            tree[i].flag = 1;
        }
        return;
    }
    else 
    {
        PushDown(i<<1);
        PushDown(i<<1|1);
        tree[i].sum = tree[i<<1].sum + tree[i<<1|1].sum;
        tree[i].flag = tree[i<<1].flag & tree[i<<1|1].flag;
    }
}
void Update(int i, int l, int r)
{
    //printf("i = %d l = %d r = %d\n", i, l, r);
    if(tree[i].r == r && l == tree[i].l)
    {
        PushDown(i);
        return;
    }
    int mid = (tree[i].r + tree[i].l) >> 1;
    if(r <= mid)
    {
        Update(i<<1, l, r);
    }
    else if(l > mid)
    {
        Update(i<<1|1, l, r);
    }
    else
    {
        Update(i<<1, l, mid);
        Update(i<<1|1, mid+1, r);
    }
    tree[i].sum = tree[i<<1].sum + tree[i<<1|1].sum;
    tree[i].flag = tree[i<<1].flag & tree[i<<1|1].flag;
 
}

LL Query(int i, int l, int r)
{
   if(tree[i].l == l && tree[i].r == r)
    {
        return tree[i].sum;
    }
    int mid = (tree[i].r + tree[i].l) >> 1;
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
        return Query(i<<1, l, mid) + Query(i<<1|1, mid+1, r);
    }
}

int main()
{
    int n, m;
    int op, x, y;
    int tt = 1;
    while(~scanf("%d", &n))
    {
        Build(1, 1, n);
        printf("Case #%d:\n", tt++);
        scanf("%d", &m);
        while(m--)
        {
            scanf("%d %d %d", &op, &x, &y);
            if(x>y)   //这里真坑,不然一直re
                swap(x,y);  
            if(op)
            {
                printf("%lld\n", Query(1, x, y));
            }
            else
            {
                Update(1, x, y);
            }
        }
        printf("\n");
    }
    return 0;
}
