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
const int maxn = 2e5+5;

char bin[maxn];
LL val[maxn];
int gry[maxn];
int n;

void slove()
{
    int k = 0;
    LL sum = 0;
    int pre = 0, end;
    LL mi = INF;
    for(int i = 1; i < n; i++)
    {
        if(bin[i] == '?')
        {
            k = 0;
            pre = bin[i-1] - '0';
            mi = val[i-1];
            while(bin[i] == '?' && i < n)
            {
                k++;
                mi = mi < val[i-1] ? mi : val[i-1];
                sum += val[i-1];
                i++;
            }
            if(i == n) break;
            sum += val[i-1];
            mi = mi < val[i-1] ? mi : val[i-1];
            end = bin[i] - '0';
            if(k%2 == 0 && end == pre) // 偶数个,两边要不同, 若同则减
            {
                sum -= mi;
            }
            if(k%2 == 1 && end != pre)
            {
                sum -= mi;
            }
            //printf("sum = %lld, k %d, i %d n %d e %d p %d\n", sum, k, i, n, end, pre);
            continue;
        }

        gry[i-1] = (bin[i] - '0') ^ (bin[i-1] - '0');
        if(gry[i-1]) sum += val[i-1];
        //printf("sum = %lld, i = %d\n", sum, i);
    }
    printf("%lld\n", sum);
}

int main()
{
    int T;
    scanf("%d", &T);
    bin[0] = '0';
    for(int t = 1; t <= T; t++)
    {
        scanf("%s", bin+1);
        n = strlen(bin);

        for(int i = 0; i < n-1; i++)
        {
            scanf("%lld", &val[i]);
        }

        printf("Case #%d: ", t);
        slove();
    }
    return 0;
}
