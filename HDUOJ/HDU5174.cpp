#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define maxn 2147483647
#define LL long long

LL c[105];
struct Num
{
    LL val, num;
} a[105];

inline int Judge(LL a, LL b, LL c)
{
    if ((a + b) % maxn == c)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int n, ca = 0;

    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &c[i]);
        }

        LL ans = 0, k = 0, t = 1;
        sort(c, c + n);
        a[0].val = c[0];

        for (int i = 1; i < n; i++)
        {
            if (c[i] != c[i - 1])
            {
                a[k].num = t;
                a[++k].val = c[i];
                t = 1;
            }
            else
            {
                t++;
            }
        }
        a[k].num = t;

        if(k == 0)
        {
            printf("Case #%d: %d\n", ++ca, -1);
            continue;
        }

        for (int i = 0; i <= k; i++)
        {
            if (i == 0)
            {
                if (Judge(a[n - 1].val, a[0].val, a[1].val))
                {
                    ans += a[i].num;
                }

                continue;
            }

            if (i == n - 1)
            {
                if (Judge(a[n - 2].val, a[n - 1].val, a[0].val))
                {
                    ans += a[i].num;
                }

                continue;
            }

            if (Judge(a[i - 1].val, a[i].val, a[i + 1].val))
            {
                ans += a[i].num;
            }

        }

        printf("Case #%d: %d\n", ++ca, ans);
    }
}
