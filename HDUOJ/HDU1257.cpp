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

int a[maxn], b[maxn];

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }

        int ans = 0, flag;
        for(int i = n-1; i >= 0; i--)
        {
            flag = a[i];
            if(a[i] == 0) continue;
            ans++;
            for(int j = i-1; j >= 0; j--)
            {
                if(flag < a[j])
                {
                    flag = a[j]; a[j] = 0;
                }
            } 
            //printf("b[%d] = %d\n", i, b[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
