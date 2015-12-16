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
#define LL long long
using namespace std;

const int inf = 0x3f;
const int INF = 0x3f3f3f3f;
const int maxn = 1e6+5;

int main()
{
    int n, x, t;
    while(~scanf("%d %d %d", &n, &x, &t))
    {
        if((n != 1) && (x == t))
        {
            puts("-1");
        }
        else if((x == 1) && (t == n))
        {
            puts("0");
        }
        else if((x == n) && (t == 1))
        {
            puts("0");
        }
        else if((x == 1) || (x == n))
        {
            puts("1");
        }
        else if(abs(x-t) == 1)
        {
            puts("1");
        }
        else 
        {
            puts("2");
        }
    }
    return 0;
}
