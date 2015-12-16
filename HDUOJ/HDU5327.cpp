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
int a[maxn], b[maxn], ha[20];

bool judge(int n)
{
    clc(ha, 0);
    int x, y;
       while(n)
        {
            x = n % 10;
            n = n / 10;
            if(ha[x]) return false;
            else ha[x] = 1;
        }
    return true;
}
void Init()
{
    clc(b, 0);
    a[0] = 1;
    for(int i = 1; i < maxn; i++)
    {
        a[i] = a[i-1];
        if(judge(i))
        {
            b[i] = 1;
            a[i]++;
        }
    }
}

int main()
{
    Init();
    int T;
    int x, y, ans;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &x, &y);
        ans = a[y] - a[x];
        if(b[x]) 
        {
            ans++;
        }
        printf("%d\n", ans);
    }
}
