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
const int maxn = 1e5+5;
const long long mod = 1e9+7;
int a[maxn], ha[maxn], l[maxn], r[maxn], pre[maxn];
vector<int> v[maxn];
void Init()
{
    v[1].push_back(1);
    for(int i = 2; i <= maxn; i++)
    {
        for(int j = 2; i*j <= maxn; j++)
        {
           v[j*i].push_back(i); 
        }
        v[i].push_back(1);
        v[i].push_back(i);
    }
}

int main()
{
    //freopen("1001.in", "r", stdin);
    int n, i, j, k = 0;
    long long ans;
    Init();
    while(~scanf("%d", &n))
    {
        for(i = 1; i <= n; i++)       
        {
            scanf("%d", &a[i]);
        }
        clc(pre, 0);
        for(i = 1; i <= n; i++)
        {
            l[i] = 1;
            k = a[i];
            for(j = 0; j < (int)v[k].size(); j++)
            {
                if(pre[v[k][j]] != 0)
                {
                    l[i] = max(l[i], pre[v[k][j]] + 1);
                }
            }
            //if(a[i] == a[i-1]) l[i] = i;
            pre[a[i]] = i;
        }
        clc(pre, 0);
        for(i = n; i > 0; i--)
        {
            r[i] = n;
            k = a[i];
            for(j = 0; j < (int)v[k].size(); j++)
            {
                if(pre[v[k][j]] != 0)
                {
                    r[i] = min(r[i], pre[v[k][j]] - 1);
                }
            }
            //if(a[i]==a[i+1]) r[i] = i;
            pre[a[i]] = i;
        }
        ans = 0;
        for(i = 1; i <= n; i++)
        {
            ans = (ans + (long long)( i - l[i] + 1) * (long long)(r[i] - i + 1) % mod) % mod;
            if(ans > mod) ans -= mod;
        }
        printf("%lld\n", ans % mod);
    }
    return 0;
}

