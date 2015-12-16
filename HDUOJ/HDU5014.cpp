#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef __int64 LL;
const int maxn = 100005;
int a[maxn],ans[maxn],visit[maxn];
int get(int d)
{
    int num = 0;
    while(d)
    {
        d >>= 1;
        num++;
    }
    return num;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i = 0;i <= n;++i)
        scanf("%d",&a[i]);
        memset(visit,0,sizeof(visit));
        memset(ans,0,sizeof(ans));
        for(int i = n;i > 0;--i)
        {
            if(visit[i]) continue;
            int d = get(i);
            int temp = ((1 << d) - 1)  ^ i;
            ans[i] = temp;
            ans[temp] = i;
            visit[temp] = visit[i] = 1;
        }
        LL sum = 0;
        for(int i = 0;i <= n;++i)
        sum += (LL)(i ^ ans[i]);
        printf("%I64d\n",sum);
        for(int i = 0;i <= n;++i)
        printf(i == n? "%d\n":"%d ",ans[a[i]]);
    }
    return 0;
}