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
const int maxn = 50;
LL D;
int S1, S2;

inline int get11(LL num)
{
    int s = 0;
    while(num)
    {
        if(num & 1)
        {
            s++;
        }
        num = num >> 1;
        //printf("num = %lld %d\n", num, s);
    }
    return s;
}
int main()
{
    int T;
    scanf("%d", &T);
    for(int tt = 1; tt <= T;  tt++)
    {
        scanf("%lld %d %d", &D, &S1, &S2);
        int k = get11(D+1), n1, numD;
        LL p = 0, kk = 0, m, yy, ans;
        if(k < S1 || k > S2) // 加 1 就少了 或者多了，不符合题意了 
        {
            numD = 0; yy = D;
            p = 1; n1 = -1;
            kk = 0;
            if(yy & 1)
            {
                n1++; kk += 1; numD++;
            }
            yy >>= 1;
            while(!(yy & 1))
            {
                p = p << 1;
                yy = yy >> 1;
            }
            int ff = 1;
            while(yy)
            {
                if(ff)  p = p << 1;
                if(yy & 1) numD++;
                else  ff = 0;
                if(ff)
                {
                    n1++; kk += p;
                }
                yy = yy >> 1;
            }
            if(ff) p = p << 1;
            m = D + p - kk;
            if(numD == 1)
            {
                m = D << 1; n1 = 0;
            }
            //printf("m = %lld, %lld, %lld n1 = %d %d\n", m, p, kk, n1, numD);
            if(numD - n1 >= S1)
            {
                ans = m;
            }
            else
            {
                int f = S1 - (numD - n1);
                LL  xx = 1;
                for(int i = 0; i < f; i++)
                {
                    m += xx;
                    xx = xx << 1;
                }
                ans = m;
            }
        }
        else 
        {
            ans = D+1;
        }
        printf("Case #%d: %lld\n", tt, ans);
    }
    return 0;
}
