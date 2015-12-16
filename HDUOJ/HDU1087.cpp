#include "cstdio"
#include "cstring"
#include "iostream"
using namespace std;
int main()
{
    //freopen("1.in","r",stdin);
    int n, a[1005];
    while(~scanf("%d",&n) && n!=0)
    {
        int i, j;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        int sum[1005], max;
        sum[0] = a[0];
        max = sum[0];
        for(i=1;i<n;i++)
        {
            int f = 0;
            for(j=0;j<i;j++)
            {
                if(a[j] < a[i] && sum[j] > f)
                    f = sum[j];
            }
            sum[i] = f + a[i];
            //printf("sum[%d] = %d\n",i,sum[i]);
            if(sum[i] > max)
            {
                max = sum[i];
            }
        }
        printf("%d\n", max);
    }
}
