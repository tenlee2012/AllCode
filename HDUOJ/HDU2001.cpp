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

int main()
{
    double x, y, a, b, z;
    while(~scanf("%lf %lf %lf %lf", &x, &y, &a, &b))
    {
        z = sqrt((x-a)*(x-a) + (y-b)*(y-b));
        printf("%.2f\n", z);
    }
    return 0;
}
