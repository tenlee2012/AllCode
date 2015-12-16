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

int a[maxn][maxn];

int lowbit(int x)
{
    return x & -x;
}

void Add(int x, int y, int val)
{
    int yy = y;
    while(x < maxn)
    {
        yy = y;
        while(yy < maxn)
        {
            a[x][yy] += val;
            yy += lowbit(yy);
        }
        x += lowbit(x);
    }
}

int Sum(int x, int y)
{
    int yy = y, ans = 0;
    while(x)
    {
        yy = y;
        while(yy)
        {
            ans += a[x][yy];
            yy -= lowbit(yy);
        }
        x -= lowbit(x);
    }
    return ans;
}

void Init()
{
    clc(a, 0);
    for(int i = 1; i < maxn; i++)
    {
        for(int j = 1; j < maxn; j++)
        {
            Add(i, j, 1);
        }
    }
}

int main()
{
    int T, q, x1, y1, x2, y2, n1, sum;
    char op;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++)
    {
        scanf("%d", &q);
        Init();
        printf("Case %d:\n", t);
        while(q--)
        {
            scanf(" %c", &op);
            if(op == 'S')
            {
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                x1++, y1++, x2++, y2++;
                int a1, b1, a2, b2;
                a1 = min(x1,x2); a2 = max(x1,x2);
                b1 = min(y1,y2); b2 = max(y1,y2);
                printf("%d\n",Sum(a2,b2) - Sum(a1-1,b2) - Sum(a2,b1-1) + Sum(a1-1,b1-1));
            }
            else if ( op == 'A' )
            {
                scanf("%d %d %d", &x1, &y1, &n1);
                Add(x1+1, y1+1, n1);
            }
            else if( op == 'D' )
            {
                int temp;
                scanf("%d %d %d", &x1, &y1, &n1);
                x1++, y1++;
                temp = Sum(x1,y1) - Sum(x1-1,y1) - Sum(x1,y1-1) + Sum(x1-1,y1-1);
                if(temp >= n1)
                    Add(x1, y1, -n1);
                else
                    Add(x1, y1, -temp);
            }
            else if(op == 'M')
            {
                scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &n1);
                x1++, y1++, x2++, y2++;
                int temp = Sum(x1,y1) - Sum(x1-1,y1) - Sum(x1,y1-1) + Sum(x1-1,y1-1);
                if(temp >= n1)
                {
                    Add(x1, y1, -n1);
                    Add(x2, y2, n1);
                }
                else
                {
                    Add(x1, y1, -temp);
                    Add(x2, y2, temp);
                }
            }
        }
    }
    return 0;
}
