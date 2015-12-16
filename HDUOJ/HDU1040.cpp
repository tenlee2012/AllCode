#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int MAXN = 1e5 + 10;
int n;
char str[MAXN];
int num[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
        }
        sort(num, num+n);
        for(int i = 0; i < n-1; i++)
        {
            printf("%d ", num[i]);
        }
        printf("%d\n", num[n-1]);
    }
    return 0;
}