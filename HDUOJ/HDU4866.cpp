#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int MAXN=200005;
const int M=MAXN*20;
int root[MAXN];
int lson[M], rson[M], sum[M], tot;
long long val[M];
struct LINE
{
    int x, d, id;
} line[MAXN];
int y[MAXN], ind[MAXN], to[MAXN];
bool cmp(LINE x1,LINE x2)
{
    return x1.x<x2.x;
}
bool cmp2(int a,int b)
{
    return y[a]<y[b];
}
int build(int l,int r)
{
    int _new=tot++;
    sum[_new]=val[_new]=0;
    if(l!=r){
        int mid;
        mid=(l+r)>>1;
        lson[_new]=build(l,mid);
        rson[_new]=build(mid+1,r);
    }
    return _new;
}
int update(int l,int r,int p,int num,int va,int rt)
{
    int _new=tot++;
    lson[_new]=lson[rt], rson[_new]=rson[rt], sum[_new]=sum[rt], val[_new]=val[rt];
    sum[_new]+=num;
    val[_new]+=va;
    if(l!=r){
        int mid=(l+r)>>1;
        if(p<=mid){
            lson[_new]=update(l,mid,p,num,va,lson[rt]);
        }else{
            rson[_new]=update(mid+1,r,p,num,va,rson[rt]);
        }
    }
    return _new;
}
long long query(int l,int r,int k,int rt)
{
    if(k==0) return 0;
    if(l==r) {
        return val[rt]/sum[rt]*k;
    }
    int mid=(l+r)>>1;
    if(k<=sum[lson[rt]]){
        return query(l,mid,k,lson[rt]);
    }else {
        return val[lson[rt]]+query(mid+1,r,k-sum[lson[rt]],rson[rt]);
    }
}
int main()
{
    int i, j, cnt, n, m, x, p, L, R, D, X, A, B, C, k;
    while(~scanf("%d%d%d%d",&n,&m,&x,&p))
    {
        cnt=0;
        tot=0;
        for(i=1;i<=n;i++){
            scanf("%d%d%d",&L,&R,&D);
            y[i]=D;
            ind[i]=i;
            ++cnt;
            line[cnt].x=L, line[cnt].d=D, line[cnt].id=i;
            ++cnt;
            line[cnt].x=R+1, line[cnt].d=-D, line[cnt].id=i;
        }
        sort(line+1,line+cnt+1,cmp);
        sort(ind+1,ind+n+1,cmp2);
        for(i=1;i<=n;i++) to[ind[i]]=i;
        root[0]=build(1,n);
        for(i=1;i<=cnt;i++){
            if(line[i].d>0)
                root[i]=update(1,n,to[line[i].id],1,line[i].d,root[i-1]);
            else root[i]=update(1,n,to[line[i].id],-1,line[i].d,root[i-1]);
        }
        int l, r, mid;
        long long pre=1, ret;
        int tt;
        for(i=1;i<=m;i++){
            scanf("%d%d%d%d",&X,&A,&B,&C);
            tt=0;
            k=(pre%C*A%C+B)%C;
            if(k==0){
                pre=0;
                puts("0");
                continue;
            }
            l=1, r=cnt;
            while(l<=r){
                mid=(l+r)>>1;
                if(line[mid].x<=X){
                    tt=mid;
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            ret=query(1,n,k,root[tt]);
            if(pre>p) ret*=2;
            pre=ret;
            printf("%I64d\n",ret);
        }
    }
    return 0;
}
