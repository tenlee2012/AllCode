//Author LJH
//www.cnblogs.com/tenlee
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
#define clc(a, b) memset(a, b, sizeof(a))
using namespace std;

const int inf = 0x3f;
const int INF = 0x3f3f3f3f;
const int maxn = 105;

int a[maxn][maxn][maxn], n;

int lowbit(int x)
{
    return x & -x;
}

void Add(int x, int y, int z, int val)
{
    int yy = y, zz = z;
    while(x <= maxn)
    {
        yy = y;
        while(yy <= maxn)
        {
            zz = z;
            while(zz <= maxn)
            {
                a[x][yy][zz] += val;
                zz += lowbit(zz);
            }
            yy += lowbit(yy);
        }
        x += lowbit(x);
    }
}

int Sum(int x, int y, int z)
{
    int yy = y, zz = z, ans = 0;
    while(x)
    {
        yy = y;
        while(yy)
        {
            zz = z;
            while(zz)
            {
                ans += a[x][yy][zz];
                zz -= lowbit(zz);
            }
            yy -= lowbit(yy);
        }
        x -= lowbit(x);
    }
    return ans;
}

int main()
{
    int m, op, x1, y1, z1, x2, y2, z2;
    while(~scanf("%d %d", &n, &m))
    {
        memset(a, 0, sizeof(a));
        while(m--)
        {
            scanf("%d", &op);
            if(op == 1)
            {
                scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
                x1++ , y1++ , z1++;  
                x2++ , y2++ , z2++;  
                // up  
                Add(x1 , y1 , z1 , 1);   
                Add(x1 , y2+1 , z1 , -1);   
                Add(x2+1 , y1 , z1 , -1);   
                Add(x2+1 , y2+1 , z1 , 1);   
                // down  
                Add(x1 , y1 , z2+1 , -1);   
                Add(x1 , y2+1 , z2+1 , 1);   
                Add(x2+1 , y1 , z2+1 , 1);   
                Add(x2+1 , y2+1 , z2+1 , -1); 
            }
            else 
            {
                scanf("%d %d %d", &x1, &y1, &z1);
                x1++; y1++; z1++;
                printf("%d\n", Sum(x1, y1, z1) % 2);
            }
        }
    }
}
