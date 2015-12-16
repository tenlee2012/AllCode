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
const int maxn = 205;
int G[maxn][maxn], Prev[maxn];
bool visit[maxn];
queue<int> q;
int n, m;

int Augment();
bool bfs();

int main()
{
    int x, y, z;
    while(~scanf("%d %d", &m, &n))
    {
        memset(G, 0, sizeof(G));
        while(m--)
        {
            scanf("%d %d %d", &x, &y, &z);
            G[x][y] += z;
        }
        int MaxFlow = 0;
        int aug;
        while(bfs())//没有增广路径就找到了最大流
            MaxFlow += Augment();
        printf("%d\n", MaxFlow);
    }
}
//用BFS寻找增广路经
bool bfs()
{
    while(!q.empty()) q.pop();
    int v, i;
    memset(Prev, 0, sizeof(Prev));
    memset(visit, 0, sizeof(visit));
    Prev[1] = 0;
    visit[1] = 1;
    q.push(1);
    while(!q.empty())
    {
        v = q.front();
        q.pop();
        for(int i = 1; i <= n; i++)
        {
            if(G[v][i] > 0 && !visit[i])
            {
                Prev[i] = v; visit[i] = 1;
                if(i == n)
                {
                    return true;
                }
                else
                {
                    q.push(i);
                }
            }
        }
    } 
    return false;
}
//
int Augment()
{
    int nMinFlow = INF;
    int v = n;
    //这就是刚才用BFS找到的一条增广路径
    //寻找源到汇的路径上 容量最小的边，其容量就是此次增加的总流量
    while(Prev[v])
    {
        nMinFlow = min(nMinFlow, G[Prev[v]][v]);
        v = Prev[v];
    }
    
    v = n;
    //修该每条边的容量。添加反向边
    while(Prev[v])
    {
        G[Prev[v]][v] -= nMinFlow;
        G[v][Prev[v]] += nMinFlow;
        v = Prev[v];
    }
    return nMinFlow;
}
