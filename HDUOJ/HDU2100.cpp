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
const int maxn = 300;

char a[maxn], b[maxn], c[maxn];

void quling(char *x)
{
    int i = 0, j = 0;
    for(i = 0; x[i]; i++)
    {
        if(x[i] != 'A')
        {
            break;
        }
    }
    for(i; x[i]; i++)
    {
        x[j++] = x[i];
    }
    x[j] = '\0';
}
int main()
{
    //freopen("1.in", "r", stdin);
    int an, bn, n, i, j, k, jin;
    while(~scanf("%s %s", a, b))
    {
        quling(a); an = strlen(a);
        quling(b); bn = strlen(b);
        //puts(a); puts(b);
        j = bn - 1;
        k = 0; jin = 0;
        for(i = an-1; i >= 0; i--)
        {
            if(j < 0)
            {
                break;
            }
            char cx = a[i] + b[j] - 'A' + jin;
            //printf("##%d %c a %d %c, b %d %c\n", cx, cx, a[i], a[i], b[j], b[j]);
            if(cx > 'Z')
            {
                c[k++] = cx - 26;
                jin = 1;
            }
            else
            {
                jin = 0;
                c[k++] = cx;
            }
            //printf("@@c[%d] = %c i = %d, j = %d\n", k-1, c[k-1], i, j);
            j--;
        }
        while(i >= 0)
        {
            if(a[i] + jin > 'Z')
            {
                c[k++] = a[i] - 26 + jin;
                jin = 1;
            }
            else
            {
                c[k++] = a[i] + jin;
                jin = 0;
            }
            //printf("c[%d] = %c i = %d\n", k-1, c[k-1], i);
            i--;
        }
        while(j >= 0)
        {
            if(b[j] + jin > 'Z')
            {
                c[k++] = b[j] + jin - 26;
                jin = 1;
            }
            else
            {
                c[k++] = b[j] + jin;
                jin = 0;
            }
            j--;
        }
        if(jin == 1)
        {
            c[k++] = 'A' + 1;
        }
        c[k] = '\0';
        if(k == 0) printf("A");
        for(i = k-1; i >= 0; i--)
        {
            printf("%c", c[i]);
        }
        printf("\n");
    }
    return 0;
}
