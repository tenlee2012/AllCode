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
const int maxn = 1e6+5;

inline int mymin(int x, int y)
{
    return x < y ? x : y;
}
inline int mymax(int x, int y)
{
    return x > y ? x : y;
}

int main()
{
    //freopen("Mul2/data/data1002/b.in", "r", stdin);
    //freopen("2.out", "w", stdout);
    int n, m, x, y;
    int le, ri, up, down;
    int e, f, g;
    int ans = 0;
    while(~scanf("%d %d %d %d", &m, &n, &x, &y))
    {
        if(m > n)//n为长边,m为短边
        {
            swap(n, m); swap(x, y);
        }
        le = y - 1;//删除的格子距左端的距离 
        ri = n - y; //删除的格子距右端的距离 
        e = mymin(le, ri);

        up = x - 1; //删除的格子距上端的距离 
        down = m - x;//删除的格子距下端的距离 
        f = mymax(up, down);

        g = mymin(e+1, f);
        ans = (m+1) / 2;//没有删除格子时，最小的面积
        if(le == ri && ri == up && up== down)//如果n，m为奇数，且删除的格子在正中间
        {
            printf("%d\n", le);
        }
        else
        {
            printf("%d\n", mymax(ans, mymin(e+1, f)));
        }
    }
    return 0;
}

