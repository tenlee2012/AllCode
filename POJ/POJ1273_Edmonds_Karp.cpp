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
const int maxn = 305;

int G[maxn][maxn];
int Prev[maxn]; //路径上每个节点的前驱结点
bool Visit[maxn];
int n, m;

int Augment()
{
    int v, i;
    deque <int> q; //双端队列
    memset(Prev, 0, sizeof(Prev));
    memset(Visit, 0, sizeof(Visit));
    Prev[1] = 0;
    Visit[1] = 1;
    q.push_back(1); //向双端队列 队尾放入一个元素
    bool bFindPath = false;
    //用BFS寻找一条从源到汇的可行路
    while(!q.empty())
    {
        v = q.front(); //双端队列 队头元素
        q.pop_front();
        for(int i = 1; i <= m; i++)
        {
            if(G[v][i] > 0 && !Visit[i])//边有流量且没有走过
            {
                Prev[i] = v;
                Visit[i] = 1;
                if(i == m)
                {
                    bFindPath = true;
                    q.clear();
                    break;
                }
                else
                {
                    q.push_back(i);
                }
            }
        }
    }
    if(!bFindPath) return 0;
    int nMinFlow = INF;
    v = m;
    //寻找源到汇路径上容量最小的边，其容量就是此次增加的总流量
    while(Prev[v])
    {
        nMinFlow = min(nMinFlow, G[Prev[v]][v]);
        v = Prev[v];
    }
    
    v = m;
    //沿此路径添加反向边，同时修改路径上每条边的容量
    while(Prev[v])
    {
        G[Prev[v]][v] -= nMinFlow;
        G[v][Prev[v]] += nMinFlow;
        v = Prev[v];
    }
    return nMinFlow;
}

int main()
{
    while(~scanf("%d %d", &n, &m))
    {
        int i, j, k, s, e, c;
        memset(G, 0, sizeof(G));
        for(i = 0; i < n; i++)
        {
            scanf("%d %d %d", &s, &e, &c);
            G[s][e] += c; //两点之间可能有多条边
        }
        int MaxFlow = 0;
        int aug;
        while(aug = Augment())
            MaxFlow += aug;
        printf("%d\n", MaxFlow);
    }
    return 0;
}
