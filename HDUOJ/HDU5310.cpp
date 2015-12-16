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
const double eps = 1e-6;
int n, m, q, p;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d %d %d", &n, &m, &p, &q);
        int qi = q / m;
        if(qi >= p)
        {
            printf("%d\n", (int)n*p);
            continue;
        }
        int k = n / m, t = n % m;
        int s1 = q * k;
        int s2 = min(q, t*p);
        printf("%d\n", s1+s2);
    }
    return 0;
}
