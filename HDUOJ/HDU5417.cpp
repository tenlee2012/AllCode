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

int x, y, w, n;
int slove()
{
    int i = 1, ans = 0;
    //if(n == 1) return 0;
    if(w > x) return (n-1)* (x+y);
    int k = x / w; 
    while(i < n)
    {
        if(i + k >= n) 
        {
            ans += w * (n-i);
            i = n;
        }           
        else
        {
            ans += x + y;
            i += k;
        }
        i++;
    }
    return ans;
}
int main()
{
    while(~scanf("%d %d %d %d", &x, &y, &w, &n))
    {
        printf("%d\n", slove());
    }
}
