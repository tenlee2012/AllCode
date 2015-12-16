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

int a[maxn], c[maxn];
int n, m;

int lowbit(int x)
{
    return x & (-x);
}

void Build(int id, int val)
{
    a[id] = val;
    while(id <= n)
    {
        c[id] = max(c[id], val);
        id += lowbit(id);
    }
}

void Update(int id, int val)
{
    a[id] = val;
    int i = id, j, k;
    while(i <= n)
    {
        c[i] = a[i];
        if(lowbit(i) > 1) //c[i] 包含区间内元素个数
        {
            k = i - lowbit(i) + 1; // c[i] 所包含区间的左端点
            j = i - 1;
            while(j >= k) //向下查找
            {
                c[i] = max(c[i], c[j]);
                j -= lowbit(j);
            }
        } 
        i += lowbit(i); //向上更新
    }
}

int Query(int ll, int rr)
{
    int ans = a[rr];
    while(true)
    {
        ans = max(ans, a[rr]);
        if(ll == rr) break;

        rr--; //一定要先减
        while(rr-ll >= lowbit(rr)) //向下查询子区间
        {
            ans = max(ans, c[rr]);
            rr -= lowbit(rr);
        }
    }
    return ans;
}

int main()
{
    int x, y;
    char op;
    while(~scanf("%d %d",&n, &m))
    {
        clc(c, 0);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            Build(i, a[i]);
        }
        while(m--)
        {
            scanf(" %c %d %d", &op, &x, &y);
            if(op == 'Q')
            {
                printf("%d\n", Query(x, y));
            }
            else
            {
                Update(x, y);
            }
        }
    }
    return 0;
}
