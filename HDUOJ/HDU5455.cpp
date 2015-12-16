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
#define LL long long
using namespace std;

const int inf = 0x3f;
const int INF = 0x3f3f3f3f;
const int maxn = 1e6+5;
char str[maxn];
int len;

void slove()
{
    int flag = 1, pre = -1, k, ff = 0, kk;
    int nu = 0;
    if(len == 1)
    {
        if(str[0] == 'c') 
        {
            printf("-1\n");
            return;
        }
        else if(str[0] == 'f')
        {
            printf("1\n");
            return;
        }
        else
        {
            printf("-1\n");
            return;
        }
    }
    for(int i = 0; i < len; i++)
    {
        if(str[i] != 'c' && str[i] != 'f')
        {
            puts("-1");
            return;
        }
        if(str[i] == 'c')
        {
            nu++;
            flag  = 0;
            if(i == len - 1) {
                k = 0; kk = 1;
            }
            else if(i == len - 2){
                k = i+1; kk = 0;
            } 
            else{
                k = i+1; kk = i+2;
            }
            if(i >= 0)
            {
                if(str[k] == 'c' || str[kk] == 'c')
                {
                    ff = 1;
                    break;
                }
            }
        }
    }
    if(flag)
    {
        if(len % 2 == 0) printf("%d\n", len / 2);
        else printf("%d\n", len / 2 + 1);
    }
    else //存在 c  
    {
        if(len <= 2) printf("-1\n"); //有c 的情况下长度最少是3
        else if(ff)
            printf("-1\n");
        else
        {
            printf("%d\n", nu);
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    getchar();
    for(int t = 1; t <= T; t++)
    {
        gets(str);
        //printf("%s#\n", str);
        len = strlen(str);
        printf("Case #%d: ", t);
        if(len == 0) puts("0");
        else slove();
    }
    return 0;
}
