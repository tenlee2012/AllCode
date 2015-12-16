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

bool judge(int y)
{
    if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        return true;
    return false;
}
int main()
{
    int y, d, m;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d-%d-%d", &y, &m, &d);
        if(judge(y) && m == 2 && d == 29)
        {
            printf("-1\n");
            continue;
        }
        int ans = 0;
        if((judge(y) && m <= 2)) ans++;
        if(judge(y+18) && m >= 3) ans++;
        for(int i = y+1; i < y+18; i++)
        {
            if(judge(i))
                ans++;
        }
        printf("%d\n", ans + 365*18);
    }
}
