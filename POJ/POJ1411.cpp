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
const int maxn = 100005;

int pri[maxn], hash[maxn], k = 0;

void findPrime()
{
    memset(hash, 0, sizeof(hash));
    hash[0] = hash[1] = 1;
    for(int i = 2; i < maxn; i++)
    {
        if(hash[i]) continue;
        pri[k++] = i;
        for(int j = 2; i * j < maxn; j++)
        {
            hash[i*j] = 1;
        }
    }
}

int main()
{
    int m, a, b;
    findPrime();
    while(scanf("%d %d %d", &m, &a, &b) && (m+a+b))
    {
        int ans = 0, x = 0, y = 0;
        for(int i = 0; i < k; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                if(pri[i] * pri[j] > m) break;
                else if(pri[j]*b >= pri[i]*a && ans < pri[i]*pri[j])
                {
                    ans = pri[i] * pri[j];
                    x = pri[j];
                    y = pri[i];
                }
            }
        }
        printf("%d %d\n", x, y);
    }
    return 0;
}
