#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    scanf ("%d",&t);
    while (t--)
    {
        int i, a[6];
        for (i=0;i<6;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+6);
        if((a[5]+a[4]) > (a[3]+a[2]+a[1]))
        printf("Grandpa Shawn is the Winner!\n");
        else
        printf("What a sad story!\n");
    }
}