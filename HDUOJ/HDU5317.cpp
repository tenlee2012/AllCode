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
const int maxn = 1e6+5;
int nu[maxn], s[maxn][10], ha[10];
int p[8] = {1, 2, 4, 8, 16, 32, 64, 128};

void Init()
{
    clc(nu, 0);
    clc(s, 0);
    for(int i = 2; i < maxn; i++)
    {
        if(nu[i]) continue;
        nu[i] = 1;
        for(int j = 2; j * i < maxn; j++)
        {
            nu[j*i]++;
        }
    }
    s[2][1] = 1;
    for(int i = 3; i < maxn; i++)
    {
        for(int j = 1; j <= 7; j++)
        {
            s[i][j] = s[i-1][j];
        }
        s[i][nu[i]]++;   
    }
}

int GCD(int x, int y)
{
    return y == 0 ? x : GCD(y, x%y);
}
int main()
{
    int l, r, T, k;
    int nlr[10], a[20];
    Init();
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &l, &r);
        k = 0;
        for(int i = 1; i <= 7; i++)
        {
            nlr[i] = s[r][i] - s[l][i];
            if(i == nu[l] ) nlr[i]++;
            //printf("i = %d, %d\n", i, nlr[i]);
            if(nlr[i] >= 2)
            {
                a[k++] = i; a[k++] = i;
            }
            else if(nlr[i] == 1)a[k++] = i;
        }
        int ma = 1;
        for(int i = 0; i < k-1; i++)
        {
            for(int j = i+1; j < k; j++)
            {
                ma = max(GCD(a[i], a[j]), ma);
            }
        }
        printf("%d\n", ma);
    }
    return 0;
}
