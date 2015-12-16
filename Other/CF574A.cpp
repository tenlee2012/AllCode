//Author LJH
//www.cnblogs.com/tenlee
//http://codeforces.com/problemset/problem/574/A
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
const int maxn = 1e2+5;

int a[maxn], n, m;

int slove()
{
    int ma = a[0], ans = 0;
    if(m > a[0])
        return 0;
    int samenum = 0, i = 0, j, k;
    if(n == 1)
    {
        return (ma - m) / 2 + 1;
    }
    while(1)
    {
        i = j = 0;
        ma = a[i];
        //printf("m = %d ma = %d ", m, ma);
        if(m > ma) return ans;
        samenum = 0;
        while(a[i] == a[j] && j < n)
        {
            samenum++;
            j++;
        }
        if(samenum == 1)
        {
            k = a[i] - a[i+1];
            if(m + k <= a[i+1])
            {
                ans += k;
                m += k;
            }
            else
            {
                k = (ma - m) / 2 + 1;
                ans += k;
                m += k;
            }
            a[i] -= k;
            continue;
        }
        //printf("same %d\n", samenum);
        if(ma - m < samenum)
        {
            ans += (ma - m) + 1;
            m += (ma - m) + 1;
        }
        else
        {
            for(k = 0; k < samenum; k++)
                a[i+k]--;
            ans += samenum;
            m += samenum;
        }
    }
    return 0;
}

bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    while(~scanf("%d", &n))
    {
        scanf("%d", &m);
        n--;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        sort(a, a+n, cmp);
        printf("%d\n", slove());
    }
    return 0;
}

