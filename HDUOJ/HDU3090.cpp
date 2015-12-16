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
struct Road
{
    int p, d;
    bool operator < (const Road &a) const
    {
        return p > a.p;
    }
}rd[maxn];

int main()
{
    int n, m;
    while(~scanf("%d %d", &n, &m) &&  m+n)
    {
        long long sum = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &rd[i].d, &rd[i].p);
            sum += (rd[i].d * rd[i].p);
        }
        sort(rd, rd+n);
        
        int i = 0;
        while(m >= 0 && sum && i<n)
        {
            int x = m - rd[i].d;
            if(x >= 0)
            {
                sum -= rd[i].d * rd[i].p;
                m = x;
            }
            else 
            {
                sum -= m * rd[i].p;
                m = 0;
            }
            i++;
        }
        printf("%lld\n", sum);
    }
    return 0;
}
