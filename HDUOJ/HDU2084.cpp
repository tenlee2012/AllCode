#include "iostream"
#include "cstdio"
using namespace std;
int main()
{
    //freopen("1.in","r",stdin);
    int t;
    cin >> t;
    while(t--)
    {
        int n, i, j, max = 0;
        int a[105][105], sum[105][105];
        cin >> n;
        for(i=0;i<n;i++)
        {
            for(j=0;j<=i;j++)
            {
                cin >> a[i][j];
            }
        }
        if(n == 1)
        {
            printf("%d\n",a[0][0]);
            continue;
        }
        sum[0][0] = a[0][0];
        for(i=1;i<n;i++)
        {
            for(j=0;j<=i;j++)
            {
                if(j == 0)
                    sum[i][j] = sum[i-1][0];
                else if(j == i)
                    sum[i][j] = sum[i-1][j-1];
                else
                    sum[i][j] = sum[i-1][j-1]>sum[i-1][j]?sum[i-1][j-1]:sum[i-1][j] ;
                sum[i][j] += a[i][j];
                //printf("sum[%d][%d] = %d\n", i, j, sum[i][j]);
                if(i == n-1)
                {
                    if(sum[i][j] > max)
                        max = sum[i][j];
                }
            }
        }
        printf("%d\n", max);
    }
}