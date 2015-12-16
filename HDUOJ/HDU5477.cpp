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
const int maxn = 1e5+5;
int n, A, B, L;
int ha[maxn];

int main()
{
    int T, x, y;
    scanf("%d", &T);
    for(int tt = 1; tt <= T; tt++)
    {
        scanf("%d %d %d %d", &n, &A, &B, &L);
        clc(ha, 0);
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &x, &y);
            ha[x] = max(ha[x], y);
        }
        int init = 0, sum = 0, tmp = 0;
        for(int i = 0; i < L; i++)
        {
            if(ha[i])
            {
                tmp = 0;
                tmp = (ha[i] - i) *A;
                i = ha[i] - 1;
                //printf("tmp = %d %d\n", tmp, sum);
                if(sum < tmp)
                {
                    init += tmp - sum;
                    sum = 0;
                }
                else
                {
                    sum -= tmp;
                }
            }
            else
            {
                sum += B;
            }
            //printf("%d %d\n", tmp, sum);
        }
        printf("Case #%d: ", tt);
        printf("%d\n", init);
    }
    return 0;
}
