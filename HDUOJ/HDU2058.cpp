#include<stdio.h>
#include<math.h>
int dd[100],bb[100];
int main()
{
        int n,m;
        int b,d;
        while(~scanf("%d %d",&n,&m) && (n||m))
        {
            int i = 0,k = 0;
                for(d=0;d*d<=2*m;d++)
                {

                        b = (2*m - d*d -d)/(2*d+2);
                        //printf("1////d = %d,,b = %d,b+d = %d\n",d,b,b+d);
                        if(d*d+2*b*d+2*b+d == 2*m && b>0)
                        {
                            dd[k] = d; bb[k] = b ;k++;
                           // printf("[%d,%d]\n",b,b+d);
                           // printf("2   d = %d,b = %d,b+d = %d\n",d,b,b+d);
                        }
                }
                for(i=k-1;i>=0;i--)
                {
                    printf("[%d,%d]\n",bb[i],bb[i]+dd[i]);
                }
                printf("\n");
        }
        return 0;
}
