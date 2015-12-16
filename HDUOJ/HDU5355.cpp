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
#define LL long long
using namespace std;

const int inf = 0x3f;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;

int ha[maxn];
vector<int>v[maxn];
LL n, m, size, sum;

void slove()
{
    for(int i = 0; i < m; i++)
        v[i].clear();
    LL su = 0, si = 0;
    LL k = n;
    LL ma = n;
    for(int i = 0; i < m; i++)
    {
        su = 0; si = size;
        k = ma;
        while(su < size && k > 0)
        {
            if(si - su - k >= 0 && !ha[k])
            {
                //printf("i = %d, k = %lld. size = %lld", i, k, size);
                v[i].push_back(k);
                ha[k] = 1;
                su += k;
                if(k == ma) ma--;
                //printf(" su = %lld\n", su);
            }
            else
            {
                k--;
            }
        }
        if(k <= 0)
        {
            puts("NO");
            return;
        }
    }
    int len = 0;
    for(int i = 0; i < m; i++)
    {
        len = (int)v[i].size();
        printf("%d ", len);
        for(int j = 0; j < len; j++)
        {
            printf("%d", v[i][j]);
            if(j != len-1) printf(" ");
        }
        puts("");
    }

}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lld %lld", &n, &m);
        if(n < m)
        {
            puts("NO"); continue;
        }
        sum = (n + 1) * n / 2;
        size = sum / m;
        if(size * m != sum || size < n)
        {
            puts("NO"); continue;
        }
        clc(ha, 0);
        slove();
    }
    return 0;
}
