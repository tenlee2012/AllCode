#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std ;

const int N = 7e2 + 11;
const int M = 2e5 + 11;
const int INF = 99999999;

int Head[N] , Next[M] , flow[M] , End[M]; 
int nedge;
int que[N] , dis[N];
int n, m, s, g, sum;

void add_edge(int a , int b , int c) 
{
    End[++nedge] = b;
    flow[nedge] = c;
    Next[nedge] = Head[a];
    Head[a] = nedge;
}

void init() 
{
    sum = 0;
    memset(Head , -1 , sizeof(Head));
    nedge = -1;
    s = 0 , g = 701;
    int floor = 200;
    int need, fir, fin;
    for(int i = 1 ; i <= n ; ++i) 
    {
        scanf("%d%d%d",&need ,&fir ,&fin);
        sum += need;
        add_edge(s, i, need);
        add_edge(i, s, 0);
        for(int j = fir; j <= fin; ++j) 
        {
            add_edge(i, j+floor, 1);
            add_edge(j+floor, i, 0);
        }
    }
    for(int i = 1; i <= 500; ++i) 
    {
        add_edge(i+floor, g, m);
        add_edge(g, i+floor, 0);
    }
}

bool bfs() 
{
    memset(dis, -1, sizeof(dis));
    dis[s] = 0;
    que[1] = s;
    int l = 0, r = 1;
    while(l < r) 
    {
        int u = que[++l];
        if(u == g) return true;
        for(int i = Head[u] ; i != -1 ; i = Next[i]) 
        {
            int v = End[i];
            if(dis[v] == -1 && flow[i] > 0) 
            {
                dis[v] = dis[u] + 1;
                que[++r] = v;
            }
        }
    }
    return false ;
}

int dfs(int u , int limit) 
{
    if(u == g || limit == 0) return limit;
    int f1 = 0 , f;
    for(int i = Head[u]; i != -1; i = Next[i]) 
    {
        int v = End[i];
        if(dis[v] == dis[u] + 1 && (f = dfs(v, min(limit, flow[i]))) > 0) 
        {
            flow[i] -= f;
            flow[i^1] += f;
            f1 += f;
            limit -= f;
            if(limit == 0) break;
        }
    }
    if(f1 == 0) dis[u] = 0;
    return f1;
}

void dinic() 
{
    int all = 0;
    while(bfs()) 
    {
        all += dfs(s, INF);
    }
    if(all == sum) printf("Yes\n\n");
    else printf("No\n\n");
}

int main() 
{
    //freopen("data.in" , "r" , stdin);
    int t, tt = 0;
    scanf("%d", &t);
    while(t--) 
    {
        scanf("%d %d", &n, &m);
        init();
        printf("Case %d: ", ++tt);
        dinic();
    }
}