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

using namespace std;
int a[1005] = {0};
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int n,j,s = 0;
        scanf("%d",&n);
        for(j=0;j<n;j++)
            scanf("%d",&a[j]);
        sort(a,a+n);
        j = n - 1;
        if(n-1 == 0)
            s = a[0];
        else if(n-1 == 1)
            s = a[1];
        else if(n-1 == 2)
            s = a[0] + a[1] + a[2];
        else
        {
            while(j>0)
            {
                if(j == 0) s = s + a[0];
                else if(j == 1) s = s +a[1];
                else if(j == 2)
                    s =s + a[0] + a[1] + a[2];
                else
                {
                    if(2*a[1] - a[0] - a[j-1] < 0)
                        s = s + (2*a[1]+a[0]+a[j]);
                    else
                        s = s + (2*a[0]+a[j-1]+a[j]);
                }
                j = j - 2;
            }
        }
        printf("%d\n",s);
    }
}
