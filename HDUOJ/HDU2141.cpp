#include<stdio.h>
#include<stdlib.h>
#include <algorithm>
using namespace std;
#define MAX 501
#define MAXMAX 250001
#define LAR 1001
int a[MAX], b[MAX], c[MAX];
int lm[MAXMAX];
int s[LAR];

int cmp(const void * a, const void * b)
{
    return *(int *)a - *(int *)b;
}
int main()
{
    int l, m, n, ss,f = 1;

    while (~scanf("%d%d%d", &l, &m, &n))
    {
        int a[MAX], b[MAX], c[MAX];
        int lm[MAXMAX];
        int s[LAR];
        int i, j, k = 0,t = 0,bleg = 0;

        for (i = 0; i < l; i++)    scanf("%d", &a[i]);
        for (i = 0; i < m; i++)    scanf("%d", &b[i]);
        for (i = 0; i < n; i++)    scanf("%d", &c[i]);

        for (i = 0; i < l; i++)
        {
                for(j = 0; j < m; j++)
                {
                    lm[k++] = a[i] +b[j];
                }
        }

        scanf("%d", &ss);
        for (i = 0; i < ss; i++)
        {
            scanf("%d", &s[i]);
        }

        printf("Case %d:\n",f++);

        sort(lm, lm+k);

        for(i=0;i<ss;i++)
        {
            bleg = 0;                //printf("s[%d] = %d  k = %d\n",i,s[i],k);
            for(j=0;j<n;j++)
            {
                if(s[i] - c[j] >= lm[0] && s[i] - c[j] <= lm[k-1])
                {
                    int min = 0, max = k - 1, mid;
                    t = s[i] - c[j];
                    while (min <= max)
                    {
                        mid = (min + max) / 2;    //printf("t = %d min = %d,max = %d\n",t,min,max);    printf("mid = %d,lm[mid] = %d\n",mid,lm[mid]);
                        if (lm[mid] > t)
                        {
                            max = mid - 1;
                        }
                        else if (lm[mid] < t)
                        {
                            min = mid + 1;
                        }
                        else
                        {
                            bleg = 1;
                            break;
                        }
                    }
                }

                if (bleg == 1) break;

            }
        if (bleg == 1)
            printf("YES\n");
        else
            printf("NO\n");
        }

    }
return 0;
}