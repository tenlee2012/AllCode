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
const int maxn = 105;

int father[maxn], edge[maxn][maxn], head[maxn];

int Find(int x)
{
    if(x != father[x])
    {
        father[x] = Find(father[x]);
    }
    return father[x];
}

bool Union(int x, int y)
{
    int xx = Find(x), yy = Find(y);
    if(x == y) return false;
    else
    {
        father[xx] = yy;
    }
    return true;
}

void Init()
{
    for(int i = 0; i < maxn; i++)
    {
        father[i] = i;
        head[i] = -1;
    }
    memset(edge, 0, sizeof(edge));
}

bool check()
{
    int k = 0;
    for(int i = 0; i < maxn; i++)
    {
        if(head[i] == 0) k++;
        if(k > 1) return false;
    }
    return true;
}
int main()
{
    int a, b, t = 1;
    while(true)
    {
        Init();
        int flag = 0;
        while(scanf("%d %d", &a, &b) && (a + b) > 0)
        {
            if(edge[a][b] || edge[b][a] || head[b] == 1) // 只有一个入度，不能有重边，孩子不能回父亲
            {
                flag = 1; continue;
            }
            if(!Union(a, b)) // 子孙不能回祖宗，即没环
            {
                flag = 1; continue;
            }
            edge[a][b] = 1;
            if(head[a] == -1) head[a] = 0;
            head[b] = 1;
        }
        if(a + b < 0) break;

        if(!check()) flag = 1;
        if(flag)
            printf("Case %d is not a tree.\n", t++);
        else 
            printf("Case %d is a tree.\n", t++);
    }
    return 0;
}
