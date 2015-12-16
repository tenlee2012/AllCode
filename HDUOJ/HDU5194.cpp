#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef long long Long;

Long p, q;
Long ansp, ansq;

Long Gcd(Long a, Long b)
{
    return b == 0 ? a : Gcd(b, a % b);
}

void Dfs(int prev, int one, int zeo, int flag)
{
    if (one > 0) Dfs(1, one-1, zeo, prev == 0 ? flag + 1 : flag);
    if (zeo > 0) Dfs(0, one, zeo-1, flag);
    if (0 == one && 0 == zeo)
    {
        ansq++;
        ansp += flag;
    }
    return;
}

int main()
{
    while (~scanf("%lld %lld", &p, &q))
    {
        //if (p < 1 || q < 1) while (true);
        ansp = ansq = 0;
        if (p > 0) Dfs(1, p-1, q, 0);
        if (q > 0) Dfs(0, p, q-1, 0);
        Long tmp = Gcd(ansp, ansq);
        printf("%lld/%lld\n", ansp / tmp, ansq / tmp);
    }
    return 0;
}
