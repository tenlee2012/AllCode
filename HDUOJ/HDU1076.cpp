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
    int x, n;
    int T;
    scanf("%d", &T);
    while(T--) 
    {
        scanf("%d %d", &x, &n);
        int i = 1;
        while(!judge(x))
        {
            x++;
        }
        while(i < n)
        {
            x = x + 4;
            if(judge(x))
                i++;
        }
        printf("%d\n", x);
    }
    return 0;
}
