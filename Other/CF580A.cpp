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
const int maxn = 1e6+5;

int n, a[maxn];

int main()
{
    while(~scanf("%d", &n))
    {
        int ans = 0, k = 1;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            if(i > 0 && a[i] >= a[i-1])
            {
                k++;
            }
            else
            {
                ans = max(k, ans);
                k = 1;
            }
        }
        ans = max(k, ans);
        printf("%d\n", ans);
    }
    return 0;
}
