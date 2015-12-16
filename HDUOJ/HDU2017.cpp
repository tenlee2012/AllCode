//Author LJH
//www.cnblogs.com/tenlee
#include <stdio.h>
#include <string.h>

using namespace std;
const int maxn = 1e5+2;

int main()
{
    int n;
    char str[maxn];
    scanf("%d", &n);
    while(n--)
    {
        scanf("%s", str);
        int ans = 0;
        for(int i = 0; str[i]; i++)
        {
            if(str[i] >= '0' && str[i] <= '9')
                ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
