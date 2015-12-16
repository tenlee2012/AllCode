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
#define LL int
using namespace std;

const int inf = 0x3f;
const int INF = 0x3f3f3f3f;
const int maxn = 1e6+5;

LL n;
int t;

LL getSum(LL x)
{
    LL sum = 0;
    while(x)
    {
        sum += x % 10;
        x = x / 10;
    }
    return sum;
}
int getBit(LL x, LL len, LL &jsum, LL &osum)
{
    int i = 0, b= 0;
    LL k, y = x;
    while(y)
    {
        b++;
        y = y / 10;
    }
    while(x)
    {
        k = x % 10; 
        if((b+len-i)%2 == 0) osum += k;
        else jsum += k;
        x = x / 10;
        i++; 
    }
    return b;
}
bool slove()
{
    LL jsum = 0, osum = 0;
    LL sum = getSum(n), len = 0;
    len = getBit(n, len, jsum, osum);
    for(int i = 0; i < t; i++) 
    {
        len += getBit(sum, len, jsum, osum);
        //printf("%lld %lld %lld\n", sum, jsum, osum);
        sum = getSum(sum) + sum;
    }
    if(abs(jsum - osum) % 11) return false;
    else 
    {
        return true;
    }
}

int main()
{
    int tt = 1;
    while(~scanf("%d %d", &n, &t))
    {

        if(n == -1 && t == -1) break;
        if(slove())
        {
            printf("Case #%d: Yes\n", tt);
        }
        else 
        {
            printf("Case #%d: No\n", tt);
        }
        tt++;
    }
    return 0;
}
