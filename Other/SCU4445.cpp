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
const int maxn = 1e3+5;
int n;
struct Point
{
    int x, y, step, dir;
    bool operator < (const Point &a) const
    {
        if(x == a.x) {return y < a.y;}
    }
}p[maxn];
queue<Point> q;

int BFS()
{
    Point now, next, start;
    int i = 0, x, y, dir, step, ans = 0;
    start.x = 0; start.y = 0; start.step = 0;
    start.dir = 4;
    while(!q.empty()){ q.pop(); }
    q.push(start);
    while(!q.empty())
    {
        now = q.front(); q.pop();
        dir = now.dir, x = now.x, y = now.y, step = now.step;
        //printf("x = %d, y = %d, step = %d, dir = %d\n", x, y, step, dir);
        if(step >= 4 * n)
        {
            return -1;
        }
        else {}

        if(dir == 1) // 上 1 -> 右 4
        {
            for(i = 0; i < n; i++)
            {
                if(p[i].x == x && p[i].y > y) //他的前面有障碍
                {
                    next.x = p[i].x; next.y = p[i].y - 1;
                    next.dir = 4; next.step = step + 1;
                    break;
                }
            }
            if(i == n)
            {
                return step;
            }
            else 
            {
                q.push(next);
            }
        }
        else if(dir == 2)
        {
            for(i = 0; i < n; i++)
            {
                if(p[i].x == x && p[i].y < y)
                {
                    next.x = p[i].x; next.y = p[i].y + 1;
                    next.dir = 3; next.step = step + 1;
                    break;
                }
            }
            if(i == n)
            {
                return step;
            }
            else 
            {
                q.push(next);
            }
        }
        else if(dir == 3)
        {
            for(i = 0; i < n; i++)
            {
                if(p[i].x < x && p[i].y == y)
                {
                    next.x = p[i].x + 1; next.y = p[i].y;
                    next.dir = 1; next.step = step + 1;
                    break;
                }
            }
            if(i == n)
            {
                return step;
            }
            else 
            {
                q.push(next);
            }
        }
        else if(dir == 4)
        {
            for(i = 0; i < n; i++)
            {
                if(p[i].x > x && p[i].y == y)
                {
                    next.x = p[i].x - 1; next.y = p[i].y;
                    next.dir = 2; next.step = step + 1;
                    break;
                }
            }
            if(i == n)
            {
                return step;
            }
            else 
            {
                q.push(next);
            }
        }
    }
}
int main()
{
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &p[i].x, &p[i].y);
        }
        sort(p, p+n);
        printf("%d\n", BFS());
    }
    return 0;
}
