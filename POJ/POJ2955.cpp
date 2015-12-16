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
const int maxn = 1e2+5;

char str[maxn], sk[maxn];

int main()
{
    int len, high, low, ans = 0, f;
    while(~scanf("%s", str))
    {
        if(!strcmp(str, "end")) break;
        len = strlen(str);
        high = 0; low = 0; ans = 0;
        f = 0;
        for(int i = 0; i < len; i++)
        {
            if(str[i] == '(' || str[i] == '[')
            {
                puts("0");
                sk[++high] = str[i];
            }
            else if(str[i] == ')')
            {
                while(sk[high] != '(' && high > 0)
                {
                    high--;
                }
                printf("high = %d\n", high);
                if(!high) f = 1;
                else
                {
                    ans += 2;
                    high--;   
                }
            }
            else if(str[i] == ']')
            {
                while(sk[high] != '[' && high > 0)
                {
                    high--;
                }
                printf("high = %d\n", high);
                if(!high) f = 1;
                else
                {
                    ans += 2;
                    high--;   
                }
            }
        }
        printf("high = %d\n", high);
        if(high || f)
            printf("%d\n", 0);
        else printf("%d\n", ans);
    }
    return 0;
}

