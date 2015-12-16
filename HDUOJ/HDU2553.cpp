#include<cstdio>
int main()
{
    int a[10] = {1,0,0,2,10,4,40,92,352,724};
    int n;
    while(~scanf("%d",&n) && n!=0)
    {
        printf("%d\n",a[n-1]);
    }
}
