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
#define clc(a, b) memset(a, b, sizeof(a))
const int inf = 0x3f;
const int INF = 0x3f3f3f3f;
const int maxn = 1050;

int a[maxn][maxn], n;

void Init()
{
    clc(a, 0);
}

int lowbit(int x)
{
    return x & -x;
}
void Add(int x, int yy, int val)
{
    while(x <= n)
    {
        int y = yy;
        while(y <= n)
        {
            a[x][y] += val;
            y += lowbit(y);
        }
        x += lowbit(x);
    }
}

int Sum(int x, int y)
{
    int sum = 0, yy;
    while(x)
    {
        yy = y;
        while(yy)
        {
            sum += a[x][yy];
            yy -= lowbit(yy);
        }
        x -= lowbit(x);
    }
    return sum;
}
int main()
{
    int op, x, y, l, x1, y1, x2, y2, sum;
    while(~scanf("%d", &op))
    {
        scanf("%d", &n);
        if(op == 0) Init();
        while(true)
        {
            scanf("%d", &op);
            if(op == 1)
            {
                scanf("%d %d %d", &x, &y, &l);
                Add(x+1, y+1, l);
            }
            else if(op == 2)
            {
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                x1++; y1++; x2++; y2++;
                sum = Sum(x2, y2) - Sum(x1-1, y2) - Sum(x2, y1-1) + Sum(x1-1, y1-1);
                printf("%d\n", sum);
            }
            else break;
        }
    }
}
