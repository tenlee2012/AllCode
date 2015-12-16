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

const int MAXN=5000;
const double PI=acos(-1.0);

struct point
{
    int x,y;
};
point list[MAXN];
int stack[MAXN],top;

int cross(point p0,point p1,point p2) //计算叉积  p0p1 X p0p2 
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}    
double dis(point p1,point p2)  //计算 p1p2的 距离 
{
    return sqrt((double)(p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
}    
bool cmp(point p1,point p2) //极角排序函数 ， 角度相同则距离小的在前面 
{
    int tmp=cross(list[0],p1,p2);
    if(tmp>0) return true;
    else if(tmp==0&&dis(list[0],p1)<dis(list[0],p2)) return true;
    else return false;
}    
void init(int n) //输入，并把  最左下方的点放在 list[0]  。并且进行极角排序 
{
    int i,k;
    point p0;
    scanf("%d%d",&list[0].x,&list[0].y);
    p0.x=list[0].x;
    p0.y=list[0].y;
    k=0;
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&list[i].x,&list[i].y);
        if( (p0.y>list[i].y) || ((p0.y==list[i].y)&&(p0.x>list[i].x)) )
        {
            p0.x=list[i].x;
            p0.y=list[i].y;
            k=i;
        }    
    }    
    list[k]=list[0];
    list[0]=p0;
    
    sort(list+1,list+n,cmp);
}     

void graham(int n)
{
    int i;
    if(n==1) {top=0;stack[0]=0;}
    if(n==2)
    {
        top=1;
        stack[0]=0;
        stack[1]=1;
    }    
    if(n>2)
    {
        for(i=0;i<=1;i++) stack[i]=i;
        top=1;
        
        for(i=2;i<n;i++)
        {
            while(top>0&&cross(list[stack[top-1]],list[stack[top]],list[i])<=0) top--;
            top++;
            stack[top]=i;
        }    
    }    
}    

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    int iCase = 0;
    scanf("%d",&T);
    int n;
    while(T--){
        iCase++;
        scanf("%d",&n);
        init(4*n);
        graham(4*n);
        double ans = 1e20;
        stack[top+1] = 0;
        for(int i = 0;i <= top;i++){
            double x1 = list[stack[i]].x;
            double y1 = list[stack[i]].y;
            double x2 = list[stack[i+1]].x;
            double y2 = list[stack[i+1]].y;
            double Min1 = 1e30, Max1 = -1e30;
            double Min2 = 1e30, Max2 = -1e30;
            for(int i = 0;i <= top;i++){
                double x0 = list[stack[i]].x;
                double y0 = list[stack[i]].y;
                double tmp1 = -(y2-y1)*x0 + (x2-x1)*y0;
                double tmp2 = -(x2-x1)*x0 - (y2-y1)*y0;
                Min1 = min(Min1,tmp1);
                Max1 = max(Max1,tmp1);
                Min2 = min(Min2,tmp2);
                Max2 = max(Max2,tmp2);
            }
            double a = y2-y1;
            double b = x2-x1;
            ans = min(ans,(Max1-Min1)*(Max2-Min2)/(a*a+b*b));
        }
        printf("Case #%d:\n%.0lf\n",iCase,ans);
    }
    
    return 0;
}