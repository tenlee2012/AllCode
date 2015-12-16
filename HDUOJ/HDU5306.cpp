#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
  long long sum;
  int tag,maxtag,mmax,cover,s;
}q[5000100];
int num[5000100];
node  pushdown(node c,int t)  //处理标记及标记覆盖范围
{
    if(!t) return c;
    if(c.cover!=c.s) c.mmax=t;
    c.maxtag=t;
    c.sum+=1LL*(c.s-c.cover)*t;
    c.cover=c.s;
    return c;
}
node pushup(node a,node b,int t) //向上更新
{
    node c;
    c.tag=t;
    c.s=a.s+b.s;
    c.sum=a.sum+b.sum;
    c.cover=a.cover+b.cover;
    c.mmax=max(a.mmax,b.mmax);
    c.maxtag=max(a.maxtag,b.maxtag);
    return pushdown(c,t);
}
void build(int l,int r,int pos)
{
    q[pos].tag=0;
    q[pos].s=r-l+1; //区间长度
    if(l<r){
        int mid=(l+r)/2;
        build(l,mid,pos*2);
        build(mid+1,r,pos*2+1);
        q[pos]=pushup(q[pos*2],q[pos*2+1],0);
    }
    else{
        q[pos].mmax=q[pos].sum=q[pos].maxtag=q[pos].tag=num[l];
        q[pos].cover=1;
    }
}
void cl(int k,int t)
{
    if(q[k].maxtag<t) return;//若已经是最小，则返回
    if(q[k].tag>=t){  
        q[k].tag=0;
    }
    if(q[k].s>1){  //区间长度大于1
        cl(k*2,t);
        cl(k*2+1,t);
    }
    if(q[k].s==1){ //处理点
        q[k].sum=q[k].mmax=q[k].maxtag=q[k].tag;
        q[k].cover=(q[k].tag>0); //决定是否覆盖
    }
    else{ //更新
        q[k]=pushup(q[k*2],q[k*2+1],q[k].tag);
    }
}
void update(int L,int R,int t,int l,int r,int pos)
{
    if(q[pos].tag&&q[pos].tag<=t) return; //已是最小，则不用update
    if(L<=l&&r<=R){  
        cl(pos,t);  //区间处理
        q[pos].tag=t;
        if(l==r){
            q[pos].mmax=q[pos].maxtag=q[pos].sum=q[pos].tag=t;
            q[pos].cover=(q[pos].tag>0); //是否覆盖
        }
        else{
            q[pos]=pushup(q[pos*2],q[pos*2+1],t);
        }
    }
    else{
        int mid=(l+r)/2;
        if(R<=mid) update(L,R,t,l,mid,pos*2);
        else if(mid<L) update(L,R,t,mid+1,r,pos*2+1);
        else update(L,R,t,l,mid,pos*2),update(L,R,t,mid+1,r,pos*2+1);
        q[pos]=pushup(q[pos*2],q[pos*2+1],q[pos].tag);
    }
}
node query(int L,int R,int l,int r,int pos)
{
    if(L<=l&&r<=R){
      return q[pos];
    }
    int mid=(l+r)/2; 
    if(R<=mid) return pushdown(query(L,R,l,mid,pos*2),q[pos].tag); //查询时，区间处理
    if(mid<L) return pushdown(query(L,R,mid+1,r,pos*2+1),q[pos].tag);
    return pushup(query(L,R,l,mid,pos*2),query(L,R,mid+1,r,pos*2+1),q[pos].tag);
}
int main()
{
    int t,n,m,i,j,k,temp;
    int a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            scanf("%d",&num[i]);
        build(1,n,1);
        for(i=0;i<m;i++)
        {
            scanf("%d",&temp);
            if(temp==0){
              scanf("%d%d%d",&a,&b,&c);
              update(a,b,c,1,n,1);
            }
            else if(temp==1){
              scanf("%d%d",&a,&b);
              printf("%d\n",query(a,b,1,n,1).mmax);
            }
            else{
              scanf("%d%d",&a,&b);
              printf("%lld\n",query(a,b,1,n,1).sum);
            }
        }
    }
    return 0;
}