#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int MAXN = 1e5 + 10;
int n;
char str[MAXN];
int num[MAXN];

int change(int j, int i)
{
    int ans = 0;
    for(; j <= i; j++)
    {
        ans = ans * 10 + (str[j] - '0');
    }
    return ans;
}
int main()
{
    while(~scanf("%s", str))
    {
        int i = 0, j = 0, k = 0;
        str[strlen(str)] = '5';
        str[strlen(str)+1] = '\0';
        while(str[i] == '5') i++;
        j = i;
        for(; str[i]; i++)
        {
            if(str[i] == '5')
            {
                num[k++] = change(j, i-1);
                //printf("num[%d] = %d\n", k-1, num[k-1]);
                while(str[i] == '5' && str[i]) i++;
                j = i;
            }
        }
        if(str[i] != '5' && str[i])
        {
            num[k++] = change(j, i-1);
            //printf("num[%d] = %d\n", k-1, num[k-1]);
        }
        sort(num, num+k);
        for(i = 0; i < k-1; i++)
        {
            printf("%d ", num[i]);
        }
        memset(str, '\0', sizeof(str));
        printf("%d\n", num[i]);
    }
    return 0;
}