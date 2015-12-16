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
const int maxn = 3145728+5;
char str[maxn], tar[4] = "wyh";
bool judge()
{
    int k = 0, i;
    for(i = 0; str[i+1]; i++)
    {
        //printf("%d %c\n", i, str[i]);
        if(str[i] == 'v' && str[i+1] == 'v')
        {
            //i = i + 1; //这里不能加1
            str[i] = 'w';
        }

        if(str[i] == tar[k])
        {
            k++;
        }
        //printf("i = %d\n", i);
        if(k == 3) return true;
    }
    for(; str[i]; i++)
    {
        if(str[i] == tar[k]) k++;
        if(k == 3) return true;
    }
    return false;
}
int main()
{
    int n;
    scanf("%d", &n);


    while(n--)
    {
        scanf("%s", str);
        if(judge())
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

