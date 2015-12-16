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
int L, R, ans;
bool flag;
inline bool judge(int l, int r)
{
    if(r < l || r < 0 || l < 0) return false;
    if(r > 2*R) return false;
    if(ans != -1 && r >= ans) return false;
    if(l == 0 && ans == -1)
    {
        ans = r;
        return false;
    }
    if(l == 0)
    {
        ans = min(ans, r);
        return false;
    }
    return true;
}
void dfs(int l, int r)
{
    if(r < l || r < 0 || l < 0) return;
    if(r > 2*R) return;
    if(ans != -1 && r >= ans) return;
    if(l == 0 && ans == -1)
    {
        ans = r;
        return;
    }
    if(l == 0)
    {
        ans = min(ans, r);
        return;
    }

    //printf("l = %d, r = %d\n", l, r);
    int x, y;
    // (x+r) / 2 + 1 = l
    x = (l - 1) * 2 - r;
    if(judge(x, r)) dfs(x, r);
    //(x+r-1) / 2 + 1 = l
    x = (l - 1) * 2 + 1 - r;
    if(judge(x, r)) dfs(x, r);
    //(l + y) / 2 = r
    y = 2 * r - l;
    if(judge(l, y)) dfs(l, y);
    //(l + y - 1) / 2 = r
    y = 2 * r + 1 - l;
    if(judge(l, y)) dfs(l, y);
}

int main()
{
    //freopen("1.out", "w", stdout);
    while(~scanf("%d %d", &L, &R))
    {
        flag = false;
        ans = -1;
        dfs(L, R);
        printf("%d\n", ans);
    }
    return 0;
}
