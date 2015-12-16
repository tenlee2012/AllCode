#include <stdio.h>
#include <cmath>
#include <cstring>
using namespace std;
#define N 15
#define MOD 10000007
long long n, m, a[15];

void matric_mul(long long a[][N], long long b[][N]); //矩阵相乘
void makemat(long long mat[][N]); //构造矩阵
void pow(long long mat[][15]); //快速幂
void Printf(long long mat[][N]);

int main()
{
    long long mat[15][15];

    while (~scanf("%d %d", &n, &m))
    {
        int i, j, k;
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        if(m+n==0)
        {
            printf("0\n");
            continue;
        }
        a[0] = 23;
        a[n+1] = 3;
        makemat(mat);
        //Printf(mat);
        pow(mat);
    }
    return 0;
}
void makemat(long long mat[][N])
{
    int i, j;
    for (i = 0; i <= n+1; i++)
    {
        if (i == n+1)
        {
            for (j = 0; j < n+1; j++)
            {
                mat[i][j] = 0;
            }
                mat[i][j] = 1;
                break;
            }

        mat[i][0] = 10;
        for (j = 1; j <= n+1; j++)
        {
            if (j <= i )
            {
                mat[i][j] = 1;
                continue;
            }
            mat[i][j] = 0;
        }
        mat[i][n+1] = 1;
    }
}
void Printf(long long mat[][N])
{
    int i, j;
    for(i=0;i<=n+1;i++)
        {
            for(j=0;j<=n+1;j++)
            {
                printf("%d ", mat[i][j]);
            }
            printf("\n");
        }
}

void pow(long long mat[][15])
{
    long long b[15][15];

    for (int i = 0; i <= n+1; i++)
    {
        for (int j = 0; j <= n+1; j++)
        {
            if (i == j)
            {
                b[i][j] = 1;
                continue;
            }
            b[i][j] = 0;
        }
    }

    while (m)
    {
        if (m & 1)
        {
            matric_mul(b, mat);
        }

        matric_mul(mat, mat);

        m >>= 1;
    }
    //Printf(b);
    long long sum = 0;
    for (int i = 0; i <= n+1; i++)
    {
        sum += a[i]*b[n][i];
    }

    printf("%d\n", sum%MOD);
}

void matric_mul(long long a[][N], long long b[][N])
{
    int i, j, k;
    long long tmp1[N][N] = {0};

    for (i = 0; i <= n+1; i++)
    {
        for (j = 0; j <= n+1 ; j++)
        {
            for (k = 0; k <= n+1; k++)
            {
                tmp1[i][j] = (tmp1[i][j] + b[i][k] * a[k][j]) % MOD;
            }
            //printf("tem[%d][%d] = %d\n", i, j, tmp1[i][j]);
        }
    }

    for (i = 0; i <= n+1; i++)
    {
        for (j = 0; j <= n+1; j++)
        {
            a[i][j] = tmp1[i][j];
        }
    }
}

