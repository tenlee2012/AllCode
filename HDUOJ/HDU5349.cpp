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

int main()
{
    int op, n, x, ma;
    int num = 0;
    while(~scanf("%d", &n))
    {
        ma = -INF;
        num = 0;
        while(n--)
        {
            scanf("%d", &op);
            if(op == 1)
            {
                scanf("%d", &x);
                ma = x > ma ? x : ma;
                num++;
            }
            else if(op == 2)
            {
                if(num > 0)
                    num--;
                if(num == 0) 
                    ma = -INF;
            }
            else if(op == 3)
            {
                if(num == 0)
                {
                    printf("0\n");
                }
                else 
                    printf("%d\n", ma);
            }
        }
    }
    return 0;
}
