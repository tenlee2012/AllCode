//Author LJH
//www.cnblogs.com/tenlee
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#define clc(a, b) memset(a, b, sizeof(a))
using namespace std;

const int inf = 0x3f;
const int INF = 0x3f3f3f3f;
const int maxn = 1e4+5;

char str[maxn], ans[maxn];
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", str);
        int k = 1, j = 0, i;
        for(i = 0; str[i+1]; i++)
        {
            if(str[i] != str[i+1])
            {
                if(k != 1)
                {
                    str[j++] = k + '0';
                    printf("%d", k);
                }
                printf("%c", str[i]);
                k = 1;
            }
            else
            {
                k++;
            }
        }
        if(k != 1)
        {
            str[j++] = k + '0';
            printf("%d", k);
        }
        printf("%c\n", str[i]);
    }
    return 0;
}
