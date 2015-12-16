#include <bits/stdc++.h>

int main()
{
    int n, a, b, c;
    double x;
    while(~scanf("%d", &n))
    {
        if(n == 0) break;
        a = b = c = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%lf", &x);
            if(x > 0) c++;
            else if(x == 0) b++;
            else a++;
        }
        printf("%d %d %d\n", a, b, c);
    }
    return 0;
}
