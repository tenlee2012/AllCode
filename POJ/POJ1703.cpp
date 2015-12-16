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

using namespace std;

const int inf = 0x3f;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;

int bleg[maxn], dis[maxn], n, q;

int find(int x)
{
    int y = x, cnt = 0;
    while(y != bleg[y])
    {
        cnt += dis[y];
        y = bleg[y];
    }
    while(x != bleg[x]) //路径压缩
    {
        int px = bleg[x], tmp = dis[x];
        dis[x] = cnt;
        bleg[x] = y;
        cnt -= tmp;
        x = px;
    }
    return x;
}

void Union(int a, int b)
{
    int pa = find(a), pb = find(b);
    if(pa == pb) return;
    dis[pa] = (dis[a] + dis[b] + 1) % 3;
    bleg[pa] = pb;
}

void Init()
{
    for(int i = 0; i <= n; i++)
    {
        bleg[i] = i; dis[i] = 0;
    }
}
int main()
{
    int T, t, f = 0;
    scanf("%d", &T);
    for(t = 1; t <= T; t++)
    {
        f = 0;
        scanf("%d %d", &n, &q);
        Init();
        while(q--)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            int pa = find(x), pb = find(y);
            if(pa != pb);
            else if((dis[x] + dis[y]) % 2 != 0);
            else 
            {
                f = 1;
            }
            Union(x, y);
        }
        printf("Scenario #%d:\n", t);
        if(f) puts("Suspicious bugs found!\n");
        else puts("No suspicious bugs found!\n");
    }
    return 0;
}
