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
const int maxn = 30;

int a[maxn], ha[maxn];
int n, m, ans;

bool cmp(int x, int y)
{
    return x > y;
}
void dfs(int x, int len, int s)
{
    if(s == 0)
    {
        ans = min(len, ans);
        return;
    }
    if(len >= n) return;
    for(int i = x+1; i < n; i++)
    {
        dfs(i, len+1, s%a[i]);
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        sort(a, a+n, cmp);
        ans = maxn;
        for(int i = 0; i < n; i++)
        {
            dfs(i, 1, m%a[i]);
        }
        printf("%d\n", ans==30?-1:ans);
    }
    return 0;
}
