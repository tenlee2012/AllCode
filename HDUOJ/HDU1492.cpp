#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    long long n;
    int a[4] = {2, 3, 5, 7}, b[4];
    while(~scanf("%lld", &n) && n > 0)
    {
        b[0] = b[1] = b[2] = b[3] = 1;
        int i = 0;
        while(n != 1)
        {
            if(n % a[i] == 0)
            {
                n = n / a[i];
                b[i]++;
                //printf("%d * ", a[i]);
                i = 0;
            }
            else
                i++;
        }
        int ans = 0, x = 1, t = 0;
        for(int i = 0; i < 4; i++)
        {
            if(b[i])
            {
                x *= b[i];
                t++;
            }
        }
        if(t > 1)
            ans += x;
        cout << ans << endl;
    }
    return 0;
}
