/*
几何+重心
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
#include<queue>
//#include<map>
#include<math.h>
using namespace std;
typedef long long ll;
//typedef __int64 int64;
const int maxn = 50005;
const int inf = 0x7fffffff;
const double pi=acos(-1.0);
const double eps = 1e-8;
struct point {
    double x,y;
    bool operator < ( const point &l ) const {
     return y<l.y||( l.y==y&&x<l.x );
}
};
struct point2{
    double x,y,area;
};
point myp[ maxn ],res[ maxn ];
point2 b[ maxn ];//由一个三角形得到的新“点“

double xmult( point sp,point ep,point op ){
     return (sp.x - op.x) * (ep.y - op.y)-(ep.x - op.x) * (sp.y - op.y);
}

int graham( int n,point pnt[] ){
      int i, len, k = 0;
      int top = 1;
      sort(pnt, pnt + n);
      if (n == 0) return 0; res[0] = pnt[0];
      if (n == 1) return 1; res[1] = pnt[1];
      if (n == 2) return 2; res[2] = pnt[2];
      for (i = 2; i < n; i++) {
          while (top && xmult(res[ top ], pnt[ i ], res[top-1])>=0 )//( cross ： from top to i )
              top--;
          res[++top] = pnt[i];
      }
      len = top; res[++top] = pnt[n - 2];
      for (i = n - 3; i >= 0; i--) {
          while (top!=len && xmult(res[ top ], pnt[ i ], res[top-1])>=0 ) 
          top--;
          res[++top] = pnt[i];
      }
      return top; // 返回凸包中点的个数
 }//res 存储着凸包里面的点

point get_grav( int n,point p[] ){
    double ans_x,ans_y;
    double sum_Area=0;
    int cnt=0;//被切割为三角形的个数
    for( int i=2;i<n;i++ ){
        double tmp=xmult( p[ i-1 ],p[ i ],p[ 0 ] );
        b[ cnt ].x=p[ 0 ].x+p[ i-1 ].x+p[ i ].x;
        b[ cnt ].y=p[ 0 ].y+p[ i-1 ].y+p[ i ].y;
        b[ cnt ].area = tmp;
        sum_Area += tmp;
        cnt++;
    }
    ans_x=ans_y=0;
    for( int i=0;i<cnt;i++ ){
        ans_x+=b[ i ].x*b[ i ].area;
        ans_y+=b[ i ].y*b[ i ].area;
    }
    ans_x/=(3.0*sum_Area);
    ans_y/=(3.0*sum_Area);//重心坐标
    point grav;
    grav.x=ans_x,grav.y=ans_y;
    return grav;//返回重心坐标
}
double dist( point a,point b ){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
bool solve( point a,point b,point now ){//判断会不会出现钝角
    double dis1,dis2,dis3;
    dis1 = dist( a,b );
    dis2 = dist( a,now );
    dis3 = dist( b,now );
    if( (dis1+dis2-dis3>eps)&&(dis1+dis3-dis2>eps) ) 
        return true;//这两个角必须为锐角，才可能保证 now 这个点在a，b“之间“
    return false;
}
    
int main(){
    int ca;
    scanf("%d",&ca);
    while( ca-- ){
        int n;
        scanf("%d",&n);
        for( int i=0;i<n;i++ )
            scanf("%lf%lf",&myp[ i ].x,&myp[ i ].y);
        point grav;
        grav = get_grav( n,myp );
        int CNT = graham( n,myp );
        //printf("CNT:%d\n",CNT);
        //for( int i=0;i<CNT;i++ )
            //printf("%d:%lf %lf\n",i,res[i].x,res[i].y);
        //printf("grav:%lf %lf\n",grav.x,grav.y);
        int ans=0;
        res[ CNT ]=res[ 0 ];
        for( int i=1;i<=CNT;i++ ){
            if( solve( res[i-1],res[i],grav )==true )
                ans++;//,printf("ans:%d %d\n",i-1,i);
        }
        printf("%d\n",ans);
    }
    return 0;
}