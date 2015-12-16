    #include <stdio.h>  
    int main()  
    {  
        int z, n, max, sum;  
        int a, b, A, B, t;  
        scanf("%d", &z);
        for(int k = 1; k <= z; k++)  
        {  
            scanf("%d",&n);  
            sum = max = -1001;  
            for(int i = 1; i <= n; i++)  
            {  
                scanf("%d", &t);  
                if(sum + t < t)  
                    sum = t , a = b = i;      //a、b记录当前连续子序列的起始、结束位置  
                else  
                    sum += t , ++b;  
                if(max < sum)  
                    max = sum , A = a , B = b;  
            }  
            printf("Case %d:\n%d %d %d\n",k, max, A, B);  
            if(k-z) puts("");  
        }  
        return 0;  
    }  