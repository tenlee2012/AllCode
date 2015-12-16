#include<stdio.h>
int main()
{
    int a,b,c;
    while(~scanf("%d%d%d",&a,&b,&c)&&a!=0)
    {
        int k = 0,i;
        if(a<b) k = 1;
        else if(b<=c) k = 0;
        else
        {
            for(i=0;;i++)
            {
                if((b-c)*i+b >= a)
                 break;
            }
        }
        printf("%d\n",2*i+1);
    }
    return 0;
}
