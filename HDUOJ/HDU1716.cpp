#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
int main()
{
    int a[500], y = 0;

    while (~scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]) && (a[0] + a[1] + a[2] + a[3] != 0))
    {
        if (y!=0)
        {
            printf("\n");
        }
        y++;
        int b[240]={0},c[500] = {0};
        int i, j, k = 0, t, f = 0;
        sort(a, a + 4);

        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                if ((i != j))
                    for (k = 0; k < 4; k++)
                    {
                        if (k != j && k != i)
                            for (t = 0; t < 4; t++)
                            {
                                if (t != i && t != j && t != k)
                                {
                                    int x = a[i] * 1000 + a[j] * 100 + a[k] * 10 + a[t];

                                    if (x >= 1000)
                                    {
                                        c[f++] = x;
                                    }

                                }
                            }
                    }

            }
        }
        k = 0;
        sort(c, c + f);
        for(i=0;i<f;i++)
        {
            if (((i == 0) || (c[i] != c[i - 1] && i > 0)))
            {
                b[k] = c[i];
                k++;
            }
        }
        for (i = 0; i < k; i++)
        {
            printf("%d", b[i]);
            if (i != k - 1)
            {
                if (b[i] / 1000 == b[i + 1] / 1000)
                {
                    printf(" ");
                }
                else
                {
                    printf("\n");
                }
            }
            else
            {
                printf("\n");
            }
        }
    }
}
