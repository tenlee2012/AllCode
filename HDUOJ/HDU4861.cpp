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

long long a[maxn], k, p;
void f()
{
    for(int i = 1; i <= k; i++)
    {
        a[i] = 0;
        for(int j = 1; j < p-1; j++)
        {
            a[i] = (a[i] + ((long long)pow((double)j, (double)i)) % p) % p; 
        }
        long long x = ((long long)pow((double)(p-1), (double)i)) % p;
        a[i] = (a[i] + x) % p;
        printf("%lld ", a[i]);
    } 
    puts("");
}
int main()
{
    while(~scanf("%lld %lld", &k, &p))
    {
        if(k/(p-1)&1) puts("YES");
        else puts("NO");  
    }
    return 0;
}
