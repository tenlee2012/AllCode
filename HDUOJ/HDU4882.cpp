#include"iostream"
#include"cstdio"
#include"algorithm"
#include"cstring"
using namespace std;
const int ms=1e5+1;
struct Node
{
    int t;
    int v;
}a[ms];
bool cmp(const Node &a,const Node &b)
{
    return a.t*b.v<a.v*b.t;
}
int main()
{
    int n,i,j;
    long long ans=0,sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i].t);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i].v);
    sort(a+1,a+1+n,cmp);
    for(i=1;i<=n;i++)
    {
        sum+=a[i].t;
        ans+=sum*a[i].v;
    }
    cout<<ans<<endl;
    return 0;
}