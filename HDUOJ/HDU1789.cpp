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
const int maxn = 1005;

struct Work
{
    int data, sco;
};
bool cmp(Work A, Work B)
{
    return A.sco >  B.sco;
}
int a[maxn];
int main()
{
    int n, T;
    Work work[maxn];
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &work[i].data);
        }
        for(int i = 0; i < n; i++)
            scanf("%d", &work[i].sco);

        sort(work, work+n, cmp);
        
        int ans = 0;
        memset(a, 0, sizeof(a));
        for(int i = 0; i < n; i++)
        {
            if(!a[work[i].data]) a[work[i].data] = 1;
            else
            {
                int j;
                for(j = work[i].data-1; j > 0; j--)
                {
                    if(!a[j]) break;
                }
                if(j > 0) a[j] = 1;
                else ans += work[i].sco;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
