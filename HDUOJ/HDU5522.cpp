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
const int maxn = 1e3+5;

int main()
{
    int a[maxn];
    int n;
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        bool ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                for(int k = 0; k < n; k++)
                    if(abs(a[i] - a[j]) == a[k] && (i!=j) && (j!=k) && (i!=k))
                    {
                        ans = 1;
                        break;
                    }
            }
        }
        if(ans) puts("YES");
        else puts("NO");
    }
    return 0;
}
