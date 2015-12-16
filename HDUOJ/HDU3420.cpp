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
int fri[maxn], n;

int main()
{
    int T;
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &fri[i]);
        }
        sort(fri, fri+n);
        int sum = fri[0] * n;
        for(int i = 1; i < n; i++)
        {
            int t = fri[i] * (n - i);
            if(t > sum) sum = t;
        }
        printf("%d\n", sum);
    }
    return 0;
}
