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
using namespace std;

const int inf = 0x3f;
const int INF = 0x3f3f3f3f;
const int maxn = 10;
int k, m;

void Init(int a[][maxn], int ans[][maxn])
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            a[i][j] = 0;
            if(j-1 == i)
            {
                a[i][j] = 1;
            }
        }
    }
    
    for(int i = 0; i < maxn; i++)
    {
        for(int j = 0; j < maxn; j++)
        {
            if(i == j)
                ans[i][j] = 1;
            else 
                ans[i][j] = 0;
        }
    }
}

void matrix_mul(int a[][maxn], int b[][maxn])
{
    int i, j, k;
    int tmp[maxn][maxn] = {0};
    for(i = 0; i < maxn; i++)
    {
        for(j = 0; j < maxn; j++)
        {
            for(k = 0; k < maxn; k++)
            {
                tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j] % m) % m;
            }
        }
    }
    for(i = 0; i < maxn; i++)
    {
        for(j = 0; j < maxn; j++)
        {
            a[i][j] = tmp[i][j];
        }
    }
    /*for(int i = 0; i < maxn; i++)
    {
        for(int j = 0; j < maxn; j++)
            printf("b %d ", a[i][j]);
        puts("");
    }*/
}

int quickPow(int a[maxn][maxn], int b[maxn], int ans[maxn][maxn], int n)
{
    /*for(int i = 0; i < maxn; i++)
    {
        for(int j = 0; j < maxn; j++)
            printf("%d ", a[i][j]);
        puts("");
    }*/
    while(n)
    {
        if(n & 1) matrix_mul(ans, a);
        matrix_mul(a, a);
        n >>= 1;
    }
    /*for(int i = 0; i < maxn; i++)
    {
        for(int j = 0; j < maxn; j++)
            printf("%d ", ans[i][j]);
        puts("");
    }*/
    
    int sum = 0;
    for(int i = 0; i < maxn; i++)
    {
        sum = (sum + i * ans[9][i]) % m;
    }
    return sum % m;
}

void func(int a[][maxn])
{
    int d[50];
    for(int i = 0; i < 10; i++)
        d[i] = i;
    for(int i = 10; i <= k; i++)
    {
        d[i] = 0;
        for(int j = 0; j < 10; j++)
        {
            d[i] = (d[i] + a[9][j] * d[i-j-1] % m) % m;
        }
        printf("%d#%d ", i, d[i]);
    }
    puts("");
}
int main()
{
    //freopen("1.txt", "r", stdin);
    int a[maxn][maxn], b[maxn], ans[maxn][maxn];
    while(~scanf("%d %d\n", &k, &m))
    {
        Init(a, ans);
        for(int i = 0; i < 10; i++)
        {
            scanf("%d", &a[9][9-i]);
        }
        //func(a);
        if(k >= 10)
            printf("%d\n", quickPow(a, b, ans, k-9));
        else 
            printf("%d\n", k%m);
    }
    return 0;
}
