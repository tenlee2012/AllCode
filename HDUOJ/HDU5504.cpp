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
const int maxn = 100;

int main()
{
    int T, n;
    LL x;
    int zi, fi, oi;
    LL sum, sum1, sum2, mi;
    scanf("%d", &T);
    while(T--)
    {
        zi = fi = oi = 0;
        sum1 = sum2 = 1;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%lld", &x);
            if(x > (LL)0)
            {
                zi++;
                sum1 *= x;
            }
            else if(x < (LL)0)
            {
                fi++;
                sum2 *= x;
                if(fi == 1)
                {
                    mi = x;
                }
                else
                {
                    mi = x > mi ? x : mi;
                }
            }
            else
            {
                oi++;
            }
        }
        if(n == 1)
        {
            printf("%lld\n", x);
            continue;
        }
        if(fi%2 == 0 && fi>0) // fi >= 2
        {
            sum = sum1 * sum2;
        }
        else if(fi%2 && fi>1) // fi >= 3
        {
            sum = sum1 * sum2 / mi;
        }
        else if(!zi && oi)
        {
            sum = 0;
        }
        else if(!zi && !oi)
        {
            sum = mi;
        }
        else 
        {
            sum = sum1;
        }
        printf("%lld\n", sum);
    }
}
