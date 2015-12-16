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

LL n, zheng[maxn], fu[maxn], a, b;
LL ans;

bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int T, j, k;
    int ma, mi, x;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++)
    {
        scanf("%lld %lld %lld", &n, &a, &b);
        j = 0; k = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            mi = min(mi, abs(x));
            ma = max(ma, abs(x));
            if(x >= 0)
            {
                zheng[j++] = x;
            }
            else
            {
                fu[k++] = x;
            }
        }
        sort(zheng, zheng+j, cmp);
        sort(fu, fu+k, cmp);
        ans = 0;

        if(a < 0)
        {
            if(b >= 0)
            {
                if(k > 0 && j > 0)//正负都有
                {
                    if(abs(fu[0]) > zheng[j-1])
                    {
                        if(j == 1) ans = a * zheng[j-1] * zheng[j-1] + b * fu[0];
                        else ans = a * zheng[j-1] * zheng[j-1] + b * zheng[0];
                    }
                    else
                    {
                        ans = a * fu[0] * fu[0] + b * zheng[0];
                    }

                }
                else if(k > 0 && j < 1)//只有负数，没有证书 a < 0 b > 0
                {
                    ans = a * fu[0] * fu[0] + b * fu[1];
                }
                else if(k < 1 && j > 0)
                {
                    ans = a * zheng[j-1] * zheng[j-1] + b * zheng[0];
                }
            }
            else // a < 0 b < 0
            {
                if(k > 0 && j > 0)//正负都有
                {
                    if(abs(fu[0]) < zheng[j-1])
                    {
                        if(k == 1) ans = a * fu[0] * fu[0] + b * zheng[j-1];
                        else ans = a * fu[0] * fu[0] + b * fu[k-1];
                    }
                    else
                    {
                        ans = a * zheng[j-1] * zheng[j-1] + b * fu[k-1];
                    }
                }
                else if(k > 0 && j < 1)//只有负数，没有证书
                {
                    ans = a * fu[0] * fu[0] + b * fu[k-1];
                }
                else if(k < 1 && j > 0) //只有正数，没有负数
                {
                    ans = a * zheng[j-1] * zheng[j-1] + b * zheng[j-2];
                }
            }
        }
        else // a > 0
        {
            if(b >= 0)  // a > 0 b >=0
            {
                //puts("a > 0 b > 0");
                if(k > 0 && j > 0)
                { 
                    if(zheng[0] > 0-fu[k-1])
                    {
                        if(j == 1) ans = a * zheng[0] * zheng[0] + b * fu[0];
                        else ans = a * zheng[0] * zheng[0] + b * zheng[1];
                    }
                    else 
                    {
                        ans = a * fu[k-1] * fu[k-1] + b * zheng[0];
                    }
                }
                else if(k > 1 && j < 1) //只有负数
                {
                    ans = a * fu[k-1] * fu[k-1] + b * fu[0];
                }
                else if(k < 1 && j > 1) //只有正数
                {
                    //puts("only >0");
                    ans = a * zheng[0] * zheng[0] + b * zheng[1];
                }
            }
            else  // a > 0 b < 0
            {
                //puts("a > 0 b< 0");
                if(k > 0 && j > 0)
                { 
                    if(zheng[0] < 0-fu[k-1])
                    {
                        if(k == 1) ans = a * fu[k-1] * fu[k-1] + b * zheng[j-1];
                        else ans = a * fu[k-1] * fu[k-1] + b * fu[k-2];
                    }
                    else 
                    {
                        ans = a * zheng[0] * zheng[0] + b * fu[k-1];
                    }
                }
                else if(k > 1 && j < 1) //只有负数 a > 0 b < 0
                {
                    //puts("only <0");
                    ans = a * fu[k-1] * fu[k-1] + b * fu[k-2];
                }
                else if(k < 1 && j > 1) //只有正数
                {
                    ans = a * zheng[0] * zheng[0] + b * zheng[j-1];
                }
            }
        }
        printf("Case #%d: %lld\n", t, ans);
    }
    return 0;
}
