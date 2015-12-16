#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>
using namespace std;

const int maxn = 20;
const int INF = 1000000+10;

int cap[maxn][maxn]; //流量
int flow[maxn][maxn]; //容量
int a[maxn]; //a[i]：从起点 s 到 i 的最小容量
int p[maxn]; //p[i]: 记录点 i 的父亲
int s, t, n, m;
int Augment()
{
    queue<int> q;
    memset(a,0,sizeof(a)); //每次找增广路初始化最小残量为 0 ,所以 a[i] 同时可做标记数组
    a[s] = INF; // 起点残量无限大
    q.push(s);  // 起点入队
    while(!q.empty()) // 当队列非空
    {
        int u = q.front(); 
        q.pop(); // 取出队首并弹出
        for(int v = 1; v <= n; v++) 
            if(!a[v] && cap[u][v] > flow[u][v]) //找到新节点 v
            {
                p[v] = u; q.push(v); // 记录 v 的父亲,并加入 FIFO 队列
                a[v] = min(a[u], cap[u][v]-flow[u][v]); // s-v 路径上的最小残量【从而保证了最后,每条路都满足a[t]】
            }
    }

    if(a[t] == 0) return 0; // 找不到, 则当前流已经是最大流, 跳出循环

    for(int u = t; u != s; u = p[u]) // 从汇点往回走
    {
        flow[p[u]][u] += a[t]; //更新正向流
        flow[u][p[u]] -= a[t]; //更新反向流
    }
    return a[t];
}
int main()
{
    int T;
    scanf("%d", &T);
    for(int test = 1; test <= T; test++)
    {
        scanf("%d %d", &n,&m);
        memset(cap, 0, sizeof(cap)); //初始化容量为 0
        memset(flow, 0, sizeof(flow)); // 初始化流量为 0

        int x, y, c;
        for(int i = 1; i <= m; i++)
        {
            scanf("%d %d %d", &x, &y, &c);
            cap[x][y] += c; // 因为可能会出现两个点有多条边的情况,所以需要全部加起来
        }
         s = 1, t = n; // 第一个点为起点, 第 n 个点为终点

        int f = 0; // 总流量
        int yy;
        while(yy = Augment())// BFS找增广路
        {
            
            f += yy; // 更新从 s 流出的总流量

        }
        printf("Case %d: %d\n", test, f);

    }
    return 0;
}
