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
const int MOD = 10007;

char str[maxn];
int Next[maxn];

void get_Next()
{
    int i = 0, j = -1;
    Next[0] = -1;
    while(str[i])
    {
        if(j == -1 || str[i] == str[j])
        {
            i++; j++;
            Next[i] = j;
        }
        else 
        {
            j = Next[j];
        }
    }
}

int main()
{
    int T, n;
    int ans;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %s", &n, str);
        ans = n;
        memset(Next, 0, sizeof(Next));
        get_Next();
        for(int i = 1; i <= n; i++)
        {
            int tmp =  Next[i];
            while(tmp)
            {
                ans = (ans + 1) % MOD;
                tmp = Next[tmp];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

