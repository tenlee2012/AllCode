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
const int maxn = 30;

int a[maxn], n, pos[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            pos[a[i]] = i;
        }
        int ans = 0;
        pos[0] = 0;
        for(int i = n-1; i > 0; i--)
        {
            //printf("i %d, pos %d\n", i, pos[i]);
            //printf("i+1 %d, pos %d\n", i+1, pos[i+1]);
            if(pos[i] > pos[i+1])
            {
                ans = i; break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
