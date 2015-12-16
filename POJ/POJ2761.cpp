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

struct Que
{
    int l, r, k, id;
    bool operator < (const Que &a) const 
    {
        if(l == a.l) return r < a.r;
        return l < a.l;
    }
}q[maxn];

struct Dog
{
    int val, id;
    bool operator < (const Dog &a) const 
    {
        return val < a.val;
    }
}d[maxn];

int node[maxn], ans[maxn], fval[maxn], pval[maxn], n, m;

inline int lowbit(int x)
{
    return x & -x;
}
void Init()
{
    clc(node, 0);
}

void add(int x, int val)
{
    //printf("x = %d\n", x);
    if(x == 0) return;
    while(x <= n)
    {
        node[x] += val;//记录这个结点下面包含了多少个数，即这个结点总共有多少个叶子结点
        x += lowbit(x);
    }
}

int findkth(int k)//查找第k大的数，返回第几个数，即排序后的下标
{
    int i, cnt = 0, ans = 0;
    for(i = 20; i >= 0; i--) //二进制思想
    {
        ans += (1 << i);
        if(ans >= n || cnt + node[ans] >= k) ////这里大于等于k的原因是可能大小为ans的数不在c[ans]的控制范围之内，所以这里求的是 < k
            ans -= (1 << i);
        else 
            cnt += node[ans];
        //cnt用来累加比当前ans小的总组数
    }
    //求出的ans是累加和（即小于等于ans的数的个数）小于k的情况下ans的最大值，所以ans+1就是第k大的数
    return ans + 1;
}

int main()
{
    int i, j;
    while(~scanf("%d %d", &n, &m))
    {
        Init();
        for(i = 1; i <= n; i++)
        {
            scanf("%d", &d[i].val);
            d[i].id = i;
        }
        sort(d+1, d+n+1);
        int k = 1;
        fval[d[1].id] = 1;
        pval[1] = d[1].val;
        for(i = 2; i <= n; i++)
        {
            if(d[i].val != d[i-1].val)
                pval[++k] = d[i].val; //消除重复的
            fval[d[i].id] = k; //记录这个数是排序后第几个数, 即原来的第几个数对应现在排序后的第几个数
        }
        for(i = 0; i < m; i++)
        {
            scanf("%d %d %d", &q[i].l, &q[i].r, &q[i].k);
            q[i].id = i;
            if(q[i].r < q[i].l) swap(q[i].l, q[i].r);
        }
        sort(q, q+m);

        int curl = 1, curr = 0; //左右 初始化左比右大
        for(i = 0; i < m; i++)
        {
            if(curr < q[i].l)// curl curr q[i].l q[i].r
            {
                for(j = curl; j <= curr; j++)//fval[j] 获得 原来第j个数在排序后的坐标
                    add(fval[j], -1);
                for(j = q[i].l; j <= q[i].r; j++)
                    add(fval[j], 1);
                curl = q[i].l; curr = q[i].r;
            }
            else // curl q[i].l curr q[i].r || q[i].l curl curr q[i].r
            {
                for(j = curl; j < q[i].l; j++) // 清空上次查询，就是把不属于对应区间的 值改为0
                    add(fval[j], -1);
                for(j = curr+1; j <= q[i].r; j++)
                    add(fval[j], 1);
                curl = q[i].l; curr = q[i].r;
            }
            ans[q[i].id] = pval[findkth(q[i].k)];
        }
        for(int i = 0; i < m; i++)
            printf("%d\n", ans[i]);
    }
    return 0;
}
