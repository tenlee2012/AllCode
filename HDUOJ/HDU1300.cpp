#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int main()
{
    //freopen("1.in", "r", stdin);
    int t;
    scanf("%d",&t);

    while (t--)
    {
        int n, a[105][2], i, j, k;
        scanf("%d",&n);

        for (i = 1; i <= n; i++)
        {
            scanf("%d %d",&a[i][0], &a[i][1]);
        }

        int sum[105], s;
        sum[0] = 0;
        sum[1] = (a[1][0] + 10) * a[1][1];

        for (i = 2; i <= n; i++)
        {
            int min = 999999999;
            int s1 = sum[i-1] + (a[i][0] + 10) * a[i][1];
            for(j=1;j<i;j++)
            {
                s = 10;
                for(k=j;k<=i;k++)
                    s += a[k][0];

                int s2 = s * a[i][1] + sum[j-1];
                if(s2 < min) min = s2;
            }
            sum[i] = s1<min?s1:min;
            //printf("sum[%d] = %d\n", i, sum[i]);
        }

        printf("%d\n", sum[n]);
    }

    return 0;
}
