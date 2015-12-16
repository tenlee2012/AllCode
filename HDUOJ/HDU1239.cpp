#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
int l = 0;
int prim[10005] = {1}, s[10005];
void prime()
{
    int i, j;

    memset(prim, 0, sizeof(prim));

    for (i = 2; i < 10005; i++)
    {
        if (prim[i])
        {
            continue;
        }

        for (j = i + i; j < 10005; j += i)
        {
            prim[j] = 1;
        }

        s[l++] = i;
    }
}

int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    prime();
    int m;
    double a , b;
    while (~scanf("%d %lf %lf", &m, &a, &b) && (m != 0 && a + b != 0))
    {
        int p = 0, q = 0;
        double x = a / b, y, max = 0;
        int i, j;

        for (i = 0; i < l; i++)
        {
            if (s[i] > m)
            {
                break;
            }
            else
            {

                for (j = i; j<l ; j++)
                {
                    y = (double)s[i] / s[j];

                    if (y >= x && s[i]*s[j] > q * p && s[i]*s[j] <= m)
                    {
                        p = s[i];
                        q = s[j];
                    }
                }
            }
        }

        printf("%d %d\n", p, q);

        /*int tp, tq ;
        for(p = l-1; p>=0; p--)
        {
            for(q = p; q>=0; q--)
            {
                if(s[p]>m || s[q]>m || s[q]*s[p]>m || (double)s[q]/s[p]<x)
                    continue;
                if(s[p]*s[q]>max)
                {
                    max = s[p]*s[q];
                    tp = s[q];
                    tq = s[p];
                }
            }
        }
        printf("%d %d\n", tp, tq);*/
    }
}
