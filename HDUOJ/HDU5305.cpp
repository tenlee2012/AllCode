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
const int maxn = 10;
int du_on[maxn], du_off[maxn], g[maxn][maxn];
int n, m, ans;

void dfs(int x, int y)
{
    if(x > n) ans++;
    else if(y > n)
    {
        if(du_on[x] != du_off[x]) return; //如果一个人的在线朋友和离线朋友不相等,直接退出，
        dfs(x+1, x+2);
    }
    else 
        if(g[x][y])
        {
            du_on[x]++; du_on[y]++;//在线朋友个数加一
            dfs(x, y+1);
            du_on[x]--; du_on[y]--;//还原回来，因为下面的dfs可能会用到

            du_off[x]++; du_off[y]++;
            dfs(x, y+1);
            du_off[x]--; du_off[y]--;
        }
        else 
            dfs(x, y+1);

}

int main()
{
    int T, x, y;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &m);
        clc(du_on, 0);
        clc(du_off, 0);
        clc(g, 0);
        while(m--)
        {
            scanf("%d %d", &x, &y);
            g[x][y] = g[y][x] = 1;
        }
        ans = 0;
        dfs(1, 2);
        printf("%d\n", ans);
    }
}
