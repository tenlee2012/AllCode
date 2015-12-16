#include <iostream>
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
const int maxn = 500;

int G[maxn][maxn];
bool visit[maxn];
int Layer[maxn];
int n, m; //
int cap[MAX][MAX];  
int lev[MAX];  
queue<int> q;  
int BFS(int s,int t)  
{  
    int u,v;  
    memset(lev,-1,sizeof(lev));  
    q.push(s);  
    lev[s] = 0;  
    while( !q.empty() )  
    {  
        u = q.front();  
        q.pop();  
        for(v=0; v<=t; v++)  
            if( cap[u][v] > 0 && lev[v] == -1 )  
            {  
                lev[v] = lev[u] + 1;  
                q.push(v);  
            }  
    }  
    return lev[t] != -1;  
}  
int Dinic(int s,int t)  
{  
    int a[MAX],cur[MAX];  
    int pre[MAX];  
    int flow = 0;  
    int i,u,flag,v,ag,k;  
    while( BFS(s,t) )  
    {  
        for(i=0; i<=t; i++)  
        {                   // cur里初始化是第一个节点哈   
            cur[i] = 0;     // DFS中，如果需要回溯，就回溯到cur中的节点。   
            a[i] = INT_MAX;  // a里面存的是剩余流量   
        }  
        u = s;  
        while(1)  
        {  
            flag = 0;  
            for(v=cur[u]; v<=t; v++)  
                if( cap[u][v] > 0 && lev[u] + 1 == lev[v] )  
                {  
                    flag = 1;  
                    break;  
                }  
            if( flag )  
            {  
                cur[u] = v + 1;  
                pre[v] = u;  
                a[v] = cap[u][v];  
                if( a[v] > a[u] )  
                    a[v] = a[u];  
                u = v;          // 从找到的节点后开始在层次图里找路   
                if( u == t )    // 找到t后，增广   
                {  
                    ag = a[t];  
                    flow += ag;  
                    for(v=t; v!=s; v=pre[v])  
                    {  
                        cur[pre[v]] = v;    //  退回上一步。。   
                        cap[pre[v]][v] -= ag;  
                        cap[v][pre[v]] += ag;  
                        a[v] -= ag;       
                        if( cap[pre[v]][v] == 0 )  
                            u = pre[v];  
                    }  
                }  
            }  
            else  
                if( u != s )    // 如果u ！= s 那么这条路走不通的话，从u的上一个节点继续找。   
                {  
                    lev[u] = INT_MAX;  // 相当于从层次图里删除这个节点。   
                    u = pre[u];  
                }  
                else  // 如果从源点找不到增广路，就结束咧。   
                    break;  
        }  
    }  
    return flow;  
}

int main()
{
    while(~scanf("%d %d", &n, &m))
    {
        int i, j, k, s, e, c;
        memset(G, 0, sizeof(G));
        for(int i = 0; i < n; i++)
        {
            cin >> s >> e >> c;
            G[s][e] += c;
        }
        cout << Dinic() << endl;
    }
    return 0;
}
/*
1 2 1
1 3 1
1 4 2
1 5 3
2 8 1
2 9 1
2 10 1
3 6 1
3 7 1
3 8 1
3 9 1
4 8 1
4 9 1
4 10 1
4 11 1
4 12 1
5 10 1
5 11 1
5 12 1
5 13 1
5 14 1
6 15 3
7 15 3
8 15 3
9 15 3
10 15 3
11 15 3
12 15 3
13 15 3
14 15 3
*/
