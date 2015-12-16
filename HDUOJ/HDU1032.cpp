#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <iostream>

using namespace std;
const long long MAX = 1000005;

long long num[MAX];

long long slove(long long x)
{
    long long k = 1;
    while(x != 1)
    {
        k++;
        if(x % 2)
        {
            x = 3 * x + 1;
        }
        else
        {
             x = x  / 2;
        }
    }
    return k;
}
int main()
{
    for(long long i = 1; i <= 1000000; i++)
    {
        num[i] = slove(i);
    }
    int x, y, a, ans;
    long long b;
    while(~scanf("%d %d", &x, &y))
    {
        int xx = x, yy = y;
        a = 0; b = 0;
        if(x > y)
        {
            int z = x;
            x = y;
            y = z;
        }
        for(int i = x; i <= y; i++)
        {
            a = num[i];
            if(b < a)
            {
                b = a;
            }
        }
        printf("%d %d %lld\n", xx, yy, b);
    }
    return 0;
}
