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

using namespace std;

const int inf = 0x3f;
const int INF = 0x3f3f3f3f;

int main()
{
    double x;
    while(~scanf("%lf", &x))
    {
        printf("%.2lf\n", fabs(x));
    }
    return 0;
}
