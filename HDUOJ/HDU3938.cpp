#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 10000+100
#define MAXM 50000+555
typedef long long LL;
int parent[MAXN];
int n,m,q;
LL path[MAXN];
struct Edge{
    int u,v,w;
}edge[MAXM];

struct Node{
    int id,len;
}p[MAXN];

int Find(int x)
{
    int s;
    for(s=x;parent[s]>=0;s=parent[s])
    ;
    while(x!=s){
        int tmp=parent[x];
        parent[x]=s;
        x=tmp;
    }
    return s;
}

int  Union(int u,int v)
{
    int r1=Find(u),r2=Find(v);
    if(r1==r2)return 0;
    int tmp=parent[r1]*parent[r2];
    if(parent[r1]<parent[r2]){
        parent[r1]+=parent[r2];
        parent[r2]=r1;
    }else {
        parent[r2]+=parent[r1];
        parent[r1]=r2;
    }
    return tmp;
}

int cmp1(const Edge &a,const Edge &b)
{
    return a.w<b.w;
}

int cmp2(const Node &a,const Node &b)
{
    return a.len<b.len;
}


int main()
{
    while(~scanf("%d%d%d",&n,&m,&q)){
        memset(parent,-1,sizeof(int)*(n+2));
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
        }
        sort(edge,edge+m,cmp1);
        for(int i=0;i<q;i++){
            scanf("%d",&p[i].len);
            p[i].id=i;
        }
        sort(p,p+q,cmp2);
        LL ans=0;
        int pos=0;
        for(int i=0;i<q;i++)
        {
            while(pos<m&&edge[pos].w<=p[i].len){
                ans+=Union(edge[pos].u,edge[pos].v);
                pos++;
            }
            path[p[i].id]=ans;
        }
        for(int i=0;i<q;i++)
            printf("%I64d\n",path[i]);
    }
    return 0;
}