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
const int maxn = 5e6+5;
char par[maxn], son[maxn];
int next[maxn], fp[maxn], ans;
int s[maxn], si = 0;

void get_next()
{
    int len = strlen(son), i = 0, j = -1;
    next[0] = -1;
    while(i < len - 1)
    {
        if(j == -1 || son[j] == son[i])
        {
            ++j; ++i;
            if(son[j] != son[i]) next[i] = j;
            else next[i] = next[j];
        }
        else
        {
            j = next[j];
        }
    }
}

void KMP()
{
    get_next();
    si = -1;

    int plen = strlen(par), slen = strlen(son);
    int i = 0, j = 0, k = 0;
    while(i < plen)
    {
        if(j == -1 || par[i] == son[j])
        {
            fp[i] = j == -1 ? 0 : j;
            //printf("i = %d, par = %c si = %d\n", i, par[i], si+1);
            s[++si] = i;
            i++; j++;
        }
        else
        {
            j = next[j];
        }

        if(j == slen)
        {
            ans++;
            j = next[j];
            k = 0;
            while(k < slen)
            {
                //printf("%c", par[s[si]]);
                si--; k++;
            }
            //printf("\nsi = %d %c\n", si, par[s[si]]);
            if(si == -1) j = 0;
            else j = fp[s[si]] + 1;
        }
    }
    //printf("si = %d %c s[0] = %c\n", si, par[s[si]], par[s[0]]);
}

int main()
{
    while(~scanf("%s %s", son, par))
    {
        si = 0;
        ans = 0;
        clc(fp, 0);
        KMP();
        //printf("\n%d\n", ans);
        for(int i = 0; i <= si; i++)
        {
            printf("%c", par[s[i]]);
        }
        printf("\n");
    }
    return 0;
}
